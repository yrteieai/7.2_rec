#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2_rec/7.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:

		TEST_METHOD(TestFindMinMaxInRow)
		{
			int row[5] = { 1, -4, 8, 3, 0 };
			int minIdx = 0;
			int maxIdx = 0;

			FindMinMaxInRow(row, 5, 1, minIdx, maxIdx);

			Assert::AreEqual(1, minIdx, L"Min index is incorrect.");
			Assert::AreEqual(2, maxIdx, L"Max index is incorrect.");
		}

		TEST_METHOD(TestSwapMinMaxInRow)
		{
			int row[5] = { 1, -4, 8, 3, 0 };
			int minIdx = 1; 
			int maxIdx = 2;

			SwapMinMaxInRow(row, minIdx, maxIdx);

			Assert::AreEqual(8, row[minIdx], L"Min element not swapped correctly.");
			Assert::AreEqual(-4, row[maxIdx], L"Max element not swapped correctly.");
		}

		TEST_METHOD(TestProcessRows)
		{

			int** a = new int* [2];
			a[0] = new int[3] { 1, 9, -5 };
			a[1] = new int[3] { 3, 4, 7 };

			ProcessRows(a, 2, 3, 0);

			Assert::AreEqual(-5, a[0][1], L"Max element not swapped correctly in row 0.");
			Assert::AreEqual(9, a[0][2], L"Min element not swapped correctly in row 0.");

			Assert::AreEqual(7, a[1][0], L"Element in row 1 not correct.");
			Assert::AreEqual(4, a[1][1], L"Element in row 1 not correct.");
			Assert::AreEqual(3, a[1][2], L"Element in row 1 not correct.");

			for (int i = 0; i < 2; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
