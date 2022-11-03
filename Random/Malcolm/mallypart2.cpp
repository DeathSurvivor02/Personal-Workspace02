#include <iostream>

using namespace std;

int main()
{
	float quant;
	int unit;
	int total_purchase = 0;
	cout << "Please enter the quantity of the items\n";
	cin >> quant;
	cout << "Please enter the unit of the items\n";
	cin >> unit;
	total_purchase = quant * unit;
	cout << "Please the total price is " << total_purchase << "\n";
	if (total_purchase < 100)
	{
		cout << "You didn't win anything\n";
	}
	if ((total_purchase >= 100) && (total_purchase < 500))
	{
		cout << " You get A key ring!\n";
	}
	else if ((total_purchase >= 500) && (total_purchase < 1000))
	{
		cout << " You get a leathure purse!\n";
	}
	else if ((total_purchase > 1000))
	{
		cout << " You get a cellular phone!\n";
	}
	return 0;
}