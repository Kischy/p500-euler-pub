#pragma once

#include "primechecker.h"




class PrimeNumbers
{
public:


	unsigned long long get_prime(const unsigned long long position)
	{
		return remember_primes_and_positions.calc_and_get_number(position);
	}


	//This function has not tests - if you ever use this class again, than incl
	void calc_primes_until_position(const unsigned long long position)
	{
		save_primes_until_position(position);
	}

	//A function that calculates the primes until a certain max number should use the sieve alhorithm. If ever needed, implement here.
	//void calc_primes_until(const unsigned long long number);

	//Is public so other classes can use it
	PrimeChecker primechecker;

private:
	RememberNumbers<unsigned long long, unsigned long long> remember_primes_and_positions{ std::bind(&PrimeNumbers::get_prime_at_position, this,std::placeholders::_1) };


	unsigned long long get_prime_at_position(const unsigned long long position)
	{
		if (is_position_to_low(position)) return 0;

		unsigned long long prime_at_pos = 2, current_position = 0;

		while (current_position < position)
		{
			if (primechecker.is_prime_number(prime_at_pos))
			{
				current_position++;

				if (current_position == position)
				{
					return prime_at_pos;
				}
			}

			prime_at_pos++;
		}
	
		return 0;
	}


	void save_primes_until_position(const unsigned long long until_pos)
	{
		if (is_position_to_low(until_pos)) return;

		remember_primes_and_positions.reserve(size_t(until_pos));

		unsigned long long prime_at_pos = 2, current_position = 0;
		

		while (current_position < until_pos)
		{
			if (primechecker.is_prime_number(prime_at_pos))
			{
				current_position++;
				
				remember_primes_and_positions.save_number(current_position, prime_at_pos);
			}

			prime_at_pos++;
		}


	}

	

	bool is_position_to_low(const unsigned long long position)
	{
		if (position <= 0) return true;

		return false;
	}



};



