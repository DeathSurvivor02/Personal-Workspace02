#include <stdexcept>
#include "Mansion.h"

Mansion::Mansion(const std::string address, const int floors, double cost_floor, double pool, double luxury) : House(address, floors, cost_floor)
{
	set_luxury(luxury);
	set_pool(pool);
}

void Mansion::set_pool(double pool)
{
	if (pool < 0)
	{
		throw std::invalid_argument("Please enter a numver larger than 0");
	}

	Pool = pool;
}

void Mansion::set_luxury(double luxury)
{
	if (luxury < 0)
	{
		throw std::invalid_argument("Please enter a numver larger than 0");
	}
	luxury = luxury;
}

double Mansion::get_pool() const
{
	return Pool;
}

double Mansion::get_luxury() const
{
	return Luxury;
}

double Mansion::calculatePrice() const
{
	double price;
	price = (Mansion::get_num_of_floors() * (Mansion::get_cost_per_floor() + get_luxury())) + get_pool();
	return price;
}