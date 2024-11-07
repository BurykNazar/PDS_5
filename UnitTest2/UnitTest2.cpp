#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_5_2_V1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestComplement)
		{
			string setA[]{ "1", "2", "3", "-", "-", "-", "-", "-" };
			vector<string> result = getComplement(setA);
			vector<string> expected = { "4", "5", "6", "7", "8" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestIntersection)
		{
			string setA[]{ "1", "2", "3", "-", "-", "-", "-", "-" };
			string setB[]{ "1", "2", "3", "4", "5", "-", "-", "-" };
			vector<string> result = getIntersection(setA, setB);
			vector<string> expected = { "1", "2", "3" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestUnion)
		{
			string setA[]{ "1", "2", "3", "-", "-", "-", "-", "-" };
			string setB[]{ "1", "2", "3", "4", "5", "-", "-", "-" };
			vector<string> result = getUnion(setA, setB);
			vector<string> expected = { "1", "2", "3", "4", "5" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestSymmetricDifference)
		{
			string setA[]{ "1", "2", "3", "-", "-", "-", "-", "-" };
			string setB[]{ "1", "2", "3", "4", "5", "-", "-", "-" };
			vector<string> result = getSymmDiff(setA, setB);
			vector<string> expected = { "4", "5" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestDifference)
		{
			string setA[]{ "1", "2", "3", "-", "-", "-", "-", "-" };
			string setB[]{ "1", "2", "3", "4", "5", "-", "-", "-" };
			vector<string> result = getDifference(setA, setB);
			vector<string> expected = { };
			Assert::IsTrue(result == expected);
		}
	};
}
