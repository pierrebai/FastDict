// File: rock.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include "rock.h"

#include <iostream>

namespace dak
{
   void use_rock(rock_struct& r)
   {
      r.rock += 2;

      std::wcout << r.rock;
   }

   void use_rock(rock_dict& r)
   {
      r[voc::rock] += 2;

      std::wcout << r[voc::rock];
   }
}

