#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/hashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableUnitTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(TestAdd)
		{
			HashTable<int, string> hashTable;
			hashTable.add(1, "One");
			hashTable.add(2, "Two");
			hashTable.add(3, "Three");

			string value;
			Assert::IsTrue(hashTable.find(1, value));
			Assert::AreEqual(value, string("One"));

			Assert::IsTrue(hashTable.find(2, value));
			Assert::AreEqual(value, string("Two"));

			Assert::IsTrue(hashTable.find(3, value));
			Assert::AreEqual(value, string("Three"));
		}

		TEST_METHOD(TestRemove)
		{
			HashTable<int, string> hashTable;
			hashTable.add(1, "One");
			hashTable.add(2, "Two");
			hashTable.add(3, "Three");

			Assert::IsTrue(hashTable.remove(2));
			Assert::IsFalse(hashTable.remove(4));
			Assert::IsFalse(hashTable.remove(5));
		}

		TEST_METHOD(TestFind)
		{
			HashTable<int, string> hashTable;
			hashTable.add(1, "One");
			hashTable.add(2, "Two");
			hashTable.add(3, "Three");

			string value;
			Assert::IsTrue(hashTable.find(1, value));
			Assert::AreEqual(value, string("One"));

			Assert::IsTrue(hashTable.find(2, value));
			Assert::AreEqual(value, string("Two"));

			Assert::IsTrue(hashTable.find(3, value));
			Assert::AreEqual(value, string("Three"));

			Assert::IsFalse(hashTable.find(4, value));
		}
	};
}
