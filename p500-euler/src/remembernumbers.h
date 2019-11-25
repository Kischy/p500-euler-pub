#pragma once

#include "iremembernumbers.h"

#include <unordered_map>
#include <functional>


template <typename T_key, typename T_value>
class RememberNumbers : public IRememberNumbers<typename T_key, typename T_value>
{
public:
	RememberNumbers(std::function<T_value(T_key)> test_key_function)
	{
		test_number_key_function = test_key_function;
	}

	virtual T_value calc_and_get_number(T_key num_key) override
	{
		if (number_has_been_saved(num_key)) return get_number(num_key);


		T_value num_val = test_number_key_function(num_key);
		save_number(num_key, num_val);

		return num_val;
	}


	void save_number(T_key num_key, T_value num_value)
	{
		if (!number_has_been_saved(num_key))
		{
			saved_numbers.insert({ num_key,num_value });
		}
	}

	T_value get_number(T_key num_key) const
	{
		auto it = saved_numbers.find(num_key);
		return it->second;
	}

	bool number_has_been_saved(T_key num_key) const
	{
		auto it = saved_numbers.find(num_key);

		return it == saved_numbers.end() ? false : true;
	}

	
	void reserve(size_t n)
	{
		saved_numbers.reserve(n);
	}
	

private:
	std::function<T_value(T_key)> test_number_key_function;
	std::unordered_map<T_key, T_value> saved_numbers;


};

