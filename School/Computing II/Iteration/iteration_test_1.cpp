#include <iostream>

int main()
{
	int x =0, y=0;
	int sum = 0;
	start:
	std::cout<< "Please enter 2 numbers where the first number is smaller than the second number\n";
	std::cin >> x >> y;
	if (x > y)
	{
		goto start;
	}
	for (int i = x; i<=y; i++)
	{
		sum += i;
	}
	std::cout << sum << std::endl;

	return 0;
}