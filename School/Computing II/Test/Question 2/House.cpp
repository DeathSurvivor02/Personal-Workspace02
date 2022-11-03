#include "House.h"
#include <stdexcept> 

// using namespace std;

House::House(const std::string address, const int floors, double cost_floor)
{
	set_address(address);
	set_cost_per_floor(cost_floor);
	set_num_of_floors(floors);
};

void House::set_address(std::string address)
{
	Address = address; 
}

void House::set_cost_per_floor(double cost_floor)
{
	Cost_per_floor = cost_floor;
}

void House::set_num_of_floors(int floors)
{
	if(floors < 0)
	{
		throw std::invalid_argument("Please enter a number that is not negative.");
	}
	Num_of_floors = floors;
}

std::string House::get_address() const
{
	return Address;
}

double House::get_cost_per_floor() const
{
	return Cost_per_floor;
}

int House::get_num_of_floors() const
{
	return Num_of_floors;
}

double House::calculatePrice() const
{
	double price;
	price = Num_of_floors * Cost_per_floor;
	return price;
}