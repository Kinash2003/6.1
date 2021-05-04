#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1/Array.h"
#include "../6.1/Array.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array unitTest = Array(20);

			for (int i = 0; i < 20; i++)
				unitTest[i] = 0;
			unitTest[10] = -5;

			Assert::AreEqual(unitTest.Number(), -5.);
		}
	};
}
