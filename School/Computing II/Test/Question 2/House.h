#ifndef HOUSE_H
#define HOUSE_H

#include <string>

class House
{
public:
	House(const std::string , const int, double);

	void set_address(std::string);
	std::string get_address() const;
	
	void set_num_of_floors(int);
	int get_num_of_floors() const;
	
	void set_cost_per_floor(double);
	double get_cost_per_floor() const;
	
	double calculatePrice() const;

private:

	std::string Address;
	int Num_of_floors;
	double Cost_per_floor;
};

#endif