#include "pch.h"




class PrimeCheckerTesting : public testing::Test
{
public:
	PrimeChecker primechecker;
};

TEST_F(PrimeCheckerTesting, TestIfOneOrZeroIsAPrimeNumber) {
	ASSERT_FALSE(primechecker.is_prime_number(0));
	ASSERT_FALSE(primechecker.is_prime_number(1));
}


TEST_F(PrimeCheckerTesting, TwoIsAPrimeNUmber) {
	ASSERT_TRUE(primechecker.is_prime_number(2));
}

TEST_F(PrimeCheckerTesting, ThreeIsAPrime) {
	ASSERT_TRUE(primechecker.is_prime_number(3));
}


TEST_F(PrimeCheckerTesting, FourIsNotAPrime) {
	ASSERT_FALSE(primechecker.is_prime_number(4));
}

TEST_F(PrimeCheckerTesting, FiveIsAPrime) {
	ASSERT_TRUE(primechecker.is_prime_number(5));
}

TEST_F(PrimeCheckerTesting, AdditionalPrimeNumberTests) {
	ASSERT_TRUE(primechecker.is_prime_number(11));
	ASSERT_TRUE(primechecker.is_prime_number(17));
	ASSERT_FALSE(primechecker.is_prime_number(21));
}

TEST_F(PrimeCheckerTesting, GivesBackFalseForNegativeNumbers) {
	ASSERT_FALSE(primechecker.is_prime_number(-11));
}



TEST(PrimeCheckerStaticTesting, PrimeNumbersTest)
{
	ASSERT_FALSE(PrimeChecker::is_prime_number_static(0));
	ASSERT_FALSE(PrimeChecker::is_prime_number_static(1));
	ASSERT_TRUE(PrimeChecker::is_prime_number_static(11));
	ASSERT_TRUE(PrimeChecker::is_prime_number_static(17));
	ASSERT_FALSE(PrimeChecker::is_prime_number_static(21));
}


TEST(PrimeCheckerStaticTesting, GivesBackFalseForNegativeNumbers)
{
	ASSERT_FALSE(PrimeChecker::is_prime_number_static(-10));
}


