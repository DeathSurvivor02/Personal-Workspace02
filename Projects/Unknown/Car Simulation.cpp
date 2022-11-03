/**
 * @file Car Simulation.cpp
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:
 * @version 1.0
 * @date 2022-05-20 09:23:49
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

// class: The FuelGuage
//  todo:
/**
 * know the car's curent amount of fuel, in gallons(assuming for americans)/ in litres (assuming for remaining of the world)
 * report the car's current amount of fuel, in gallons
 * able to increment the amount of fuel by 1 unit. this simulates putting fuel into the car. ( have  a maximum of 15 gallons //fixme might change to more than 15)
 * able to decrement the amount of fuel by 1 unit, once the car is above 0 units of fuel. this simulates the car burning fuel
 */

// class: The Odometer
//  todo:
/**
 * know the car's current millage
 * report the car's current millage
 * be able to increment the millage by 1 unit(mile/km). the maximum mileage the Odometer can store is 999,999 miles/kms. when this amount is exceeded, the odometer will reset to 0
 * to be able to work with the fuelgauge object. it should decrease the fuelgauge object's current amount of fuel by 1 gallon every 24 miles/kms travelled.(the car's fuel economy i 24 miles per unit)
 *
 */

class FuelGuage
{
public:
	FuelGuage();
	int fuel;

private:
	const int max_fuel = 15;
	void update_fuel();
	void report_fuel();
	void increment_fuel();
	void decrement_fuel();
};

void FuelGuage::increment_fuel()
{
	if (fuel >= 15)
	{
		std::cout << "The car cannot take any more fuel." << std::endl;
	}
	else
	{
		fuel += 1;
	}
}

void FuelGuage::report_fuel()
{
	std::cout << "Odometer : " << fuel << std::endl;
}

void FuelGuage::decrement_fuel()
{
	if (fuel < 0)
	{
		std::cout << "The car no longer has enough fuel." << std::endl;
	}
	else
	{
		fuel -= 1;
	}
}

class Odometer
{
	float millage;	
	void report_millage();
	void increment_millage();
	void decrement_millage();


};