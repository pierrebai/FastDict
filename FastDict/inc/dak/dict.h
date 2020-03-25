// File: dak/dict.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_DICT_H
#define DAK_DICT_H

#include <dak/types.h>
#include <dak/element.h>

#include <map>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Dictionary. Lookup data when given a name.
   //
   // Automatically adds elements when referenced via the [] operator.

   struct dict
   {
      // Types used by the dictionary: data container and iterators.
      typedef std::map<name, element> elements;
      typedef elements::iterator iterator;
      typedef elements::const_iterator const_iterator;

      // Constructors.
      dict();
      dict(const dict &);

      // Assignment. Copy the whole dictionary.
      dict& operator =(const dict &);

      // Append the given dictionary.
      dict& operator +=(const dict &);

      // Empty dictionary.
      static const dict empty;

      // Number of elements in the dictionary.
      index size() const;

      // Modifications to the dictionary.
      void append(const dict &);
      bool erase(const name &);
      bool contains(const name &) const;

      // Element retrieval.
      element & operator [](const name &);
      const element & operator [](const name &) const;

      // Iterations over the elements.
      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

      // Comparisons.
      bool operator == (const dict&) const;
      bool operator != (const dict&) const;

   protected:
      elements _elements;
   };

   DAK_ELEMENT_OPERATOR(+, dict, element);
}

#endif /* DAK_DICT_H */
