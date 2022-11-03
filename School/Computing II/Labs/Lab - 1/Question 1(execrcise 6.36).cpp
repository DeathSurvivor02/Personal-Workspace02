

#include <iostream>


// using namespace std;
int power(int base, int exponent);


int main()
{
	int num1 = 0, num2 = 0;
	int value;
	std::cout << "Please enter 2 numbers to find the exponent\n";
	std::cin >> num1 >> num2;
	value = power(num1, num2);
	std::cout << value << std::endl; //Question 1(exercise 6.36).cpp:
	return 0;

}

int power(int base, int exponent)
{

	if (exponent == 1)
	{
		return base;
	}
	else
	{
		// base = base * base
		return base * power(base, exponent - 1);
	}
}

/* 2^4

2 *(2^3)
2 * 2 *(2^2)
2 * 2 *(2^1)
2 * 2 *(2^0) */


// 2 * (2,4)
// 2 * 2 * (2,4)
