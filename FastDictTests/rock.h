// File: rock.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_ROCK_H
#define DAK_ROCK_H

#include "dak/name.h"
#include "dak/dict.h"
#include "dak/voc.h"
#include "dak/fast_element.h"

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Pure structure containing a rock integer, as a basis for comparison.

   struct rock_struct
   {
      int64 rock = 42;
   };

   // A function to use the rock to avoid that the compiler optimize away all code.
   __declspec(noinline)
   void use_rock(rock_struct&);

   //////////////////////////////////////////////////////////////////////////
   //
   // A fast-dict version that contains a rock integer.

   struct rock_dict : dict
   {
      rock_dict()
      {
         add_permanent_proxy(voc::rock, _rock);
      }

      rock_dict(const rock_dict& d)
      {
         add_permanent_proxy(voc::rock, _rock);
         *this = d;
      }

      rock_dict(const dict& d)
      {
         add_permanent_proxy(voc::rock, _rock);
         *this = d;
      }

      eint64& operator [](const voc::rock_n&)
      {
         return _rock;
      }

      const eint64& operator [](const voc::rock_n&) const
      {
         return _rock;
      }

      using dict::operator [];

   private:

      // This elements cannot be removed.
      eint64 _rock = 42;
   };

   // A function to use the rock to avoid that the compiler optimize away all code.
   __declspec(noinline)
   void use_rock(rock_dict&);
}

#endif /* DAK_ROCK_H */
