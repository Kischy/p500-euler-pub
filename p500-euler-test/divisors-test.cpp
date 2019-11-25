#include "pch.h"





class FindNumbersOfDivisorsViaFactorizationTesting : public testing::Test
{
public:
	Divisors divisors;
};


TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, LowestNumberWith_prime_power_2_to_4_Divisors)
{
	unsigned long long lowest_2_to_4_divisors = 120;
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>{ExpNum{ 2,4 }}), lowest_2_to_4_divisors);
}

TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, LowestNumberWith_prime_power_2_to_3_Divisors)
{
	unsigned long long lowest_2_to_3_divisors = 24;
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>{ExpNum{ 2,3 }}), lowest_2_to_3_divisors);
}

TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, LowestNumberWith_4_Divisors)
{
	unsigned long long LowestNumberWith_4_Divisors = 6;
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>{ExpNum{ 2,2 }}), LowestNumberWith_4_Divisors);
}

TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, LowestNumberWith_2_Divisors)
{
	unsigned long long lowest_2_divisors = 2;
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>{ExpNum{ 2,1 }}), lowest_2_divisors);
}


TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, ReturnZeroOnEmptyVec)
{
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>()), unsigned long long(0));
}


TEST_F(FindNumbersOfDivisorsViaFactorizationTesting, LowestNumberWith_1_Divisor)
{
	ASSERT_EQ(divisors.lowest_number_for_prime_power_of_2(std::vector<ExpNum>{ExpNum{ 1,1 }}), unsigned long long(1));
}



