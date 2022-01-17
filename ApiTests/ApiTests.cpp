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

		TEST_METHOD(TestSearch)
		{
			const auto result = new ols();
			Assert::IsNotNull(result);
		};

		TEST_METHOD(TestUpdateItem)
		{
			const auto result = new ols();
			Assert::IsNotNull(result);
		};

		TEST_METHOD(TestSize)
		{
			const auto result = new ols();
			Assert::IsNotNull(result);
		};
	};
}
