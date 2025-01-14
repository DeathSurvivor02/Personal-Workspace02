#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	
	ofstream lottery{"lottery.txt", ios::out};
	int count = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)	
		{
			for (int k = 1; k <= 10; k++)
			{
				for (int l = 1; l <= 10; l++)
				{
					for (int m = 1; m <= 10; m++)
					{
						for (int n = 1; n <= 10; n++)
						{
							if (i == j || i == k || i == l || i == n || i == m || j == k || j == n || j == l || j == m || k == m || k == l || k == n || m == n || m == l || n == l)
							{
								continue;
							}
							else
							{
								if (i > j || i > k || i > l || i > m || i > n || j > k || j > l || j > m || j > n || k > l || k > m || k > n || l > m || l > n || m > n)
								{
									continue;
								}
								else
								{ 
									lottery << count++ << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << " " << std::endl;
									// std::cout << count << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << std::endl;
								}
							}
						}
					}
				}
			}
		}
	}
	

	std::cout << rand() % (count+1-0) + 0 <<  std::endl;
	std::cout << count;
}