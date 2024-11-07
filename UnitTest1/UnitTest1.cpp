#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_5_1_V1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestEmptySets)
		{
			vector<string> setA;
			vector<string> setB;
			vector<string> setC;
			vector<string> result = getCartProd(setA.data(), setA.size(), setB.data(), setB.size(), setC.data(), setC.size());
			Assert::IsTrue(result.empty());
		}

		TEST_METHOD(TestSingleElementSets)
		{
			string setA[] = { "a" };
			string setB[] = { "x" };
			string setC[] = { "1" };
			vector<string> result = getCartProd(setA, 1, setB, 1, setC, 1);
			Assert::AreEqual(size_t(1), result.size());
			Assert::AreEqual(string("ax1"), result[0]);
		}

		TEST_METHOD(TestMultipleElements)
		{
			string setA[] = { "a", "b" };
			string setB[] = { "x", "y" };
			string setC[] = { "1", "2" };
			vector<string> result = getCartProd(setA, 2, setB, 2, setC, 2);
			Assert::AreEqual(size_t(8), result.size());
			Assert::AreEqual(string("ax1"), result[0]);
			Assert::AreEqual(string("ax2"), result[1]);
			Assert::AreEqual(string("ay1"), result[2]);
			Assert::AreEqual(string("ay2"), result[3]);
			Assert::AreEqual(string("bx1"), result[4]);
			Assert::AreEqual(string("bx2"), result[5]);
			Assert::AreEqual(string("by1"), result[6]);
			Assert::AreEqual(string("by2"), result[7]);
		}

		TEST_METHOD(TestDifferentSizes)
		{
			string setA[] = { "a" };
			string setB[] = { "x", "y" };
			string setC[] = { "0", "1", "2" };
			vector<string> result = getCartProd(setA, 1, setB, 2, setC, 3);
			Assert::AreEqual(size_t(6), result.size());
			Assert::AreEqual(string("ax0"), result[0]);
			Assert::AreEqual(string("ax1"), result[1]);
			Assert::AreEqual(string("ax2"), result[2]);
			Assert::AreEqual(string("ay0"), result[3]);
			Assert::AreEqual(string("ay1"), result[4]);
			Assert::AreEqual(string("ay2"), result[5]);
		}
	};
}
