#include <iostream>

using namespace std;
int animaltype;
char reply;
char type;
int repeat;
int CostFee = 0;

void SUV(int CostFee = 0)
{
	cout << "\n To tune up a SUV is Y.To tune up regular sedan a is N. Y/N? \n";
	cin >> reply;

	if (reply == 'Y')
		;
	{
		CostFee = 200;
	}
	if (reply == 'N')
		;
	{
		CostFee = 150;
	}
	cout << "\n Your total Insurance for your pet is $ \n" << CostFee;
}

void sedan(int CostFee = 0)
{
	cout << "\n Car Valets pricing strategy for an SUV Y. Car Valets pricing strategy for an sedan is N. Y/N? \n";
	cin >> reply;

	if (reply == 'Y')
		;
	{
		CostFee = 40;
	}
	if (reply == 'N')
		;
	{
		CostFee = 30;
	}
	cout << "\n Your total Insurance for your pet is $ \n" << CostFee;
}

void Regular()
{
	cout << "regular gas";
	cin >> reply;

	if (reply == 'Y')
		;
	{
		CostFee = 1.48;
	}
	if (reply == 'N')
		;
	{
		CostFee = 0;
	}
}

void Unleaded()
{
	cout << "unleaded gas";
	cin >> reply;

	if (reply == 'Y')
		;
	{
		CostFee = 1.10;
	}
	if (reply == 'N')
		;
	{
		CostFee = 0;
	}
}

void Diesel()
{
	cout << "Diesel gas";
	cin >> reply;

	if (reply == 'Y')
		;
	{
		CostFee = 1.40;
	}
	if (reply == 'N')
		;
	{
		CostFee = 0;
	}
	cout << "\n Your total Insurance for your car is $ \n" << CostFee;
}

int main()
{

	do

	{

		cout << "\t \t \t \t \t Hello World what's your animal type? \n";
		cout << "\n 1. S or s for SUV";
		cout << "\n 2. R or r for regular sedan\n";
		cin >> type;

		if ((type == 'S') || (type == 's'))
		{
			SUV();
		}
		if ((type == 'R') || (type == 'r'))
		{
			sedan();
		}

		if (type != 'S' && type != 'R')
		{
			cout << "\n ERROR INVALID CAR\n";
		}
		cout << "\n Do you want to insure another car Y/N?\n";
		cin >> repeat;
	} while (repeat == 'Y');

	return 0;
}
