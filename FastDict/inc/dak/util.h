// File: dak/util.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_UTIL_H
#define DAK_UTIL_H

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Prevent copy construction and assignments when used as a base class.

   struct no_copy
   {
   protected:
      no_copy() = default;

   private:
      no_copy(const no_copy&) = delete;
      no_copy& operator =(const no_copy&) = delete;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Prevent move construction and assignments when used as a base class.

   struct no_move
   {
   protected:
      no_move() = default;

   private:
      no_move(const no_move&&) = delete;
      no_move& operator =(const no_move&&) = delete;
   };
}

#endif /* DAK_UTIL_H */

