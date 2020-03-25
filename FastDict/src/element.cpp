// File: element.cpp
//
// Dak Copyright © 2012-2018. All Rights Reserved.

#include "dak/element.h"
#include "dak/dict.h"

#include <exception>
#include <wchar.h>

namespace dak
{
   const element element::empty;

   bool element::reset(datatype aType)
   {
      switch(_type)
      {
         default:
         case datatype::unknown:
         case datatype::boolean:
         case datatype::integer:
         case datatype::real:
         case datatype::name:  _n = name();         break;
         case datatype::dict:  delete _d; _d = 0;   break;
         case datatype::text:  delete _t; _t = 0; break;
      }

      _type = aType;

      switch(_type)
      {
         default:
         case datatype::unknown:
         case datatype::boolean:
         case datatype::integer:
         case datatype::real:
         case datatype::name:  _n = name();    break;
         case datatype::text:  _t = new text;  break;
         case datatype::dict:  _d = new dict;  break;
      }

      return aType == _type;
   }

   bool element::compatible(datatype aType) const
   {
      switch(_type)
      {
         default:
         case datatype::unknown:
         case datatype::real:
         case datatype::name:
         case datatype::dict:
         case datatype::text:    return _type == aType;
         case datatype::boolean:
         case datatype::integer: return datatype::boolean == aType
                                    ||  datatype::integer == aType;
      }
   }

   bool element::ensure(datatype aType)
   {
      if (compatible(aType))
         return true;

      // Try to preserve as much of the existing value as possible.
      switch (aType)
      {
         default:
         case datatype::unknown:
         case datatype::name:
         case datatype::text:
         case datatype::dict:
            return reset(aType);

         case datatype::boolean:
         {
            const bool prev = operator bool();
            if (!reset(aType))
               return false;
            _i = prev;
            return true;
         }

         case datatype::integer:
         {
            const int64 prev = operator int64();
            if (!reset(aType))
               return false;
            _i = prev;
            return true;
         }

         case datatype::real:
         {
            const double prev = operator double();
            if (!reset(aType))
               return false;
            _r = prev;
            return true;
         }
      }
   }

   bool element::verify(datatype aType)
   {
      if (compatible(aType))
         return true;

      if (_type == datatype::unknown)
         return reset(aType);

      return false;
   }

   element::element()
   : _i(0), _type(datatype::unknown)
   {
   }

   element::element(const element & anOther)
   : _i(0), _type(datatype::unknown)
   {
      *this = anOther;
   }

   element::element(const text & t)
   : _i(0), _type(datatype::unknown)
   {
      *this = t;
   }

   element::element(wchar_t c)
   : _i(c), _type(datatype::integer)
   {
   }

   element::element(char c)
   : _i(c), _type(datatype::integer)
   {
   }
   
   element::element(strptr s)
   : _i(0), _type(datatype::unknown)
   {
      *this = s;
   }

   element::element(bool b)
   : _i(b), _type(datatype::boolean)
   {
   }

