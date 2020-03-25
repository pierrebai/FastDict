#include "CppUnitTest.h"

#include "dak/element.h"
#include "helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak;

namespace tests
{		
   TEST_CLASS(element_tests)
	{
	public:
		TEST_METHOD(element_base)
		{
         element e;

         Assert::AreEqual(e, element());
         Assert::AreEqual(e, element::empty);
         Assert::AreNotEqual(e, element(1));

         Assert::IsTrue( e == element());
         Assert::IsTrue(e == element::empty);
         Assert::IsFalse(e != element());

         Assert::IsFalse(e == element(1));
         Assert::IsFalse(element::empty == element(1));
         Assert::IsTrue(e != element(1));
      }

      TEST_METHOD(element_constructors)
      {
         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d((dict()));
         element e_n(voc::rock);

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::text, e_t1.type());
         Assert::AreEqual(dak::datatype::text, e_t2.type());
         Assert::AreEqual(dak::datatype::integer, e_c1.type());
         Assert::AreEqual(dak::datatype::integer, e_c2.type());
         Assert::AreEqual(dak::datatype::boolean, e_b.type());
         Assert::AreEqual(dak::datatype::integer, e_i2.type());
         Assert::AreEqual(dak::datatype::integer, e_i1.type());
         Assert::AreEqual(dak::datatype::integer, e_i3.type());
         Assert::AreEqual(dak::datatype::integer, e_u1.type());
         Assert::AreEqual(dak::datatype::integer, e_u2.type());
         Assert::AreEqual(dak::datatype::integer, e_u3.type());
         Assert::AreEqual(dak::datatype::real, e_r1.type());
         Assert::AreEqual(dak::datatype::real, e_r2.type());
         Assert::AreEqual(dak::datatype::dict, e_d.type());
         Assert::AreEqual(dak::datatype::name, e_n.type());
      }

