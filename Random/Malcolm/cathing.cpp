#include <iostream>
#include <stdlib.h>
using namespace std;

int Tune_up(int opt);		 // gives the price of the tune-up according to the vehicle
int Valet(int opt);			 //
float Gas_filling(int opt); //
void Vehicle_type(int opt);	 // ask for the type of vehicle
void Complete_transaction(int a, int b, float c);
int cost = 0;
int Tune_up(int opt)
{
	// char vehicle;
	if (opt == 1)
	{
		cost = 150;
	}
	if (opt == 2)
	{
		cost = 200;
	}
	return cost;
}
int Valet(int opt)
{
	int valet = 0;
	if (opt == 1)
	{
		valet = 30;
	}
	if (opt == 2)
	{
		valet = 40;
	}
	return valet;
}
float Gas_filling(int opt)
{
	double gas_total;
	int gas_amount;
	float gas_type;
	char type_gas;
	cout << "How much gas would you like?\n";
	cin >> gas_amount;
	cout << "What type of gas would you like?\n";
	cout << "R for Regular gas at $1.48\n";
	cout << "U for Unleashed gas at $1.10\n";
	cout << "D for Diesel gas at $1.40\n";
	cin >> type_gas;
	if (type_gas == 'R')
	{
		gas_type = 1.48;
	}
	if (type_gas == 'U')
	{
		gas_type = 1.10;
	}
	if (type_gas == 'D')
	{
		gas_type = 1.40;
	}
	gas_total = gas_amount * gas_type;
	if ((cost > 0) && (gas_total > 50.00))
	{
		gas_total = gas_total * 0.9;
	}
	return gas_total;
}
void Complete_transaction(int a, int b, float c)
{
	float total = a + b + c;
	cout << "Tune Up Costs: " << a << endl;
	cout << "Valet Costs: " << b << endl;
	cout << "Gas Fill Up Costs: " << c << endl;
	cout << "Total Costs: " << total << endl;
}

int main()
{
	// char type;
	int opt;
	char service;
	int valet;
	int tune;
	float gas;
	char answer;

		cout << "Choose a type of vehicle\n";
		cout << "1. Regular Sedan\n";
		cout << "2. Sedan\n";
		cin >> opt;
	do	{
		cout << "Enter a service option for the vehicle\n";
		cout << "A. Tune Up\n";
		cout << "B. Car Valet\n";
		cout << "C. Gas Fill Up\n";
		cout << "D. Complete Transaction\n";
		cout << "E. Exit\n";
		cout << "What is your selection?\n";
		cin >> service;
		if (service == 'A')
		{
			tune = Tune_up(opt);
		}
		if (service == 'B')
		{
			valet = Valet(opt);
		}
		if (service == 'C')
		{
			gas = Gas_filling(opt);
		}
		if (service == 'D')
		{
			Complete_transaction(tune, valet, gas);
		}
		if (service == 'E')
		{
			exit(0);
		}
		cout << "Do you wish to do something else with you vehicle? (Y/N)\n";
		cin >> answer;
	} while (answer == 'Y');
	return 0;
}