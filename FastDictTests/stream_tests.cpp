#include "CppUnitTest.h"

#include "dak/stream.h"
#include "helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak;
using namespace dak::voc;
using namespace std;

namespace tests
{		
   TEST_CLASS(stream_tests)
	{
	public:
		TEST_METHOD(stream_base)
		{
         wstringstream ss;

         ss.clear();
         ss.str(L"");
         ss << voc::rock;
         Assert::AreEqual(text(L"rock"), ss.str());

         ss.clear();
         ss.str(L"");
         dak::dict d1;
         ss << d1;
         Assert::AreEqual(text(L"{ }"), ss.str());

         ss.clear();
         ss.str(L"");
         dak::dict d2;
         d2[voc::rock] = 3;
         ss << d2;
         Assert::AreEqual(text(L"{ rock : 3 , }"), ss.str());

      }
   };
}
