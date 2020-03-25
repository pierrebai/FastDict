#include "CppUnitTest.h"

#include "dak/fast_element.h"
#include "helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak;

namespace tests
{
   TEST_CLASS(fast_element_tests)
	{
	public:
		TEST_METHOD(fast_element_int64)
		{
         eint64 e;

         Assert::AreEqual<element>(eint64(), e);
         Assert::AreNotEqual<element>(element(), e);
         Assert::AreNotEqual(eint64(1), e);

         Assert::IsTrue( e == eint64());
         Assert::IsFalse(e == element());
         Assert::IsFalse(e != eint64());

         Assert::IsFalse(e == eint64(1));
         Assert::IsFalse(eint64::empty == eint64(1));
         Assert::IsTrue(e != eint64(1));

         Assert::IsFalse(e.reset(datatype::unknown));
         Assert::IsFalse(e.reset(datatype::real));
         Assert::IsFalse(e.reset(datatype::name));
         Assert::IsFalse(e.reset(datatype::dict));
         Assert::IsFalse(e.reset(datatype::boolean));
         Assert::IsFalse(e.reset(datatype::text));

         Assert::IsTrue(e.reset(datatype::integer));

         Assert::IsFalse(e.compatible(datatype::unknown));
         Assert::IsFalse(e.compatible(datatype::real));
         Assert::IsFalse(e.compatible(datatype::name));
         Assert::IsFalse(e.compatible(datatype::dict));
         Assert::IsFalse(e.compatible(datatype::text));

         Assert::IsTrue(e.compatible(datatype::boolean));
         Assert::IsTrue(e.compatible(datatype::integer));
      }

      TEST_METHOD(fast_element_int64_conversion)
      {
         eint64 e;
         Assert::AreEqual<int64>(0, e);

         e = 33;
         Assert::AreEqual<int64>(33, e.value());

         Assert::AreEqual<int64 >(33,   static_cast<int64&>(e));
         Assert::AreEqual<bool  >(true, static_cast<bool  >(e));
         Assert::AreEqual<int16 >(33,   static_cast<int16 >(e));
         Assert::AreEqual<int32 >(33,   static_cast<int32 >(e));
         Assert::AreEqual<int64 >(33,   static_cast<int64 >(e));
         Assert::AreEqual<word  >(33,   static_cast<word  >(e));
         Assert::AreEqual<dword >(33,   static_cast<dword >(e));
         Assert::AreEqual<qword >(33,   static_cast<qword >(e));
         Assert::AreEqual<float >(33.f, static_cast<float >(e));
         Assert::AreEqual<double>(33.,  static_cast<double>(e));
      }

      TEST_METHOD(fast_element_int64_operators)
		{
         eint64 e;

         Assert::AreEqual<int64>(0, e);

         e += 2;
         Assert::AreEqual<int64>(2, e);

         e -= 7;
         Assert::AreEqual<int64>(-5, e);

         e *= 3;
         Assert::AreEqual<int64>(-15, e);

         e /= -5;
         Assert::AreEqual<int64>(3, e);

         e &= 1;
         Assert::AreEqual<int64>(1, e);

         e |= 10;
         Assert::AreEqual<int64>(11, e);

         e ^= 8;
         Assert::AreEqual<int64>(3, e);

         e <<= 2;
         Assert::AreEqual<int64>(12, e);

         e >>= 1;
         Assert::AreEqual<int64>(6, e);

         e += 2.5;
         Assert::AreEqual<int64>(8, e);

         e -= 0.99;
         Assert::AreEqual<int64>(7, e);

         e *= 0.5;
         Assert::AreEqual<int64>(3, e);

         e /= 2.1;
         Assert::AreEqual<int64>(1, e);
      }

      TEST_METHOD(fast_element_double)
      {
         edouble e;

         Assert::AreEqual(edouble(), e);
         Assert::AreNotEqual<element>(element(), e);
         Assert::AreNotEqual(edouble(1), e);

         Assert::IsTrue(e == edouble());
         Assert::IsFalse(e == element());
         Assert::IsFalse(e != edouble());

         Assert::IsFalse(e == edouble(1));
         Assert::IsFalse(edouble::empty == edouble(1));
         Assert::IsTrue(e != edouble(1));

         Assert::IsFalse(e.reset(datatype::unknown));
         Assert::IsFalse(e.reset(datatype::integer));
         Assert::IsFalse(e.reset(datatype::name));
         Assert::IsFalse(e.reset(datatype::dict));
         Assert::IsFalse(e.reset(datatype::boolean));
         Assert::IsFalse(e.reset(datatype::text));

         Assert::IsTrue(e.reset(datatype::real));

         Assert::IsFalse(e.compatible(datatype::unknown));
         Assert::IsFalse(e.compatible(datatype::integer));
         Assert::IsFalse(e.compatible(datatype::boolean));
         Assert::IsFalse(e.compatible(datatype::name));
         Assert::IsFalse(e.compatible(datatype::dict));
         Assert::IsFalse(e.compatible(datatype::text));

         Assert::IsTrue(e.compatible(datatype::real));
      }

      TEST_METHOD(fast_element_double_conversion)
      {
         edouble e;
         Assert::AreEqual<double>(0.0, e);

         e = 33.0;
         Assert::AreEqual<double>(33.0, e.value());

         Assert::AreEqual<double>(33, static_cast<double&>(e));
         Assert::AreEqual<bool  >(true, static_cast<bool>(e));
         Assert::AreEqual<int16 >(33, static_cast<int16>(e));
         Assert::AreEqual<int32 >(33, static_cast<int32>(e));
         Assert::AreEqual<int64 >(33, static_cast<int64>(e));
         Assert::AreEqual<word  >(33, static_cast<word>(e));
         Assert::AreEqual<dword >(33, static_cast<dword>(e));
         Assert::AreEqual<qword >(33, static_cast<qword>(e));
         Assert::AreEqual<float >(33.f, static_cast<float>(e));
         Assert::AreEqual<double>(33., static_cast<double>(e));
      }

      TEST_METHOD(fast_element_double_operators)
      {
         edouble e;

         Assert::AreEqual<double>(0, e);

         e += 2;
         Assert::AreEqual<double>(2, e);

         e -= 7;
         Assert::AreEqual<double>(-5, e);

         e *= 3;
         Assert::AreEqual<double>(-15, e);

         e /= -5;
         Assert::AreEqual<double>(3, e);

         e &= 1;
         Assert::AreEqual<double>(1, e);

         e |= 10;
         Assert::AreEqual<double>(11, e);

         e ^= 8;
         Assert::AreEqual<double>(3, e);

         e <<= 2;
         Assert::AreEqual<double>(12, e);

         e >>= 1;
         Assert::AreEqual<double>(6, e);

         e += 2.5;
         Assert::AreEqual<double>(8.5, e);

         e -= 0.99;
         Assert::AreEqual<double>(7.51, e);

         e *= 0.5;
         Assert::AreEqual<double>(3.755, e);

         e /= 2.1;
         Assert::AreEqual<double>(3.755/2.1, e);
      }

      TEST_METHOD(fast_element_dict)
      {
         dict d;
         d[voc::apple] = 3;

         edict e;

         Assert::AreEqual(edict(), e);
         Assert::AreNotEqual<element>(element(), e);
         Assert::AreNotEqual(edict(d), e);

         Assert::IsTrue(e == edict());
         Assert::IsFalse(e == element());
         Assert::IsFalse(e != edict());

         Assert::IsFalse(e == edict(d));
         Assert::IsFalse(edict::empty == edict(d));
         Assert::IsTrue(e != edict(d));

         Assert::IsFalse(e.reset(datatype::unknown));
         Assert::IsFalse(e.reset(datatype::integer));
         Assert::IsFalse(e.reset(datatype::name));
         Assert::IsFalse(e.reset(datatype::real));
         Assert::IsFalse(e.reset(datatype::boolean));
         Assert::IsFalse(e.reset(datatype::text));

         Assert::IsTrue(e.reset(datatype::dict));

         Assert::IsFalse(e.compatible(datatype::unknown));
         Assert::IsFalse(e.compatible(datatype::integer));
         Assert::IsFalse(e.compatible(datatype::boolean));
         Assert::IsFalse(e.compatible(datatype::name));
         Assert::IsFalse(e.compatible(datatype::real));
         Assert::IsFalse(e.compatible(datatype::text));

         Assert::IsTrue(e.compatible(datatype::dict));
      }

      TEST_METHOD(fast_element_name)
      {
         ename e;

         Assert::AreEqual(ename(), e);
         Assert::AreNotEqual<element>(element(), e);
         Assert::AreNotEqual(ename(voc::apple), e);

         Assert::IsTrue(e == ename());
         Assert::IsFalse(e == element());
         Assert::IsFalse(e != ename());

         Assert::IsFalse(e == ename(voc::pebble));
         Assert::IsFalse(ename::empty == ename(voc::pebble));
         Assert::IsTrue(e != ename(voc::pebble));

         Assert::IsFalse(e.reset(datatype::unknown));
         Assert::IsFalse(e.reset(datatype::integer));
         Assert::IsFalse(e.reset(datatype::real));
         Assert::IsFalse(e.reset(datatype::dict));
         Assert::IsFalse(e.reset(datatype::boolean));
         Assert::IsFalse(e.reset(datatype::text));

         Assert::IsTrue(e.reset(datatype::name));

         Assert::IsFalse(e.compatible(datatype::unknown));
         Assert::IsFalse(e.compatible(datatype::integer));
         Assert::IsFalse(e.compatible(datatype::boolean));
         Assert::IsFalse(e.compatible(datatype::real));
         Assert::IsFalse(e.compatible(datatype::dict));
         Assert::IsFalse(e.compatible(datatype::text));

         Assert::IsTrue(e.compatible(datatype::name));
      }

      TEST_METHOD(fast_element_text)
      {
         etext e;

         Assert::AreEqual(etext(), e);
         Assert::AreNotEqual<element>(element(), e);
         Assert::AreNotEqual(etext(L"allo"), e);

         Assert::IsTrue(e == etext());
         Assert::IsFalse(e == element());
         Assert::IsFalse(e != etext());

         Assert::IsFalse(e == etext(L"bye"));
         Assert::IsFalse(etext::empty == etext(L"bye"));
         Assert::IsTrue(e != etext(L"bye"));

         Assert::IsFalse(e.reset(datatype::unknown));
         Assert::IsFalse(e.reset(datatype::integer));
         Assert::IsFalse(e.reset(datatype::name));
         Assert::IsFalse(e.reset(datatype::real));
         Assert::IsFalse(e.reset(datatype::dict));
         Assert::IsFalse(e.reset(datatype::boolean));

         Assert::IsTrue(e.reset(datatype::text));

         Assert::IsFalse(e.compatible(datatype::unknown));
         Assert::IsFalse(e.compatible(datatype::integer));
         Assert::IsFalse(e.compatible(datatype::boolean));
         Assert::IsFalse(e.compatible(datatype::real));
         Assert::IsFalse(e.compatible(datatype::dict));
         Assert::IsFalse(e.compatible(datatype::name));

         Assert::IsTrue(e.compatible(datatype::text));
      }

      TEST_METHOD(fast_element_text_operators)
      {
         etext e;

         Assert::AreEqual<text>(L"", e);

         e += text(L"hello");
         Assert::AreEqual<text>(L"hello", e);

         e += L", world!";
         Assert::AreEqual<text>(L"hello, world!", e);
      }

   };
}
