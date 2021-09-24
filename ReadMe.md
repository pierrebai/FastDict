# **Golfing with Dict**

Code golf is usually all about how short the code can be. This code golf will be a bit different: it will be about code size, speed and efficiency. The question we will explore is:

***How fast can a dictionary access be?***

Yes, it’s a bit weird as code golf go, but bear with me. You’ll see we’ll get somewhere with this. Not necessarily somewhere you were planning to go... but we’ll get there, together, as a team! Nah, just kidding. No teamwork required. I’ll do all the work and you can just sit back and watch me.

All the code we will discuss is available on GitHub at this address:

<https://github.com/pierrebai/FastDict>

(Note that there are multiple branches, “master” for the starting point, “fast-dict” for the final result.)

## **The Rules**

As you’ll see, by the end of this, the laws of the universe will get bent. But that doesn’t mean we can’t make up our own laws. That’s why I’ll be putting down rules, the basic shape of what the dictionary must look like and the functionality it will provide.

I’ll start be outlining the high-level description of the functionality and afterward provide a short C++ declaration of what the interface will look like. For a full view of the C++ API, refer to the “master” branch on GitHub. Now, to the description!

### **High-level Description**

|**C++ Class**|**Purpose**|**API**|
| :-: | :-: | :-: |
|element|The dictionary item. Contains a value of any type. For example: an integer, a double, some text, or another dictionary.|Setting values, reading the value, resetting the element, comparing elements, etc.|
|name|A label-like type used to access elements in the dictionary.|Constructing new names, comparing names.|
|dict|The dictionary, indexed by names, holding elements.|Construction, copying, merging, adding, removing and accessing its elements, iterating over its elements.|
### **C++ Code**
I will only give the shortest of description. You can look at the code on GitHub. The main point that interests us is the dictionary access, so that is all I’ll show right now:

```C++
// Element retrieval.
element & operator [](const name &);
const element & operator [](const name &) const;
```

Very simple, very standard. The look-up function receives a name and return an element. To help understand what are names, let’s see how they are created:

```C++
// You need to derive from name to create a concrete name.
// All instances of a given concrete name are equal.

struct name
{
    // Invalid-name, default constructor.
    name() : _name(nullptr) {}
protected:
    // The text passed for the name by its sub-classes must be static
    // so that each address is unique.
    name(strptr n) : _name(n) {}
};
```

While name has a public default constructor, its other constructor is protected. Why protected? You will see the deep reason later on… Does that mean all instances have to be from sub-classes? Yes! Every name will be an instance of a sub-class of name! But which sub-class? Gee... **all of them**, of course!

In fact, if you look in the GitHub repo, you will see that I handily provide a voc.h header. This headers declares… a vocabulary of names. As was hinted in the name class declaration, each actual name is a sub-class… a different sub-class for each distinct name! The file goes a bit like this:

```C++
namespace voc
{
    #define MAKE_NAME(n) struct n ## _n : dak::name { n ## _n() : name(L ## #n) {} };
    MAKE_NAME(apple);
    MAKE_NAME(person);
    // etc…
    const apple_n apple;
    const person_n person;
}
```

The element class itself is a simple class that can hold a value of any common types. There is nothing special about it.

Now would be a good time for you to think just how fast you could make such a dictionary interface. You can look at the “master” branch on GitHub as the starting point. Will it be N log N? N?, log N? Constant time? Faster? Wait, faster than constant time? What would that even mean?

## **The Bends**

Now that we’ve established, the rules, it’s time to bend them to our advantage. Of course, like any good trickster, the rules were carefully thought out to give the house the edge.

In particular, there is a good reason why the name class is designed as it is. You see, having different types for different names means that we can subvert the C++ type system to our advantage. In particular… we can subvert the function overloading mechanism!

Remember the element access functions? What would happen if they were overloaded like this:

```C++
// Element retrieval.
element & operator [](const name &);
const element & operator [](const name &) const;

// Overload!!!
inline element& operator [](const voc::rock_n&)
inline const element& operator [](const voc::rock_n&) const
```

This means we can return the element without having to look it up! Complete cheating! But how could the element be found if the voc::rock is accessed through the version taking a simple name and not a voc::rock? How could the dict elements be iterated over during normal iteration? Easy! We create proxy elements in the normal dictionary map, each proxy defers all its behavior to the direct-access copy. Basically, we add a few functions to the element class, to record if it is a proxy. We also add a function to the dict class to record each proxy element and the direct-access element they refer to.

```C++
struct dict
{
protected:
    std::map<name, element> _elements;
    // Sub-classes call this during construction
    // to add the permanent proxy elements.
    void add_permanent\proxy(const name& n, element &);
};

struct element
{
    bool is_proxy() const;
    bool is_permanent() const;
};
```

The result of this is that we can access the elements of our choice at compile-time! You simply sub-class the dict class and add the proxy elements that will be accessible under the names of your choice. The resulting class acts just like a dict, and can be used everywhere a dict can be, but if you know the true type of the dict and the true name you want to access, you get compile-time access thanks to function inlining and overloading.

## **The Twist**

Us in the madness business would not be satisfied by such mediocre trickery. This subversion is not going far enough. We want more speed! We have compile-time access to our element, but we want compile-time access to the **value** contained in the element. Is that even possible? Why, yes, it is!

