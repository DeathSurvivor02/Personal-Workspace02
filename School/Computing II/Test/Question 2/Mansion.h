#ifndef MANSION_H
#define MANSION_H

#include "House.h"
// #include "House.cpp"

class Mansion : public House
{
public:
	Mansion(const std::string,int, double, double, double);
	void set_pool(double);
	double get_pool() const;

	void set_luxury (double);
	double get_luxury() const;

	double calculatePrice() const;
private:
	double Luxury;
	double Pool;
};

#endif