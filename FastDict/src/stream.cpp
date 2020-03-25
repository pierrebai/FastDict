// File: stream.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include "dak/stream.h"
#include "dak/types.h"
#include "dak/dict.h"

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Stream operations.

   std::wostream& operator <<(std::wostream& o, const name& n)
   {
      return o << n.as_text();
   }

   std::wostream& operator <<(std::wostream& o, const element& e)
   {
      switch(e.type())
      {
         case datatype::unknown:  return o << L"unknown";
         case datatype::boolean:  return o << (bool) e;
         case datatype::integer:  return o << (int64) e;
         case datatype::name:     return o << (const name &) e;
         case datatype::real:     return o << (double) e;
         case datatype::dict:     return o << (const dict &) e;
         case datatype::text:     return o << (strptr) e;
         default:                 return o;
      }
   }

   std::wostream& operator <<(std::wostream& o, const dict& d)
   {
      o << L"{ ";
      const dict::const_iterator e = d.end();
      for (dict::const_iterator i = d.begin(); i != e; ++i) {
         o << i->first << L" : " <<  i->second << L" , ";
      }
      o << L"}";
      return o;
   }
}
