// File: dak/element.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_ELEMENT_H
#define DAK_ELEMENT_H

#include <dak/types.h>
#include <dak/name.h>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Types that can be kept in an element.

   enum class datatype : byte
   {
      unknown, boolean, integer, name, real, dict, text
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Element in dictionaries. Can represent all data
   // types. Simple ones are inlined, other allocated on the heap.
   //
   // All types are always copied when assigned to, so beware of assigning
   // dictionaries!
   //
   // When implicitely converted to a type, the element type is not changed.
   // The value is converted to the closest corresponding value.
   //
   // (All integer-like types are equivalent, so you can read a boolean
   // from an integer. Same for double-like types, float and double.)
   //
   // Also, when converted to a type via the ensure() or reset() functions,
   // if the element was not of that type, it is changed into it. So beware
   // of changing a dict into an integer, as the dict content is lost!
   //
   // To support access to elements containg dict, the element
   // provides the [] operator to access the sub-elements of the container.
   // Again, the element will be automatically converted, so if it was not
   // an array of a dict, its previous content will be lost.

   struct element
   {
      // Create an element of an unfixed type, potentially pre-initialized to a value.
      element();

      // Copy the given element.
      element(const element &);

      element(const text &);
      element(wchar_t);
      element(char);
      element(strptr);
      element(bool);
      element(int16);
      element(int32);
      element(int64);
      element(word);
      element(dword);
      element(qword);
      element(float);
      element(double);
      element(const dict &);
      element(const name &);
      ~element();

      static const element empty;

      // Assignments. Changes the type if needed.
      element& operator =(const element &);

      // Assignments of various types. Changes the type if needed.
      element& operator =(const text &);
      element& operator =(wchar_t);
      element& operator =(char);
      element& operator =(strptr);
      element& operator =(bool);
      element& operator =(int16);
      element& operator =(int32);
      element& operator =(int64);
      element& operator =(word);
      element& operator =(dword);
      element& operator =(qword);
      element& operator =(float);
      element& operator =(double);
      element& operator =(const dict &);
      element& operator =(const name &);

      // Data access. Does not change the type.
      operator char() const;
      operator wchar_t() const;
      operator text() const;
      operator strptr() const;
      operator bool() const;
      operator int16() const;
      operator int32() const;
      operator int64() const;
      operator word() const;
      operator dword() const;
      operator qword() const;
      operator float() const;
      operator double() const;
      operator const dict &() const;
      operator name() const;

      // Dict conversion + immediate dict op.
      void append(const dict &);
      bool erase(const name &);
      bool contains(const name &) const;
      element & operator [](const name &);
      const element & operator [](const name &) const;

      // Dict and text return the length, others return zero.
      index size() const;

      // Current type of data contained in the element.
      datatype type() const;

      // All integer-like types are equivalent, so you can read a boolean
      // from an integer. Same for double-like types, float and double.
      bool compatible(datatype aType) const;

      // Clear the old data and set the type. Clear even if same type.
      // Returns true if the type was successfully set.
      bool reset(datatype = datatype::unknown);

      // Reset if currently not the requested type.
      // Tries to preserve as much of the old value as possible.
      // Returns true if the type was successfully set.
      bool ensure(datatype);

      // Verify if it has the requested type or unknown, in which case set the type.
      // Returns true if the type was already correct or successfully set.
      // Returns false if the type was different.
      bool verify(datatype);

      // Comparison.
      bool operator == (const element&) const;
      bool operator != (const element&) const;

   protected:
      union
      {
         int64          _i;
         double         _r;
         dict *         _d;
         element *      _e;
         const element* _ce;
         text *         _t;
         name           _n;
      };
      datatype _type = datatype::unknown;

      friend struct dict;
   };


   //////////////////////////////////////////////////////////////////////////
   //
   // Conversion operators.

   // This defines the operator x= for the type t.
   // For example, it defines += for int32.
   // It does so by extracting the value t from the element, then applying
   // the operator, then assigning the value back to the element.

   #define DAK_ELEMENT_OPERATOR(x, t, e) inline e& operator x=(e& a, const t& b) { t c = const_cast<const e&>(a); c x= b; a = c; return a; }

   // This defines the x= operator for integer-like types.

   #define DAK_ELEMENT_INT_OPERATORS(x, e) \
      DAK_ELEMENT_OPERATOR(x, wchar_t, e)  \
      DAK_ELEMENT_OPERATOR(x, char, e)     \
      DAK_ELEMENT_OPERATOR(x, int16, e)    \
      DAK_ELEMENT_OPERATOR(x, int32, e)    \
      DAK_ELEMENT_OPERATOR(x, int64, e)    \
      DAK_ELEMENT_OPERATOR(x, word, e)     \
      DAK_ELEMENT_OPERATOR(x, dword, e)    \
      DAK_ELEMENT_OPERATOR(x, qword, e)    \

   // This defines the x= operator for floating-point-like types.

  #define DAK_ELEMENT_REAL_OPERATORS(x, e) \
      DAK_ELEMENT_OPERATOR(x, float, e)    \
      DAK_ELEMENT_OPERATOR(x, double, e)   \

   // This defines the x= operator for container types.

  #define DAK_ELEMENT_CONTAINER_OPERATORS(x, e) \
      DAK_ELEMENT_OPERATOR(x, dict, e)

   // This defines the x= operator for the text type.

   #define DAK_ELEMENT_TEXT_OPERATORS(x, e) \
         DAK_ELEMENT_OPERATOR(x, text, e) \
         inline e& operator += (e& a, strptr b) { text c = const_cast<const e&>(a); c x= b; a = c; return a; }

   // Define the desired operators for each type.

   DAK_ELEMENT_INT_OPERATORS(+, element);
   DAK_ELEMENT_INT_OPERATORS(-, element);
   DAK_ELEMENT_INT_OPERATORS(*, element);
   DAK_ELEMENT_INT_OPERATORS(/, element);
   DAK_ELEMENT_INT_OPERATORS(&, element);
   DAK_ELEMENT_INT_OPERATORS(|, element);
   DAK_ELEMENT_INT_OPERATORS(^, element);
   DAK_ELEMENT_INT_OPERATORS(%, element);
   DAK_ELEMENT_INT_OPERATORS(<<, element);
   DAK_ELEMENT_INT_OPERATORS(>>, element);

   DAK_ELEMENT_REAL_OPERATORS(+, element);
   DAK_ELEMENT_REAL_OPERATORS(-, element);
   DAK_ELEMENT_REAL_OPERATORS(*, element);
   DAK_ELEMENT_REAL_OPERATORS(/, element);

   DAK_ELEMENT_TEXT_OPERATORS(+, element);
}

#endif /* DAK_ELEMENT_H */
