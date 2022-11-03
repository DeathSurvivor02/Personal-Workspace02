#include <iostream>

using namespace std;

int recurse(int large);

int main()
{
	int value = 0;
	int left = 0;
	std::cout << "Enter a value larger than 10\n";
	std::cin >> value;
	while (value <= 10)
	{
		std::cout << "The value is " << value << "is smaller than 10. Enter another value.\n" << std::endl;
		std::cin >> value;
	}
	left = recurse(value);
	std::cout << std::endl << left;
	return 0;
}

int recurse(int large)
{
	int result = 0;
	if (result <= 5)
	{
		return 5; //TODO don't understand here;
	}
	else
	{
		 /* result = */ 
		return result * recurse(large - 1); 
	}
}