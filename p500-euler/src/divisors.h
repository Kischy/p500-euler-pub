#pragma once


#include "../external/InfInt.h"

#include <algorithm>
#include <functional>

#include "expnum.h"
#include "math_helper.h"
#include "primenumbers.h"




/*
This class is based on the paper: M. E. Grost, The American Mathematical Monthly 1968, 75, 725.
For problem 500 of project euler Theorem 4 is most relevant.
A pdf of the paper is saved with the project.
*/



class Divisors
{
public:



	InfInt lowest_number_for_prime_power_of_2(std::vector<ExpNum>& prime_factorization)
	{
		if (prime_factorization.empty()) return 0;
		if (is_low_fac(prime_factorization)) return 1;	


		return find_lowest_prime_power(prime_factorization);
	}



	//Is public so other classes can use it
	PrimeNumbers prime_numbers;


private:


	//Functions to find the lowest possible number with d divisors for d values that are prime powers

	InfInt find_lowest_prime_power(const std::vector<ExpNum>& prime_factorization) 
	{
		std::vector<unsigned long long> g_values;
		get_g_values(prime_factorization, g_values);

		InfInt lowest = 1;

		for (const unsigned long long num : g_values) lowest *= num;

		return lowest;
	}

	void get_g_values(const std::vector<ExpNum>& prime_fac, std::vector<unsigned long long>& g_vals_out) 
	{
		unsigned long long n = 1, g_max = 1, i = 1, l = 1, g_out = 1;
		
		get_n(n, prime_fac);

		prime_numbers.calc_primes_until_position(n);

		//std::cout << n << "\n";
		//This is just a approximation
		g_vals_out.reserve(2*n);

		get_g_max(g_max, n);

		for (i = 1; i <= n; ++i)
		{
			for (l = 1; l <= n; ++l)
			{
				calc_g_value(g_out, i, l);

				if (g_out > g_max) break;
				g_vals_out.push_back(g_out);
			}
		}

		sort_and_cut_vector(g_vals_out, n);
	}

	void sort_and_cut_vector(std::vector<unsigned long long>& g_vals, const unsigned long long n)
	{
		std::sort(g_vals.begin(), g_vals.end());
		g_vals.resize(n);
	}

	void calc_g_value(unsigned long long& g_out, const unsigned long long i, const unsigned long long l)
	{
		g_out = helper::long_Pow(prime_numbers.get_prime(i), helper::long_Pow(2, l - 1));
	}

	void get_g_max(unsigned long long& max_out, const unsigned long long n) 
	{
		//max1 = 2^[(q-1)*q^n]
		//unsigned long long max1 = helper::long_Pow(2, (q - 1)*helper::long_Pow(q, n));

		//max2 = prime(n+1)^(q-1)
		unsigned long long max2 = prime_numbers.get_prime(n+1);
		max_out = max2;
		/*
		if (max1 < max2) max_out = max1;
		else max_out = max2;
		*/

	}

	void get_n( unsigned long long& n_out, const std::vector<ExpNum>& prime_factorization) const
	{
		n_out = prime_factorization.at(0).exponent;
	}



	inline bool is_low_fac(const std::vector<ExpNum>& prime_factorization) const
	{
		if (prime_factorization.at(0).base == 1) return true;

		return false;
	}



	//Functions to find the lowest possible number with d divisors  

};









