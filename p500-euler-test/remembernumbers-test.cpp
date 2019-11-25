#include "pch.h"


class RememberNumbersCheckerInt : public testing::Test
{
public:
	RememberNumbers<int, int> remembersnumbers_intint{ [](int a) {return a + 1; } };
};

class RememberNumbersCheckerLongLongBool : public testing::Test
{
public:
	RememberNumbers<long long, bool> remembersnumbers_longlong_bool{ [](long long a) {return true; } };
};





TEST_F(RememberNumbersCheckerInt, EmptyClassHasNoNumberSaved) {
	ASSERT_FALSE(remembersnumbers_intint.number_has_been_saved(0));
}

TEST_F(RememberNumbersCheckerLongLongBool, NumberHasBeenSaved) {

	remembersnumbers_longlong_bool.save_number(1, true);
	ASSERT_TRUE(remembersnumbers_longlong_bool.number_has_been_saved(1));
	ASSERT_FALSE(remembersnumbers_longlong_bool.number_has_been_saved(2));
}

TEST_F(RememberNumbersCheckerInt, GetsSavedNumber) {

	remembersnumbers_intint.save_number(-10, -2000);
	ASSERT_EQ(remembersnumbers_intint.get_number(-10), -2000);
}


TEST_F(RememberNumbersCheckerInt, CalcNumberAccordingToLambdaAndSaveIt) {

	remembersnumbers_intint.calc_and_get_number(1);
	ASSERT_EQ(remembersnumbers_intint.get_number(1), 2);
	ASSERT_TRUE(remembersnumbers_intint.number_has_been_saved(1));
}



//Public functions
TEST_F(RememberNumbersCheckerInt, CalcAndGetNumberAccordingToLambda) {
	ASSERT_EQ(remembersnumbers_intint.calc_and_get_number(1), 2);
	ASSERT_EQ(remembersnumbers_intint.calc_and_get_number(10), 11);
	ASSERT_EQ(remembersnumbers_intint.calc_and_get_number(1), 2);

}

TEST_F(RememberNumbersCheckerLongLongBool, CalcAndGetNumberAccordingToLambda) {
	ASSERT_EQ(remembersnumbers_longlong_bool.calc_and_get_number(1), true);

}








