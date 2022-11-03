#include <iostream>

/* 6.41 (Recursive Greatest Common Divisor) The greatest
common divisor of integers x and y is the largest integer that
evenly divides both x and y . Write a recursive function gcd
that returns the greatest common divisor of x and y , defined
recursively as follows: If y is equal to 0 , then gcd(x, y) is x;
otherwise, gcd(x, y) is gcd(y, x % y) , where % is the
remainder operator. [Note: For this algorithm, x must be larger
than y .] */

int gcd(int x, int y);
int main()
{
	int x = 0;
	int y = 0;
	int great = 0;
	std::cout << "Enter a value for x and a value for y" << std::endl;
	std::cin >> x >> y;
	great = gcd(x, y);
	std::cout << great << std::endl;
	return 0;
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return 0;
	}
	if (x == 0)
	{
		return y;
	}

	if (x < y)
	{
		return -1;
	}

	else if (x > y)
	{
		return gcd(x, x % y);
	}
}


/* int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(x, x % y);
} */
