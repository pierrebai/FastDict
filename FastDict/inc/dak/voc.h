// File: dak/voc.h
//
// Dak Copyright © 2019. All Rights Reserved.

#pragma once

#ifndef DAK_VOC_H
#define DAK_VOC_H

#include <dak/types.h>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Create a vocabulary of names.
   // Given as an example of how to create names.

   namespace voc
   {
      //////////////////////////////////////////////////////////////////////////
      //
      // The types of names is kept in its own namespace to avoid contaminating
      // the outer namespaces with common words.

      #define DAK_VOC_MAKE_NAME(n) struct n ## _n : dak::name { n ## _n() : name(L ## #n) {} };

      DAK_VOC_MAKE_NAME(apple);
      DAK_VOC_MAKE_NAME(array);
      DAK_VOC_MAKE_NAME(dictionary);
      DAK_VOC_MAKE_NAME(stream);
      DAK_VOC_MAKE_NAME(window);
      DAK_VOC_MAKE_NAME(person);
      DAK_VOC_MAKE_NAME(first_name);
      DAK_VOC_MAKE_NAME(last_name);
      DAK_VOC_MAKE_NAME(age);
      DAK_VOC_MAKE_NAME(sex);
      DAK_VOC_MAKE_NAME(number);
      DAK_VOC_MAKE_NAME(integer);
      DAK_VOC_MAKE_NAME(real);
      DAK_VOC_MAKE_NAME(position);
      DAK_VOC_MAKE_NAME(coordinate);
      DAK_VOC_MAKE_NAME(hello);
      DAK_VOC_MAKE_NAME(world);
      DAK_VOC_MAKE_NAME(rock);
      DAK_VOC_MAKE_NAME(sand);
      DAK_VOC_MAKE_NAME(pebble);
      DAK_VOC_MAKE_NAME(letter);
      DAK_VOC_MAKE_NAME(file);
      DAK_VOC_MAKE_NAME(last);

      #undef DAK_VOC_MAKE_NAME


      //////////////////////////////////////////////////////////////////////////
      //
      // The actual vocabulary is kept here, in a namespace to avoid conflicting
      // with other instances using the same words.

      const apple_n apple;
      const array_n array;
      const dictionary_n dictionary;
      const stream_n stream;
      const window_n window;
      const person_n person;
      const first_name_n first_name;
      const last_name_n last_name;
      const age_n age;
      const sex_n sex;
      const number_n number;
      const integer_n integer;
      const real_n real;
      const position_n position;
      const coordinate_n coordinate;
      const hello_n hello;
      const world_n world;
      const rock_n rock;
      const sand_n sand;
      const pebble_n pebble;
      const letter_n letter;
      const file_n file;
      const last_n last;


      //////////////////////////////////////////////////////////////////////////
      //
      // You can also create synonyms or translation or the names, since all
      // instances of a given name type are equivalent and equal.
      // For example here we create the french translation of dictionary.

      const dictionary_n dictionnaire;
   }
}

#endif /* DAK_VOC_H */
