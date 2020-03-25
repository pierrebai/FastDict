#include "CppUnitTest.h"

#include "dak/name.h"
#include "helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak;
using namespace dak::voc;
using namespace std;

namespace tests
{		
   TEST_CLASS(name_tests)
	{
	public:
		TEST_METHOD(name_base)
		{
         name n;

         Assert::IsFalse(n.is_valid());

         Assert::AreEqual(n, name());
         Assert::AreNotEqual(n, (const name&)rock);

         Assert::IsTrue( n == name());
         Assert::IsFalse(n != name());
         Assert::IsFalse(n <  name());
         Assert::IsTrue( n <= name());
         Assert::IsFalse(n >  name());
         Assert::IsTrue( n >= name());

         Assert::IsFalse(n == rock);
         Assert::IsTrue(n != rock);
      }

      TEST_METHOD(name_derived)
      {
         rock_n r;

         Assert::IsTrue(r.is_valid());

         Assert::AreNotEqual((const name&)r, name());
         Assert::AreEqual(r, rock);

         Assert::IsTrue( r == rock);
         Assert::IsFalse(r != rock);
         Assert::IsFalse(r < rock);
         Assert::IsTrue( r <= rock);
         Assert::IsFalse(r > rock);
         Assert::IsTrue( r >= rock);

         Assert::IsFalse(r == name());
         Assert::IsTrue(r != name());
      }

   };
}