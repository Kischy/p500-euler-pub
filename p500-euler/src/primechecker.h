#pragma once


#include "remembernumbers.h"
#include "math_helper.h"


class PrimeChecker
{
public:
	bool is_prime_number(const unsigned long long number)
	{
		return remember_primes.calc_and_get_number(number);
	}

	static bool is_prime_number_static(const unsigned long long number)
	{
		return PrimeChecker::is_prime(number);
	}


	
private:
	RememberNumbers<unsigned long long, bool> remember_primes{ &PrimeChecker::is_prime };


	static bool is_prime(const unsigned long long number)
	{
		if (number <= 3) return numbers_until_three(number);

		return is_a_prime_higher_three(number);
	}


	static bool numbers_until_three(const unsigned long long number)
	{
		if (number == 2 || number == 3) return true;

		return false;
	}


	static bool is_a_prime_higher_three(const unsigned long long number)
	{
		unsigned long long upper = get_upper_limit(number);

		for (unsigned long long i = 2; i <= upper; ++i)
		{
			if (helper::is_divisable(number, i)) return false;
		}

		return true;
	}

	static unsigned long long get_upper_limit(const unsigned long long number)
	{
		//return number.intSqrt();
		return static_cast<unsigned long long>(std::sqrt(number) + 1);
	}





};