   element::element(int16 i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(int32 i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(int64 i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(word i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(dword i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(qword i)
   : _i(i), _type(datatype::integer)
   {
   }

   element::element(float f)
   : _r(f), _type(datatype::real)
   {
   }

   element::element(double d)
   : _r(d), _type(datatype::real)
   {
   }

   element::element(const dict &d)
   : _i(0), _type(datatype::unknown)
   {
      *this = d;
   }

   element::element(const name & n)
   : _i(0), _type(datatype::unknown)
   {
      *this = n;
   }

   element::~element()
   {
      reset();
   }

   element& element::operator =(const element & anOther)
   {
      switch(anOther._type)
      {
         default:
         case datatype::unknown: reset(); break;
         case datatype::boolean:
         case datatype::integer: *this =  anOther._i; break;
         case datatype::name:    *this =  anOther._n; break;
         case datatype::real:    *this =  anOther._r; break;
         case datatype::dict:    *this = *anOther._d; break;
         case datatype::text:    *this = *anOther._t; break;
      }

      return *this;
   }

   element& element::operator =(const text & sometext)
   {
      return element::operator =(sometext.c_str());
   }

   element& element::operator =(char aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(wchar_t aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(strptr sometext)
   {
      if (reset(datatype::text))
         *_t = sometext ? sometext : L"";

      return *this;
   }

   element& element::operator =(bool aValue)
   {
      if (reset(datatype::boolean))
         _i = aValue;
      else if (compatible(datatype::real))
         _r = aValue;

      return *this;
   }

   element& element::operator =(int16 aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(int32 aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(int64 aValue)
   {
      if (reset(datatype::integer))
         _i = aValue;
      else if (compatible(datatype::real))
         _r = (double)aValue;

      return *this;
   }

   element& element::operator =(word aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(dword aValue)
   {
      return element::operator =((int64) aValue);
   }

   element& element::operator =(qword aValue)
   {
	   return element::operator =((int64)aValue);
   }

   element& element::operator =(float aValue)
   {
      return element::operator =((double) aValue);
   }

   element& element::operator =(double aValue)
   {
      if (reset(datatype::real))
         _r = aValue;
      else if (compatible(datatype::integer))
         _i = (int64)aValue;

      return *this;
   }

   element& element::operator =(const dict & aDict)
   {
      if (reset(datatype::dict))
         *_d = aDict;

      return *this;
   }

   element& element::operator =(const name& aValue)
   {
      if (reset(datatype::name))
         _n = aValue;

      return *this;
   }

   element::operator char() const
   {
      if (compatible(datatype::integer))
         return (char)_i;

      if (compatible(datatype::real))
         return (char)_r;

      return 0;
   }

   element::operator wchar_t() const
   {
      if (compatible(datatype::integer))
         return (wchar_t)_i;

      if (compatible(datatype::real))
         return (wchar_t)_r;

      return 0;
   }

   element::operator text() const
   {
      if (compatible(datatype::text))
         return *_t;

      return L"";
   }

   element::operator strptr() const
   {
      if (compatible(datatype::text))
         return _t->c_str();

      return L"";
   }

   element::operator word() const
   {
      if (compatible(datatype::integer))
         return (word)_i;

      if (compatible(datatype::real))
         return (word)_r;

      return 0;
   }

   element::operator dword() const
   {
      if (compatible(datatype::integer))
         return (dword)_i;

      if (compatible(datatype::real))
         return (dword)_r;

      return 0;
   }

   element::operator bool() const
   {
      switch (_type)
      {
         default:
         case datatype::unknown: return false;
         case datatype::boolean:
         case datatype::integer:  return _i != 0;
         case datatype::name:     return _n.is_valid();
         case datatype::real:     return _r != 0;
         case datatype::dict:
         case datatype::text:     return size() > 0;
      }
   }

   element::operator int16() const
   {
      if (compatible(datatype::integer))
         return (int16)_i;

      if (compatible(datatype::real))
         return (int16)_r;

      return 0;
   }

   element::operator int32() const
   {
      if (compatible(datatype::integer))
         return (int32)_i;

      if (compatible(datatype::real))
         return (int32)_r;

      return 0;
   }

   element::operator qword() const
   {
      if (compatible(datatype::integer))
         return (qword)_i;

      if (compatible(datatype::real))
         return (qword)_r;

      return 0;
   }

   element::operator int64() const
   {
      if (compatible(datatype::integer))
         return (int64)_i;

      if (compatible(datatype::real))
         return (int64)_r;

      return 0;
   }

   element::operator float() const
   {
      if (compatible(datatype::real))
         return (float)_r;

      if (compatible(datatype::integer))
         return (float)_i;

      return 0;
   }

   element::operator double() const
   {
      if (compatible(datatype::real))
         return _r;

      if (compatible(datatype::integer))
         return (double)_i;

      return 0;
   }

   element::operator const dict &() const
   {
      if (compatible(datatype::dict))
         return *_d;

      return dict::empty;
   }

   element::operator name() const
   {
      if (compatible(datatype::name))
         return _n;

      return name();
   }

   // Dict conversion + immediate dict op.
   void element::append(const dict & d)
   {
      if (!ensure(datatype::dict))
         return;

      _d->append(d);
   }

   bool element::erase(const name& n)
   {
      if (!ensure(datatype::dict))
         return false;

      return _d->erase(n);
   }

   bool element::contains(const name& n) const
   {
      if (!compatible(datatype::dict))
         return false;

      return _d->contains(n);
   }

   element & element::operator [](const name& n)
   {
      if (!ensure(datatype::dict))
         throw std::exception("bad element access on fixed element");

      return (*_d)[n];
   }

   const element & element::operator [](const name& n) const
   {
      if (!compatible(datatype::dict))
         return empty;

      return ((const dict &)*_d)[n];
   }

   index element::size() const
   {
      switch(_type)
      {
         default:
         case datatype::unknown:
         case datatype::boolean:
         case datatype::integer:
         case datatype::real:
         case datatype::name:  return 0;
         case datatype::dict:  return _d->size();
         case datatype::text:  return _t->length();
      }
   }

   datatype element::type() const
   {
      return _type;
   }

   bool element::operator == (const element& e) const
   {
      if (_type != e._type)
         return false;

      switch (_type)
      {
         default:                return false;
         case datatype::unknown: return true;
         case datatype::boolean: 
         case datatype::integer: return _i == e._i;
         case datatype::real:    return _r == e._r;
         case datatype::name:    return _n == e._n;
         case datatype::dict:    return *_d == *e._d;
         case datatype::text:    return *_t == *e._t;
      }
   }

   bool element::operator != (const element& e) const
   {
      return !((*this) == e);
   }
}

