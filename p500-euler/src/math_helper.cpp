#include "math_helper.h"


#include <cmath>

namespace helper
{
	unsigned long long long_Pow(const unsigned long long base, const unsigned long long exponent)
	{
		if (base == 0) return 0;
		else if (exponent == 0) return 1;
		else if (exponent == 1) return base;
		else if (exponent < 0) return 0;

		unsigned long long val = base;
		
		// For very high number this should be switched to unsigned long long
		//unsigned long long expo = exponent;

		//std::cout << exponent << "\n";
		unsigned long long a = 1;

		for (unsigned long long i = 2; i <= exponent; ++i)
		{
			val *= base;
		}	

		return val;
	}


	bool is_divisable(const unsigned long long number, const unsigned long long divisor)
	{
		return (number % divisor) == 0;
	}



}

