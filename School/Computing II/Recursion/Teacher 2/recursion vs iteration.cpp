#include <iostream>

// interation
/* int iterativeSum(int n)
{
	int result =
} */

// main

int sum(int n);
int main()
{
	sum(5);
	return 0;
}

// recursion (my way _unsure if correctly implemented_)
//  int sum(int n)
//  {
//  	int result = 0;
//  	int i = 0;
//  	if ( i == n )
//  		return result;
//  	}
//  	i++;
//  	return result += sum(n);
//  }

int sum(int n)
{

	int result = 0;
	if (n <= 1)
	{
		std::cout << result;
		return n;
	}
	else
	{
		return result = n + sum(n - 1);
	}
}