

#include <iostream>

#include "src/math_helper.h"
#include "src/divisors.h"

#include <memory>

//#include "external/unsigned long long.h"




int main(int argc, char **argv)
{

	std::cout << "Calculation started" << std::endl;

	InfInt p500_answ = 1;

	//Divisors div;

	std::unique_ptr<Divisors> div = std::make_unique<Divisors>();

	std::vector<ExpNum> factorization;
	factorization.push_back(ExpNum{ 2,500500 });

	//factorization = div->prime_factorize.factorize_exponent(102);

	p500_answ = div->lowest_number_for_prime_power_of_2(factorization);

	//std::cout << "The number without modulo:\n" << p500_answ << std::endl;
	std::cout << "=============================================\n" << std::endl;

	InfInt toModulo = 500500507;
	p500_answ = p500_answ % toModulo;

	std::cout << "The answer to the 500th problem of ProjectEuler.Net is:\n" << p500_answ << std::endl;

	return 0;
}


