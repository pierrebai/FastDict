// File: dak/stream.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_STREAM_H
#define DAK_STREAM_H

#include <dak/types.h>

#include <iostream>

namespace dak
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Stream operations on known data types.
   //
   // By default, uses the standard output stream. Specialized for our own types.

   std::wostream& operator<< (std::wostream& o, const name&);
   std::wostream& operator<< (std::wostream& o, const element&);
   std::wostream& operator<< (std::wostream& o, const dict&);
}

#endif /* DAK_STREAM_H */
