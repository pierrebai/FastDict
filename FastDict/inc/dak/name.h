// File: dak/name.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_NAME_H
#define DAK_NAME_H

#include <dak/types.h>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Name. Efficient when used as key.
   //
   // You need to derive from name to create a concrete name.
   // All instances of a given concrete name are equal.

   struct name
   {
      // Invalid name constructor.
      name() : _name(nullptr) {}

      // Validity.
      bool is_valid() const { return _name != nullptr; }

      // Comparison methods.
      bool operator ==(const name & n) const { return _name == n._name; }
      bool operator !=(const name & n) const { return _name != n._name; }
      bool operator  <(const name & n) const { return as_int()  < n.as_int(); }
      bool operator <=(const name & n) const { return as_int() <= n.as_int(); }
      bool operator  >(const name & n) const { return as_int()  > n.as_int(); }
      bool operator >=(const name & n) const { return as_int() >= n.as_int(); }

      // Hashing for used in unordered maps.
      int32 hash() const { return (int32)as_int(); }

      // Textual representation of the name.
      strptr as_text() const { return _name ? _name : L"#invalid#"; }

   protected:
      // The text passed for the name by its sub-classes must be static
      // so that each address is unique.
      name(strptr n) : _name(n) {}

      intptr_t as_int() const { return reinterpret_cast<intptr_t>(_name); }

      strptr _name;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Hashes the name.

   struct name_hasher
   {
      inline int32 operator ()(const name & aName) const
      {
         return aName.hash();
      }
   };
}

#endif /* DAK_NAME_H */
