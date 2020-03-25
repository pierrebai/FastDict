// File: dak/types.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_TYPES_H
#define DAK_TYPES_H

#define WIN32_LEAN_AND_MEAN

#include <cstdint>
#include <string>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Basic types.
   //
   // Because we favor using signed types due to the C/C++ integer promotion
   // rules, we give unsigned types memory-related names, underlining their
   // raw-memory usage instead of numerical nature.

   typedef int8_t        int8;
   typedef int16_t       int16;
   typedef int32_t       int32;
   typedef int64_t       int64;
   typedef uint8_t       byte;
   typedef uint16_t      word;
   typedef uint32_t      dword;
   typedef uint64_t      qword;
   typedef std::wstring  text;
   typedef const wchar_t* strptr;

   // Type used as index and size of containers.
   typedef intptr_t index;

   //////////////////////////////////////////////////////////////////////////
   //
   // Forward declare some types defined elesewhere.

   struct dict;
   struct element;
   struct eint64;
   struct edouble;
   struct edict;
   struct ename;
   struct etext;
   struct name;
   struct no_copy;
   struct no_move;
}

#endif /* DAK_TYPES_H */
