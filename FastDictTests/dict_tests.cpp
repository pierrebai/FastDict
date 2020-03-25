#include "CppUnitTest.h"

#include "dak/dict.h"
#include "dak/voc.h"
#include "helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak;
using namespace dak::voc;

namespace tests
{
   TEST_CLASS(dict_tests)
	{
	public:
		TEST_METHOD(dict_base)
		{
         dak::dict d1;

         Assert::AreEqual<dak::index>(0, d1.size());

         d1[voc::rock] = 3;
         d1[voc::pebble] = 4;
         d1[voc::sand] = 5.0;
         d1[voc::hello] = L"6";
         d1[voc::world] = voc::rock;

         Assert::AreEqual<dak::index>(5, d1.size());

         Assert::AreEqual<int32>(3, d1[rock]);
         Assert::AreEqual<int64>(4, d1[pebble]);
         Assert::AreEqual<double>(5.0, d1[sand]);
         Assert::AreEqual<text>(L"6", d1[hello]);
         Assert::AreEqual<name>(rock, d1[world]);

         Assert::IsTrue(d1.erase(rock));
         Assert::IsTrue(d1.erase(pebble));
         Assert::IsTrue(d1.erase(world));
         Assert::IsTrue(d1.erase(hello));
         Assert::IsTrue(d1.erase(sand));
         Assert::IsFalse(d1.erase(rock));

         Assert::AreEqual<dak::index>(0, d1.size());
      }

      TEST_METHOD(dict_append)
      {
         dak::dict d1;

         d1[rock] = 3;
         d1[pebble] = 4;
         d1[sand] = 5.0;
         d1[hello][world] = rock;

         dak::dict d2;

         d2 += d1;

         Assert::AreEqual<dak::index>(4, d1.size());
         Assert::AreEqual<dak::index>(4, d2.size());

         Assert::AreEqual<int32>(3, d2[rock]);
         Assert::AreEqual<int64>(4, d2[pebble]);
         Assert::AreEqual<double>(5.0, d2[sand]);
         Assert::AreEqual<name>(rock, d2[hello][world]);

         Assert::IsTrue(d2.contains(rock));
         Assert::IsTrue(d2.contains(pebble));
         Assert::IsTrue(d2.contains(sand));
         Assert::IsTrue(d2.contains(hello));
         Assert::IsTrue(d2.contains(hello));
         Assert::IsTrue(d2[hello].contains(world));

         Assert::AreEqual(d1, d2);
      }

      TEST_METHOD(dict_iterator)
      {
         dak::dict d1;

         d1[rock] = 3;
         d1[pebble] = 4;
         d1[sand] = 5.0;
         d1[hello] = L"6";

         int32 count = 0;
         for (const auto& i : d1)
         {
            count += 1;
            if (i.first == rock)
               Assert::AreEqual<int32>(3, i.second);
            if (i.first == pebble)
               Assert::AreEqual<int64>(4, i.second);
            if (i.first == sand)
               Assert::AreEqual<double>(5.0, i.second);
            if (i.first == hello)
               Assert::AreEqual<text>(L"6", i.second);
         }

         Assert::AreEqual(4, count);
      }
   };
}