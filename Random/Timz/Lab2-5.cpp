#include <iostream>

using namespace std;

int main()
{
	int num1;
	cout << "Please enter a number\n";
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "\n\n\n";
	for (int i = 0; i < num1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << "\n\n\n";

	for (int i = 0; i < num1; i++)
	{
		for (int j = num1; j > i; j--)
		{
			cout << "* ";
		}
		cout << endl;
	}

/* 	cout << "\n\n\n";
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			
			cout << "* ";
		}
		cout << endl;
	}
 */
	return 0;
}