      TEST_METHOD(element_assignments)
      {
         element e_u;
         element e_t1;
         element e_t2;
         element e_c1;
         element e_c2;
         element e_b;
         element e_i2;
         element e_i1;
         element e_i3;
         element e_u1;
         element e_u2;
         element e_u3;
         element e_r1;
         element e_r2;
         element e_d;
         element e_n;

         e_u  = element();
         e_t1 = text(L"text");
         e_t2 = L"strptr";
         e_c1 = 'c';
         e_c2 = L'w';
         e_b  = true;
         e_i2 = (int16)2;
         e_i1 = (int32)1;
         e_i3 = (int64)3;
         e_u1 = (word)4u;
         e_u2 = (dword)5u;
         e_u3 = (qword)6u;
         e_r1 = 7.0f;
         e_r2 = 8.0;
         e_d  = dict();
         e_n  = voc::rock;

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::text, e_t1.type());
         Assert::AreEqual(dak::datatype::text, e_t2.type());
         Assert::AreEqual(dak::datatype::integer, e_c1.type());
         Assert::AreEqual(dak::datatype::integer, e_c2.type());
         Assert::AreEqual(dak::datatype::boolean, e_b.type());
         Assert::AreEqual(dak::datatype::integer, e_i2.type());
         Assert::AreEqual(dak::datatype::integer, e_i1.type());
         Assert::AreEqual(dak::datatype::integer, e_i3.type());
         Assert::AreEqual(dak::datatype::integer, e_u1.type());
         Assert::AreEqual(dak::datatype::integer, e_u2.type());
         Assert::AreEqual(dak::datatype::integer, e_u3.type());
         Assert::AreEqual(dak::datatype::real, e_r1.type());
         Assert::AreEqual(dak::datatype::real, e_r2.type());
         Assert::AreEqual(dak::datatype::dict, e_d.type());
         Assert::AreEqual(dak::datatype::name, e_n.type());
      }

      TEST_METHOD(element_text_assignments)
      {
         element e1;

         e1 = L"hello";
         Assert::AreEqual<text>(text(L"hello"), e1);

         e1 = (strptr)nullptr;
         Assert::AreEqual<text>(text(L""), e1);

         e1 = L"bye";
         Assert::AreEqual<text>(text(L"bye"), e1);

         e1.reset(datatype::text);
         Assert::AreEqual<text>(text(L""), e1);

         e1 = L"bye";
         Assert::AreEqual<text>(text(L"bye"), e1);

         e1.verify(datatype::text);
         Assert::AreEqual<text>(text(L"bye"), e1);
      }

      TEST_METHOD(element_conversion)
      {
         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d((dict()));
         element e_n(voc::rock);

         Assert::AreEqual<int32>(0, e_u);
         Assert::AreEqual<text>(text(L"text"), e_t1);
         Assert::AreEqual<text>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16>((int16)2, e_i2);
         Assert::AreEqual<int32>((int32)1, e_i1);
         Assert::AreEqual<int64>((int64)3, e_i3);
         Assert::AreEqual<word>((word)4u, e_u1);
         Assert::AreEqual<dword>((dword)5u, e_u2);
         Assert::AreEqual<qword>((qword)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<dict>((dict()), e_d);
         Assert::AreEqual<name>(voc::rock, e_n);
      }

      TEST_METHOD(element_const_conversion)
      {
         const element e_u;
         const element e_t1(text(L"text"));
         const element e_t2(L"strptr");
         const element e_c1('c');
         const element e_c2(L'w');
         const element e_b(true);
         const element e_i2((int16)2);
         const element e_i1((int32)1);
         const element e_i3((int64)3);
         const element e_u1((word)4u);
         const element e_u2((dword)5u);
         const element e_u3((qword)6u);
         const element e_r1(7.0f);
         const element e_r2(8.0);
         const element e_d((dict()));
         const element e_n(voc::rock);

         Assert::AreEqual<int32>(0, e_u);
         Assert::AreEqual<text>(text(L"text"), e_t1);
         Assert::AreEqual<text>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16>((int16)2, e_i2);
         Assert::AreEqual<int32>((int32)1, e_i1);
         Assert::AreEqual<int64>((int64)3, e_i3);
         Assert::AreEqual<word>((word)4u, e_u1);
         Assert::AreEqual<dword>((dword)5u, e_u2);
         Assert::AreEqual<qword>((qword)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<dict>((dict()), e_d);
         Assert::AreEqual<name>(voc::rock, e_n);
      }

      TEST_METHOD(element_unknown_assignments)
      {
         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d((dict()));
         element e_n(voc::rock);

         // Assigning an empty element of type unknown
         // should set the type to unknown and reset the value.
         e_u = element();
         e_t1 = element();
         e_t2 = element();
         e_c1 = element();
         e_c2 = element();
         e_b = element();
         e_i2 = element();
         e_i1 = element();
         e_i3 = element();
         e_u1 = element();
         e_u2 = element();
         e_u3 = element();
         e_r1 = element();
         e_r2 = element();
         e_d = element();
         e_n = element();

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::unknown, e_t1.type());
         Assert::AreEqual(dak::datatype::unknown, e_t2.type());
         Assert::AreEqual(dak::datatype::unknown, e_c1.type());
         Assert::AreEqual(dak::datatype::unknown, e_c2.type());
         Assert::AreEqual(dak::datatype::unknown, e_b.type());
         Assert::AreEqual(dak::datatype::unknown, e_i2.type());
         Assert::AreEqual(dak::datatype::unknown, e_i1.type());
         Assert::AreEqual(dak::datatype::unknown, e_i3.type());
         Assert::AreEqual(dak::datatype::unknown, e_u1.type());
         Assert::AreEqual(dak::datatype::unknown, e_u2.type());
         Assert::AreEqual(dak::datatype::unknown, e_u3.type());
         Assert::AreEqual(dak::datatype::unknown, e_r1.type());
         Assert::AreEqual(dak::datatype::unknown, e_r2.type());
         Assert::AreEqual(dak::datatype::unknown, e_d.type());
         Assert::AreEqual(dak::datatype::unknown, e_n.type());

         Assert::AreEqual<int32>(0, e_u);
         Assert::AreEqual<text>(text(L""), e_t1);
         Assert::AreEqual<text>(L"", e_t2);
         Assert::AreEqual<char>('\0', e_c1);
         Assert::AreEqual<wchar_t>(L'\0', e_c2);
         Assert::AreEqual<bool>(false, e_b);
         Assert::AreEqual<int16>((int16)0, e_i2);
         Assert::AreEqual<int32>((int32)0, e_i1);
         Assert::AreEqual<int64>((int64)0, e_i3);
         Assert::AreEqual<word>((word)0u, e_u1);
         Assert::AreEqual<dword>((dword)0u, e_u2);
         Assert::AreEqual<qword>((qword)0u, e_u3);
         Assert::AreEqual<float>(0.0f, e_r1);
         Assert::AreEqual<double>(0.0, e_r2);
         Assert::AreEqual<dict>((dict()), e_d);
         Assert::AreEqual<name>(name(), e_n);
      }

      TEST_METHOD(element_size)
      {
         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         const element e_u;
         const element e_t1(text(L"text"));
         const element e_t2(L"strptr");
         const element e_c1('c');
         const element e_c2(L'w');
         const element e_b(true);
         const element e_i2((int16)2);
         const element e_i1((int32)1);
         const element e_i3((int64)3);
         const element e_u1((word)4u);
         const element e_u2((dword)5u);
         const element e_u3((qword)6u);
         const element e_r1(7.0f);
         const element e_r2(8.0);
         const element e_d(d);
         const element e_n(voc::rock);

         Assert::AreEqual<index>(0, e_u.size());
         Assert::AreEqual<index>(4, e_t1.size());
         Assert::AreEqual<index>(6, e_t2.size());
         Assert::AreEqual<index>(0, e_c1.size());
         Assert::AreEqual<index>(0, e_c2.size());
         Assert::AreEqual<index>(0, e_b.size());
         Assert::AreEqual<index>(0, e_i2.size());
         Assert::AreEqual<index>(0, e_i1.size());
         Assert::AreEqual<index>(0, e_i3.size());
         Assert::AreEqual<index>(0, e_u1.size());
         Assert::AreEqual<index>(0, e_u2.size());
         Assert::AreEqual<index>(0, e_u3.size());
         Assert::AreEqual<index>(0, e_r1.size());
         Assert::AreEqual<index>(0, e_r2.size());
         Assert::AreEqual<index>(3, e_d.size());
         Assert::AreEqual<index>(0, e_n.size());
      }

      TEST_METHOD(element_compatible)
      {
         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         const element e_u;
         const element e_t1(text(L"text"));
         const element e_t2(L"strptr");
         const element e_c1('c');
         const element e_c2(L'w');
         const element e_b(true);
         const element e_i2((int16)2);
         const element e_i1((int32)1);
         const element e_i3((int64)3);
         const element e_u1((word)4u);
         const element e_u2((dword)5u);
         const element e_u3((qword)6u);
         const element e_r1(7.0f);
         const element e_r2(8.0);
         const element e_d(d);
         const element e_n(voc::rock);

         Assert::IsTrue(e_u.compatible(dak::datatype::unknown));
         Assert::IsTrue(e_t1.compatible(dak::datatype::text));
         Assert::IsTrue(e_t2.compatible(dak::datatype::text));
         Assert::IsTrue(e_c1.compatible(dak::datatype::integer));
         Assert::IsTrue(e_c2.compatible(dak::datatype::integer));
         Assert::IsTrue(e_b.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_i2.compatible(dak::datatype::integer));
         Assert::IsTrue(e_i1.compatible(dak::datatype::integer));
         Assert::IsTrue(e_i3.compatible(dak::datatype::integer));
         Assert::IsTrue(e_u1.compatible(dak::datatype::integer));
         Assert::IsTrue(e_u2.compatible(dak::datatype::integer));
         Assert::IsTrue(e_u3.compatible(dak::datatype::integer));
         Assert::IsTrue(e_r1.compatible(dak::datatype::real));
         Assert::IsTrue(e_r2.compatible(dak::datatype::real));
         Assert::IsTrue(e_d.compatible(dak::datatype::dict));
         Assert::IsTrue(e_n.compatible(dak::datatype::name));

         Assert::IsTrue(e_b.compatible(dak::datatype::integer));
         Assert::IsTrue(e_i2.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_i1.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_i3.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_u1.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_u2.compatible(dak::datatype::boolean));
         Assert::IsTrue(e_u3.compatible(dak::datatype::boolean));

         Assert::IsFalse(e_u.compatible(dak::datatype::text));
         Assert::IsFalse(e_t1.compatible(dak::datatype::integer));
         Assert::IsFalse(e_t2.compatible(dak::datatype::integer));
         Assert::IsFalse(e_c1.compatible(dak::datatype::real));
         Assert::IsFalse(e_c2.compatible(dak::datatype::unknown));
         Assert::IsFalse(e_b.compatible(dak::datatype::real));
         Assert::IsFalse(e_i2.compatible(dak::datatype::text));
         Assert::IsFalse(e_i3.compatible(dak::datatype::dict));
         Assert::IsFalse(e_u1.compatible(dak::datatype::name));
         Assert::IsFalse(e_u3.compatible(dak::datatype::real));
         Assert::IsFalse(e_r1.compatible(dak::datatype::integer));
         Assert::IsFalse(e_r2.compatible(dak::datatype::name));
         Assert::IsFalse(e_n.compatible(dak::datatype::integer));
      }

      TEST_METHOD(element_reset)
      {
         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d(d);
         element e_n(voc::rock);

         e_u.reset();
         e_t1.reset();
         e_t2.reset();
         e_c1.reset();
         e_c2.reset();
         e_b.reset();
         e_i2.reset();
         e_i1.reset();
         e_i3.reset();
         e_u1.reset();
         e_u2.reset();
         e_u3.reset();
         e_r1.reset();
         e_r2.reset();
         e_d.reset();
         e_n.reset();

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::unknown, e_t1.type());
         Assert::AreEqual(dak::datatype::unknown, e_t2.type());
         Assert::AreEqual(dak::datatype::unknown, e_c1.type());
         Assert::AreEqual(dak::datatype::unknown, e_c2.type());
         Assert::AreEqual(dak::datatype::unknown, e_b.type());
         Assert::AreEqual(dak::datatype::unknown, e_i2.type());
         Assert::AreEqual(dak::datatype::unknown, e_i1.type());
         Assert::AreEqual(dak::datatype::unknown, e_i3.type());
         Assert::AreEqual(dak::datatype::unknown, e_u1.type());
         Assert::AreEqual(dak::datatype::unknown, e_u2.type());
         Assert::AreEqual(dak::datatype::unknown, e_u3.type());
         Assert::AreEqual(dak::datatype::unknown, e_r1.type());
         Assert::AreEqual(dak::datatype::unknown, e_r2.type());
         Assert::AreEqual(dak::datatype::unknown, e_d.type());
         Assert::AreEqual(dak::datatype::unknown, e_n.type());
      }

      TEST_METHOD(element_ensure)
      {
         element e_u;
         element e_t1;
         element e_t2;
         element e_c1;
         element e_c2;
         element e_b;
         element e_i2;
         element e_i1;
         element e_i3;
         element e_u1;
         element e_u2;
         element e_u3;
         element e_r1;
         element e_r2;
         element e_d;
         element e_n;

         e_u.ensure(dak::datatype::unknown);
         e_t1.ensure(dak::datatype::text);
         e_t2.ensure(dak::datatype::text);
         e_c1.ensure(dak::datatype::integer);
         e_c2.ensure(dak::datatype::integer);
         e_b.ensure(dak::datatype::boolean);
         e_i2.ensure(dak::datatype::integer);
         e_i1.ensure(dak::datatype::integer);
         e_i3.ensure(dak::datatype::integer);
         e_u1.ensure(dak::datatype::integer);
         e_u2.ensure(dak::datatype::integer);
         e_u3.ensure(dak::datatype::integer);
         e_r1.ensure(dak::datatype::real);
         e_r2.ensure(dak::datatype::real);
         e_d.ensure(dak::datatype::dict);
         e_n.ensure(dak::datatype::name);

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::text, e_t1.type());
         Assert::AreEqual(dak::datatype::text, e_t2.type());
         Assert::AreEqual(dak::datatype::integer, e_c1.type());
         Assert::AreEqual(dak::datatype::integer, e_c2.type());
         Assert::AreEqual(dak::datatype::boolean, e_b.type());
         Assert::AreEqual(dak::datatype::integer, e_i2.type());
         Assert::AreEqual(dak::datatype::integer, e_i1.type());
         Assert::AreEqual(dak::datatype::integer, e_i3.type());
         Assert::AreEqual(dak::datatype::integer, e_u1.type());
         Assert::AreEqual(dak::datatype::integer, e_u2.type());
         Assert::AreEqual(dak::datatype::integer, e_u3.type());
         Assert::AreEqual(dak::datatype::real, e_r1.type());
         Assert::AreEqual(dak::datatype::real, e_r2.type());
         Assert::AreEqual(dak::datatype::dict, e_d.type());
         Assert::AreEqual(dak::datatype::name, e_n.type());
      }

      TEST_METHOD(element_ensure_preserve_value)
      {
         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d(d);
         element e_n(voc::rock);

         // Ensuring the same type should not reset the value.
         e_u.ensure(dak::datatype::unknown);
         e_t1.ensure(dak::datatype::text);
         e_t2.ensure(dak::datatype::text);
         e_c1.ensure(dak::datatype::integer);
         e_c2.ensure(dak::datatype::integer);
         e_b.ensure(dak::datatype::boolean);
         e_i2.ensure(dak::datatype::integer);
         e_i1.ensure(dak::datatype::integer);
         e_i3.ensure(dak::datatype::integer);
         e_u1.ensure(dak::datatype::integer);
         e_u2.ensure(dak::datatype::integer);
         e_u3.ensure(dak::datatype::integer);
         e_r1.ensure(dak::datatype::real);
         e_r2.ensure(dak::datatype::real);
         e_d.ensure(dak::datatype::dict);
         e_n.ensure(dak::datatype::name);

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::text, e_t1.type());
         Assert::AreEqual(dak::datatype::text, e_t2.type());
         Assert::AreEqual(dak::datatype::integer, e_c1.type());
         Assert::AreEqual(dak::datatype::integer, e_c2.type());
         Assert::AreEqual(dak::datatype::boolean, e_b.type());
         Assert::AreEqual(dak::datatype::integer, e_i2.type());
         Assert::AreEqual(dak::datatype::integer, e_i1.type());
         Assert::AreEqual(dak::datatype::integer, e_i3.type());
         Assert::AreEqual(dak::datatype::integer, e_u1.type());
         Assert::AreEqual(dak::datatype::integer, e_u2.type());
         Assert::AreEqual(dak::datatype::integer, e_u3.type());
         Assert::AreEqual(dak::datatype::real, e_r1.type());
         Assert::AreEqual(dak::datatype::real, e_r2.type());
         Assert::AreEqual(dak::datatype::dict, e_d.type());
         Assert::AreEqual(dak::datatype::name, e_n.type());

         Assert::AreEqual<int32>(0, e_u);
         Assert::AreEqual<text>(text(L"text"), e_t1);
         Assert::AreEqual<text>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16>((int16)2, e_i2);
         Assert::AreEqual<int32>((int32)1, e_i1);
         Assert::AreEqual<int64>((int64)3, e_i3);
         Assert::AreEqual<word>((word)4u, e_u1);
         Assert::AreEqual<dword>((dword)5u, e_u2);
         Assert::AreEqual<qword>((qword)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<dict>(d, e_d);
         Assert::AreEqual<name>(voc::rock, e_n);

         // Ensuring a similar type should preserve most of the value.
         e_u.ensure(dak::datatype::integer);
         e_t1.ensure(dak::datatype::boolean);
         e_t2.ensure(dak::datatype::boolean);
         e_c1.ensure(dak::datatype::real);
         e_c2.ensure(dak::datatype::real);
         e_b.ensure(dak::datatype::real);
         e_i2.ensure(dak::datatype::real);
         e_i1.ensure(dak::datatype::real);
         e_i3.ensure(dak::datatype::real);
         e_u1.ensure(dak::datatype::real);
         e_u2.ensure(dak::datatype::boolean);
         e_u3.ensure(dak::datatype::boolean);
         e_r1.ensure(dak::datatype::integer);
         e_r2.ensure(dak::datatype::boolean);
         e_d.ensure(dak::datatype::boolean);
         e_n.ensure(dak::datatype::boolean);

         Assert::AreEqual<int64>(0, e_u);
         Assert::AreEqual<bool>(true, e_t1);
         Assert::AreEqual<bool>(true, e_t2);
         Assert::AreEqual<double>(99., e_c1);
         Assert::AreEqual<double>(119., e_c2);
         Assert::AreEqual<bool>(1., e_b);
         Assert::AreEqual<double>(2., e_i2);
         Assert::AreEqual<double>(1., e_i1);
         Assert::AreEqual<double>(3., e_i3);
         Assert::AreEqual<double>(4., e_u1);
         Assert::AreEqual<bool>(true, e_u2);
         Assert::AreEqual<bool>(true, e_u3);
         Assert::AreEqual<int64>(7, e_r1);
         Assert::AreEqual<bool>(true, e_r2);
         Assert::AreEqual<bool>(true, e_d);
         Assert::AreEqual<bool>(true, e_n);

      }

      TEST_METHOD(element_verify)
      {
         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         element e_u;
         element e_t1(text(L"text"));
         element e_t2(L"strptr");
         element e_c1('c');
         element e_c2(L'w');
         element e_b(true);
         element e_i2((int16)2);
         element e_i1((int32)1);
         element e_i3((int64)3);
         element e_u1((word)4u);
         element e_u2((dword)5u);
         element e_u3((qword)6u);
         element e_r1(7.0f);
         element e_r2(8.0);
         element e_d(d);
         element e_n(voc::rock);

         // Verifying the same type should not reset the value.
         e_u.verify(dak::datatype::unknown);
         e_t1.verify(dak::datatype::text);
         e_t2.verify(dak::datatype::text);
         e_c1.verify(dak::datatype::integer);
         e_c2.verify(dak::datatype::integer);
         e_b.verify(dak::datatype::boolean);
         e_i2.verify(dak::datatype::integer);
         e_i1.verify(dak::datatype::integer);
         e_i3.verify(dak::datatype::integer);
         e_u1.verify(dak::datatype::integer);
         e_u2.verify(dak::datatype::integer);
         e_u3.verify(dak::datatype::integer);
         e_r1.verify(dak::datatype::real);
         e_r2.verify(dak::datatype::real);
         e_d.verify(dak::datatype::dict);
         e_n.verify(dak::datatype::name);

         Assert::AreEqual(dak::datatype::unknown, e_u.type());
         Assert::AreEqual(dak::datatype::text, e_t1.type());
         Assert::AreEqual(dak::datatype::text, e_t2.type());
         Assert::AreEqual(dak::datatype::integer, e_c1.type());
         Assert::AreEqual(dak::datatype::integer, e_c2.type());
         Assert::AreEqual(dak::datatype::boolean, e_b.type());
         Assert::AreEqual(dak::datatype::integer, e_i2.type());
         Assert::AreEqual(dak::datatype::integer, e_i1.type());
         Assert::AreEqual(dak::datatype::integer, e_i3.type());
         Assert::AreEqual(dak::datatype::integer, e_u1.type());
         Assert::AreEqual(dak::datatype::integer, e_u2.type());
         Assert::AreEqual(dak::datatype::integer, e_u3.type());
         Assert::AreEqual(dak::datatype::real, e_r1.type());
         Assert::AreEqual(dak::datatype::real, e_r2.type());
         Assert::AreEqual(dak::datatype::dict, e_d.type());
         Assert::AreEqual(dak::datatype::name, e_n.type());

         Assert::AreEqual<int32>(0, e_u);
         Assert::AreEqual<text>(text(L"text"), e_t1);
         Assert::AreEqual<text>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16>((int16)2, e_i2);
         Assert::AreEqual<int32>((int32)1, e_i1);
         Assert::AreEqual<int64>((int64)3, e_i3);
         Assert::AreEqual<word>((word)4u, e_u1);
         Assert::AreEqual<dword>((dword)5u, e_u2);
         Assert::AreEqual<qword>((qword)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<dict>(d, e_d);
         Assert::AreEqual<name>(voc::rock, e_n);
      }

      TEST_METHOD(element_int64_operators)
      {
         element e;

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
         Assert::AreEqual<double>(8.5, e);

         e -= 0.99;
         Assert::AreEqual<double>(7.51, e);

         e *= 0.5;
         Assert::AreEqual<double>(3.755, e);

         e /= 2.1;
         Assert::AreEqual<double>(3.755 / 2.1, e);

         e = text(L"hello");
         Assert::AreEqual<text>(L"hello", e);

         e += L", world!";
         Assert::AreEqual<text>(L"hello, world!", e);

         e = L"bye";
         Assert::AreEqual<text>(L"bye", e);
      }

      TEST_METHOD(element_double_operators)
      {
         element e;

         e = 0.0;

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
         Assert::AreEqual<double>(3.755 / 2.1, e);

         e = text(L"hello");
         Assert::AreEqual<text>(L"hello", e);

         e += L", world!";
         Assert::AreEqual<text>(L"hello, world!", e);

         e = L"bye";
         Assert::AreEqual<text>(L"bye", e);
      }

      TEST_METHOD(element_bool_operator)
      {
         element e_u;
         element e_t1(L"");
         element e_t2(text(L""));
         element e_c1('\0');
         element e_c2(L'\0');
         element e_b(false);
         element e_i2((int16)0);
         element e_i1((int32)0);
         element e_i3((int64)0);
         element e_u1((word)0);
         element e_u2((dword)0);
         element e_u3((qword)0);
         element e_r1(0.f);
         element e_r2(0.);
         element e_d(dict::empty);
         element e_n((name()));

         Assert::AreEqual<bool>(false, e_u);
         Assert::AreEqual<bool>(false, e_t1);
         Assert::AreEqual<bool>(false, e_t2);
         Assert::AreEqual<bool>(false, e_c1);
         Assert::AreEqual<bool>(false, e_c2);
         Assert::AreEqual<bool>(false, e_b);
         Assert::AreEqual<bool>(false, e_i2);
         Assert::AreEqual<bool>(false, e_i1);
         Assert::AreEqual<bool>(false, e_i3);
         Assert::AreEqual<bool>(false, e_u1);
         Assert::AreEqual<bool>(false, e_u2);
         Assert::AreEqual<bool>(false, e_u3);
         Assert::AreEqual<bool>(false, e_r1);
         Assert::AreEqual<bool>(false, e_r2);
         Assert::AreEqual<bool>(false, e_d);
         Assert::AreEqual<bool>(false, e_n);

         dict d;
         d[voc::rock] = 33;
         d[voc::pebble] = 4;
         d[voc::sand] = 5;

         e_u = element();
         e_t1 = text(L"text");
         e_t2 = L"strptr";
         e_c1 = 'c';
         e_c2 = L'w';
         e_b = true;
         e_i2 = (int16)2;
         e_i1 = (int32)1;
         e_i3 = (int64)3;
         e_u1 = (word)4u;
         e_u2 = (dword)5u;
         e_u3 = (qword)6u;
         e_r1 = 7.0f;
         e_r2 = 8.0;
         e_d = d;
         e_n = voc::rock;

         Assert::AreEqual<bool>(false, e_u);
         Assert::AreEqual<bool>(true, e_t1);
         Assert::AreEqual<bool>(true, e_t2);
         Assert::AreEqual<bool>(true, e_c1);
         Assert::AreEqual<bool>(true, e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<bool>(true, e_i2);
         Assert::AreEqual<bool>(true, e_i1);
         Assert::AreEqual<bool>(true, e_i3);
         Assert::AreEqual<bool>(true, e_u1);
         Assert::AreEqual<bool>(true, e_u2);
         Assert::AreEqual<bool>(true, e_u3);
         Assert::AreEqual<bool>(true, e_r1);
         Assert::AreEqual<bool>(true, e_r2);
         Assert::AreEqual<bool>(true, e_d);
         Assert::AreEqual<bool>(true, e_n);
      }

      TEST_METHOD(element_dict)
      {
         dict d;
         d[voc::rock] = 33.;
         d[voc::pebble] = 4;
         d[voc::sand] = 5.f;

         element e;

         e[voc::age] = 55.;
         e.append(d);
         e.erase(voc::rock);
         e.erase(voc::pebble);

         Assert::IsFalse(e.contains(voc::pebble));
         Assert::IsTrue(e.contains(voc::sand));
         Assert::IsTrue(e.contains(voc::age));
         Assert::IsFalse(e.contains(voc::rock));

         Assert::AreEqual<index>(2, e.size());
         Assert::AreEqual<float>(5.f, e[voc::sand]);
         Assert::AreEqual<double>(55., e[voc::age]);
      }
   };
}
