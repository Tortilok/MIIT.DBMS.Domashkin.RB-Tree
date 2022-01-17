#include "pch.h"
#include "CppUnitTest.h"
#include "../API/ols.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ApiTests
{
	TEST_CLASS(ApiTests)
	{
	public:
		
		TEST_METHOD(TestClassCreation)
		{
			const auto result = new ols();
			Assert::IsNotNull(result);
		};

		TEST_METHOD(TestListEmpty)
		{
			size_t expected = 0;
			ols result;
			Assert::IsTrue(result.empty());
			result.add(2);
			Assert::IsFalse(result.empty());
		};
		TEST_METHOD(TestAddItem)
		{
			size_t expected = 0;
			ols result;
			Assert::AreEqual(expected, result.size());
			result.add(2);
			expected = 1;
			Assert::AreEqual(expected, result.size());
			Assert::AreEqual(2, result.read(0));
			result.add(-2);
			result.add(600);
			result.add(8);
			expected = 4;
			Assert::AreEqual(expected, result.size());
			Assert::AreEqual(600, result.read(2));

		};

		TEST_METHOD(TestReadItem)
		{
			ols result;
			result.add(-100);
			Assert::AreEqual(-100, result.read(0));
			result.add(-2);
			result.add(70);
			result.add(8);
			Assert::AreEqual(70, result.read(2));
			Assert::AreEqual(8, result.read(3));
			Assert::AreEqual(-2, result.read(1));
		};
		TEST_METHOD(TestRemoveItemStart)
		{
			ols result;
			size_t expected = 3;
			result.add(100);
			result.add(200);
			result.add(300);
			Assert::AreEqual(expected, result.size());
			result.remove(0);
			expected = 2;
			Assert::AreEqual(expected, result.size());
		};
		TEST_METHOD(TestRemoveItemMiddle)
		{
			ols result;
			size_t expected = 4;
			result.add(100);
			result.add(-200);
			result.add(500);
			result.add(300);
			Assert::AreEqual(expected, result.size());
			result.remove(2);
			expected = 3;
			Assert::AreEqual(expected, result.size());
		};

		TEST_METHOD(TestRemoveItemEnd)
		{
			ols result;
			size_t expected = 2;
			result.add(100);
			result.add(300);
			Assert::AreEqual(expected, result.size());
			result.remove(1);
			expected = 1;
			Assert::AreEqual(expected, result.size());
		};

		TEST_METHOD(TestSearchEnd)
		{
			ols result;
			result.add(100);
			result.add(500);
			result.add(3);
			result.add(-100);

			int temp = result.search(-100);
			int expected = 3;
			Assert::AreEqual(expected, temp);
			Assert::AreEqual(-100, result.read(temp));
		};

		TEST_METHOD(TestSearchMiddle)
		{
			ols result;
			result.add(100);
			result.add(500);
			result.add(3);
			result.add(-100);

			int temp = result.search(3);
			int expected = 2;
			Assert::AreEqual(expected, temp);
			Assert::AreEqual(3, result.read(temp));
		};

		TEST_METHOD(TestSearchStart)
		{
			ols result;
			result.add(100);
			result.add(500);
			result.add(3);
			result.add(-100);

			int temp = result.search(100);
			int expected = 0;
			Assert::AreEqual(expected, temp);
			Assert::AreEqual(100, result.read(temp));
		};

		TEST_METHOD(TestUpdateItemMiddle)
		{
			ols result;
			result.add(1);
			result.add(50);
			result.add(-3);
			result.add(-100);
			
			result.update(2, 3);

			Assert::AreEqual(3, result.read(2));
		};

		TEST_METHOD(TestUpdateItemStart)
		{
			ols result;
			result.add(1);
			result.add(50);
			result.add(-3);
			result.add(-100);

			result.update(0, 1000);

			Assert::AreEqual(1000, result.read(0));
		};

		TEST_METHOD(TestUpdateItemEnd)
		{
			ols result;
			result.add(1);
			result.add(50);
			result.add(-3);
			result.add(-100);

			result.update(3, -15);

			Assert::AreEqual(-15, result.read(3));
		};

		TEST_METHOD(TestSizeZero)
		{
			ols result;
			size_t expected = 0;
			Assert::AreEqual(expected, result.size());
		};

		TEST_METHOD(TestSizeNoZero)
		{
			ols result;
			result.add(1);
			result.add(1);
			result.add(1);
			size_t expected = 3;
			Assert::AreEqual(expected, result.size());
		};
		TEST_METHOD(TestOperatorZero)
		{
			/* Тест оператора << при пустом списке*/
			ols result;
			std::stringstream s;
			s << result;
			string temp = "";
			Assert::AreEqual(s.str(), temp);
		}

		TEST_METHOD(TestOperatorNoZero)
		{
			/* Тест оператора << при заполненном списке*/
			ols result;
			result.add(1);
			result.add(2);
			result.add(3);
			std::stringstream s;
			s << result;
			string temp = "1 2 3 ";
			Assert::AreEqual(s.str(), temp);
		}

		TEST_METHOD(TestIndexZero)
		{
			/* Тест обращения по индексу при пустом списке*/
			ols result;
			Assert::ExpectException<std::out_of_range>([&]
				{
					result[2];
				});
		}

		TEST_METHOD(TestIndexNoZero)
		{
			/* Тест обращения по индексу при заполненном списке*/
			ols result;
			result.add(1);
			result.add(2);
			result.add(3);
			int temp = 3;
			Assert::AreEqual(temp, result[2]);
		}
	};
}
