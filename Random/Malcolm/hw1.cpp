#include <iostream>

using namespace std;

int cars;
char reply;
char type;
int repeat;
int CostFee;

int sedan;

void SUV(int CostFee = 0)
{
	cout << "\n To tune up a SUV is Y. To regular sedan a is N. Y/N? \n";
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
	cout << "\n Your total cost for your car is $ \n" << CostFee;
}

void sedan(int CostFee = 0)
{
	cout << "\n Car Valets pricing strategy for an SUV is Y. For a regular sedan is N. Y/N? \n";
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
	cout << "\n Your total Insurance for your car is $ \n" << CostFee;
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

	cout << "\n Your total Insurance for your car is $ \n" << CostFee;
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
	cout << "\n Your total Insurance for your car is $ \n" << CostFee;
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
		cout << "\t \t \t \t \t Hello please enter your car type? \n";
		cout << "\n 1. SUV";
		cout << "\n 2. Sedan";
		cin >> type;

		if (type == "SUV")
		{
			SUV();
		}
		if (type == "sedan")
		{
			Sedan();
		}
		if (type != "SUV" && type != "sedan")
		{
			cout << "\n ERROR INVALID CAR\n";
		}
		cout << "\n Do you want to tune up another car Y/N?\n";
		cin >> repeat;
	} while (repeat == 'Y');
	return 0;
}