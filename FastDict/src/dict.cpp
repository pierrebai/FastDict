// File: dict.cpp
//
// Dak Copyright © 2012-2018. All Rights Reserved.

#include "dak/dict.h"

namespace dak
{
   const dict dict::empty;

   dict::dict()
   {
   }

   dict::dict(const dict & d)
      : _elements(d._elements)
   {
   }

   dict& dict::operator =(const dict & d)
   {
      {
         const const_iterator end = _elements.end();
         for (const_iterator pos = _elements.begin(); pos != end;)
         {
            pos = _elements.erase(pos);
         }
      }
      {
         const const_iterator end = d.end();
         for (const_iterator pos = d.begin(); pos != end; ++pos)
         {
            (*this)[(*pos).first] = (*pos).second;
         }
      }
      return *this;
   }

   dict& dict::operator +=(const dict & d)
   {
      append(d);
      return *this;
   }

   void dict::append(const dict & d)
   {
      const const_iterator end = d.end();
      for (const_iterator pos = d.begin(); pos != end; ++pos)
      {
         (*this)[(*pos).first] = (*pos).second;
      }
   }

   bool dict::erase(const name& n)
   {
      iterator pos = _elements.find(n);
      if (pos == _elements.end())
         return false;

      _elements.erase(pos);
      return true;
   }

   bool dict::contains(const name& n) const
   {
      return 0 != _elements.count(n);
   }

   index dict::size() const
   {
      return _elements.size();
   }

   element & dict::operator [](const name& n)
   {
      return _elements [ n ];
   }

   const element & dict::operator [](const name& n) const
   {
      static element not_found;
      const_iterator pos = _elements.find(n);
      if(_elements.end() == pos)
         return not_found;
      else
         return (*pos).second;
   }

   dict::iterator dict::begin()
   {
      return _elements.begin();
   }

   dict::iterator dict::end()
   {
      return _elements.end();
   }

   dict::const_iterator dict::begin() const
   {
      return _elements.begin();
   }

   dict::const_iterator dict::end() const
   {
      return _elements.end();
   }

   bool dict::operator == (const dict& d) const
   {
      if (d.size() != size())
         return false;

      for (const auto& i : d)
         if (i.second != (*this)[i.first])
            return false;

      return true;
   }

   bool dict::operator != (const dict& d) const
   {
      return !((*this) == d);
   }
}
