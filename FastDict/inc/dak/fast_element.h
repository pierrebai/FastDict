// File: dak/fast_element.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_FAST_ELEMENT_H
#define DAK_FAST_ELEMENT_H

#include <dak/element.h>
#include <dak/dict.h>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Element with fixed type that give direct access to their fixed value.
   //
   // Allows fast, optimized code.

   //////////////////////////////////////////////////////////////////////////
   //
   // Fixed-type int64 element.

   struct eint64 : element
   {
      eint64() : element(datatype::integer) {}
      eint64(int64 v) : element(datatype::integer, v) {}
      eint64(const eint64& e) : element(e.type()) { *this = e; }

      int64& value() { return _i; }
      const int64& value() const { return _i; }

      operator int64&() { return _i; }

      operator bool()    const { return _i != 0; }
      operator char()    const { return static_cast<char>(_i); }
      operator wchar_t() const { return static_cast<wchar_t>(_i); }
      operator int16()   const { return static_cast<int16>(_i); }
      operator int32()   const { return static_cast<int32>(_i); }
      operator int64()   const { return _i; }
      operator word()    const { return static_cast<word>(_i);  }
      operator dword()   const { return static_cast<dword>(_i); }
      operator qword()   const { return static_cast<qword>(_i); }
      operator float()   const { return static_cast<float>(_i); }
      operator double()  const { return static_cast<double>(_i); }

      eint64& operator =(const eint64& e) { _i = e._i; return *this; }
      eint64& operator =(bool v)   { _i = v; return *this; }
      eint64& operator =(int16 v)  { _i = v; return *this; }
      eint64& operator =(int32 v)  { _i = v; return *this; }
      eint64& operator =(int64 v)  { _i = v; return *this; }
      eint64& operator =(word v)   { _i = v; return *this; }
      eint64& operator =(dword v)  { _i = v; return *this; }
      eint64& operator =(qword v)  { _i = v; return *this; }
      eint64& operator =(float v)  { _i = static_cast<int64>(v); return *this; }
      eint64& operator =(double v) { _i = static_cast<int64>(v); return *this; }
   };

   DAK_ELEMENT_INT_OPERATORS(+, eint64);
   DAK_ELEMENT_INT_OPERATORS(-, eint64);
   DAK_ELEMENT_INT_OPERATORS(*, eint64);
   DAK_ELEMENT_INT_OPERATORS(/, eint64);
   DAK_ELEMENT_INT_OPERATORS(&, eint64);
   DAK_ELEMENT_INT_OPERATORS(|, eint64);
   DAK_ELEMENT_INT_OPERATORS(^, eint64);
   DAK_ELEMENT_INT_OPERATORS(%, eint64);
   DAK_ELEMENT_INT_OPERATORS(<<, eint64);
   DAK_ELEMENT_INT_OPERATORS(>>, eint64);

   DAK_ELEMENT_REAL_OPERATORS(+, eint64);
   DAK_ELEMENT_REAL_OPERATORS(-, eint64);
   DAK_ELEMENT_REAL_OPERATORS(*, eint64);
   DAK_ELEMENT_REAL_OPERATORS(/, eint64);


   //////////////////////////////////////////////////////////////////////////
   //
   // Fixed-type double element.

   struct edouble : element
   {
      edouble() : element(datatype::real) {}
      edouble(double v) : element(datatype::real, v) {}

      double& value() { return _r; }
      const double& value() const { return _r; }

      operator double&() { return _r; }

      operator bool()    const { return _r != 0; }
      operator char()    const { return static_cast<char>(_r); }
      operator wchar_t() const { return static_cast<wchar_t>(_r); }
      operator int16()   const { return static_cast<int16>(_r); }
      operator int32()   const { return static_cast<int32>(_r); }
      operator int64()   const { return static_cast<int64>(_r); }
      operator word()    const { return static_cast<word>(_r);  }
      operator dword()   const { return static_cast<dword>(_r); }
      operator qword()   const { return static_cast<qword>(_r); }
      operator float()   const { return static_cast<float>(_r); }
      operator double()  const { return _r; }

      edouble& operator =(const edouble& e) { _r = e._r; return *this; }
      edouble& operator =(bool v)   { _r = static_cast<double>(v); return *this; }
      edouble& operator =(int16 v)  { _r = static_cast<double>(v); return *this; }
      edouble& operator =(int32 v)  { _r = static_cast<double>(v); return *this; }
      edouble& operator =(int64 v)  { _r = static_cast<double>(v); return *this; }
      edouble& operator =(word v)   { _r = static_cast<double>(v); return *this; }
      edouble& operator =(dword v)  { _r = static_cast<double>(v); return *this; }
      edouble& operator =(qword v)  { _r = static_cast<double>(v); return *this; }
      edouble& operator =(float v)  { _r = v; return *this; }
      edouble& operator =(double v) { _r = v; return *this; }
   };

   DAK_ELEMENT_INT_OPERATORS(+, edouble);
   DAK_ELEMENT_INT_OPERATORS(-, edouble);
   DAK_ELEMENT_INT_OPERATORS(*, edouble);
   DAK_ELEMENT_INT_OPERATORS(/, edouble);
   DAK_ELEMENT_INT_OPERATORS(&, edouble);
   DAK_ELEMENT_INT_OPERATORS(|, edouble);
   DAK_ELEMENT_INT_OPERATORS(^, edouble);
   DAK_ELEMENT_INT_OPERATORS(%, edouble);
   DAK_ELEMENT_INT_OPERATORS(<<, edouble);
   DAK_ELEMENT_INT_OPERATORS(>>, edouble);

   DAK_ELEMENT_REAL_OPERATORS(+, edouble);
   DAK_ELEMENT_REAL_OPERATORS(-, edouble);
   DAK_ELEMENT_REAL_OPERATORS(*, edouble);
   DAK_ELEMENT_REAL_OPERATORS(/, edouble);


   //////////////////////////////////////////////////////////////////////////
   //
   // Fixed-type dict element.

   struct edict : element
   {
      edict() : element(datatype::dict) {}
      edict(const dict& v) : element(datatype::dict) { append(v); }
      edict(const edict& e) : element(datatype::dict) { append(*e._d); }

      dict& value() { return *_d; }
      const dict& value() const { return *_d; }
      operator dict&() { return *_d; }
      operator const dict&() const { return *_d; }

      edict& operator =(const edict& e) { append(*e._d); return *this; }

      using element::operator=;
   };

   DAK_ELEMENT_OPERATOR(+, dict, edict);


   //////////////////////////////////////////////////////////////////////////
   //
   // Fixed-type name element.

   struct ename : element
   {
      ename() : element(datatype::name) {}
      ename(const name& v) : element(datatype::name) { _n = v; }
      ename(const ename& e) : element(datatype::name) { _n = e._n; }

      name& value() { return name(_n); }
      const name& value() const { return name(_n); }
      operator name&() { return name(_n); }
      operator const name&() const { return name(_n); }

      ename& operator =(const ename& e) { _n = e._n; return *this; }

      using element::operator=;
   };


   //////////////////////////////////////////////////////////////////////////
   //
   // Fixed-type text element.

   struct etext : element
   {
      etext() : element(datatype::text) {}
      etext(const text& v) : element(datatype::text) { *this = v; }
      etext(strptr v) : element(datatype::text) { *this = v; }
      etext(const etext& e) : element(datatype::text) {*this = e._t; }

      text& value() { return *_t; }
      const text& value() const { return *_t; }
      operator const text&() const { return *_t; }
      operator strptr() const { return _t->c_str(); }

      etext& operator =(const etext& e) { element::operator=(e._t); }

      using element::operator=;
   };

   DAK_ELEMENT_TEXT_OPERATORS(+, etext);
}

#endif /* DAK_FAST_ELEMENT_H */