The sleigh-of-hand we will be using is sub-classing the element class, where the value resides. If we know in advance the type of the value we want to keep under a name, we can force it to always have that type, a be known at compile-time. Knowing the type of the value we want to keep under a specific name is not unusual, it is even typical! That’s how we design types, schema and databases after all.

So here is a typical example of such sub-classing. (See the “fast-dict” branch on GitHub for all the variation provided.)

```C++
struct eint64 : element
{
    operator int64&() { return _i; }
    // etc...
};
```

As we can see, it can inline the access to the true value contained in the element. Now our dict sub-class can return such an eint64 in its overloaded element-access function, and offer full compile-time access to the direct value! Like this:

```C++
    inline eint64& operator [](const voc::rock\_n&) { return _rock; }

    inline const eint64& operator [](const voc::rock_n&) const { return _rock; }
```

To support the element sub-classes, an additional function is added to element to let it know that the value type is now fixed:

```C++
    bool is_fixed() const { return _fixed == fixedtype::fixed; }
```

## **The Proof**

But I do not merely claim that it is compile-time access, I prove it! Not merely prove it, but compare it to pure structure access. That’s right! While the dictionary sub-class with its overloaded functions can be used just like a normal dict, and all its elements, including the permanent, proxied, typed ones can be found by normal look-up or by iteration, it is just as fast as a **raw struct**! Just as fast as this:

```C++
struct rock_struct
{
    int64 rock = 42;
};

d1.rock = rand();
    call        qword ptr [rand]  
    movsxd      rcx,eax  
    mov         qword ptr [rsp+38h],rcx  
use_rock(d1);
    lea         rcx,[d1]  
    call        dak::use_rock
std::wcout << d1.rock;
    mov         rbx,qword ptr [d1]  
    mov         rcx,qword ptr [std::wcout]  
    mov         rdx,rbx  
    call        qword ptr [operator<<]  
d1.rock += rand();
    call        qword ptr [rand]  
    movsxd      rcx,eax  
    add         rbx,rcx  
use_rock(d1);
    lea         rcx,[d1]  
    mov         qword ptr [d1],rbx  
    call        dak::use_rock
std::wcout << d1.rock;
    mov         rdx,qword ptr [d1]  
    mov         rcx,qword ptr [std::wcout]  
    call        qword ptr [operator<<]  
use_rock(d1);
    lea         rcx,[d1]  
    call        dak::use_rock
d1[voc::rock] = rand();
    call        qword ptr [rand]  
    movsxd      rcx,eax  
    mov         qword ptr [rsp+38h],rcx  
use_rock(d1);
    lea         rcx,[d1]  
    call        dak::use_rock
std::wcout << d1[voc::rock];
    lea         rdx,[rsp+38h]  
    mov         rcx,qword ptr [std::wcout]  
    call        dak::operator<<
d1[voc::rock] += rand();
    call        qword ptr [rand]  
    add         eax,dword ptr [rsp+38h]  
    movsxd      rcx,eax
    mov         qword ptr [rsp+38h],rcx  
use_rock(d1);
    lea         rcx,[d1]  
    call        dak::use_rock
std::wcout << d1[voc::rock];
    lea         rdx,[rsp+38h]  
    mov         rcx,qword ptr [std::wcout]  
    call        dak::operator<<
use_rock(d1);
    lea         rcx,[d1]  
    call        dak::use_rock
```
In the “fast-dict” branch, there are unit-tests, and among them two dummy ones that were used solely Vto compare the code generation of the sub-dict and the structure. I captured the disassembly of both, and here what you can see: as we claimed, each is just as fast as the other!

## **Conclusion**

We set out to the golf course, setting our sight on the dictionary access and trying to see how low we could make the par for the course. And lo and behold!, how low we went!

But I feel you tensed, confused and crossed.

This is a parody of design, an abomination! Deriving from a dict class? Would you derive from a `std::vector`, a `std::map`, a `std::pair`? What kind of respectable programmer would ever do that? And I’d agree! (Wait, what? Who said that?) No, no, no, no, I would really agree! I would, I would, I would, except…

… you see everything in life is a question of perspective. Of how we perceive the world. And in the case of programming, perception is all about naming. Naming types, naming functions, naming variables. What’s in a name? Names shape our vision of the world, and in this much less grander scale, our designs. So… what if I told you dict is not the real name of the class? What would happen if we renamed it it… object?

Ah, the final illumination! Yes, now it makes sense to derive from object. Now it makes sense that we would add fixed permanent elements to an object to hold values of fixed type! It’s no longer even a surprising design. It’s basically how a language like Python works under the hood. In Python, every object of every class is really just a dictionary of values indexed by names. It’s just that now you can do it directly in C++.

It’s also very useful. You no longer need to write and rewrite boiler-plate code for every struct and class. You can have a single implementation for all types for things like serialization, undo/redo, data lookup, hooking-up to UI elements, and various other activities I’m sure you can come with. You write it once for the ~~dict~~ object class. Every sub-class inherits the implementation of object and all data is always accessible via simple iteration over elements or name lookup.

Ain’t that something? So, did we get somewhere worth seeing or not?
