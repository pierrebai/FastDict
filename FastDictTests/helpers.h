// File: helpers.h
//
// Dak Copyright © 2012-2019. All Rights Reserved.

#pragma once

#ifndef DAK_TESTS_HELPERS_H
#define DAK_TESTS_HELPERS_H

#include "CppUnitTest.h"

#include "dak/name.h"
#include "dak/dict.h"
#include "dak/voc.h"
#include "dak/stream.h"

namespace Microsoft { namespace VisualStudio { namespace CppUnitTestFramework
{
   template<> inline std::wstring ToString<dak::name>(const dak::name& n)
   {
      return n.as_text();
   }

   template<> inline std::wstring ToString<dak::voc::rock_n>(const dak::voc::rock_n& r)
   {
      return r.as_text();
   }

   template<> inline std::wstring ToString<dak::dict>(const dak::dict& d);

   template<> inline std::wstring ToString<dak::word>(const dak::word& i)
   {
      RETURN_WIDE_STRING(i);
   }

   template<> inline std::wstring ToString<dak::element>(const dak::element& e)
   {
      RETURN_WIDE_STRING(e);
   }

   template<> inline std::wstring ToString<dak::dict>(const dak::dict& d)
   {
      RETURN_WIDE_STRING(d);
   }

   template<> inline std::wstring ToString<dak::datatype>(const dak::datatype& d)
   {
      RETURN_WIDE_STRING(static_cast<int>(d));
   }

} } }

#endif /* DAK_TESTS_HELPERS_H */
