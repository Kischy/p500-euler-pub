#include "pch.h"

#include "../p500-euler/src/math_helper.cpp"


namespace hp = helper;


TEST(PowFunctionTest, ReturnsZeroOnZeroBaseCall)
{
	ASSERT_EQ(hp::long_Pow(0, 10), 0);

}

TEST(PowFunctionTest, ReturnsOneOnZeroExponentCall)
{
	ASSERT_EQ(hp::long_Pow(1, 0), 1);
}


TEST(PowFunctionTest, ReturnsZeroOnZeroBaseZeroExponentCall)
{
	ASSERT_EQ(hp::long_Pow(0, 0), 0);
}


TEST(PowFunctionTest, ReturnNumberOnExponentOneCall)
{
	unsigned long long arbitrary_number = 333;
	ASSERT_EQ(hp::long_Pow(arbitrary_number, 1), arbitrary_number);
}


TEST(PowFunctionTest, ReturnsCorrectPow)
{
	unsigned long long arbitrary = 333;
	unsigned long long exponent = 7;
	unsigned long long result = arbitrary * arbitrary *arbitrary *arbitrary *arbitrary * arbitrary *arbitrary;

	ASSERT_EQ(hp::long_Pow(arbitrary, exponent), result);
}

TEST(PowFunctionTest, HandlesNegativeNumbersBaseCorrect)
{
	unsigned long long arbitrary = -333;
	unsigned long long exponent = 7;
	unsigned long long result = arbitrary * arbitrary *arbitrary *arbitrary *arbitrary * arbitrary *arbitrary;

	ASSERT_EQ(hp::long_Pow(arbitrary, exponent), result);
}

