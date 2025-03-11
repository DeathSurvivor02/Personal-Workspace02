// #include <iostream>
// #include <fstream>

/**
 * @date: April, 15th 2022
 * @author: Ean Bynoe
 * @brief: Lottery function that counts the number of reoccuring selecting numbers from the 1.1million combinations of random numbers from 1 and 33
 *
 */
/* int main()
{
	int location;
	int result;
	int lot1, lot2, lot3, lot4, lot5, lot6;
	int res1, res2, res3, res4, res5, res6;
	int iterations;
	int resz;
	ifstream open2012{"2012.txt", ios::in};
	ifstream openlottery{"lottery.txt", ios::in};
	ifstream editlottery{"lottery.txt", ios::app};

	while (open2012 >> location >> lot1 >> lot2 >> lot3 >> lot4 >> lot5 >> lot6 >> iterations)
	{
		while (openlottery >> result >> res1 >> res2 >> res3 >> res4 >> res5 >> res6 >> resz)
		{
			if ((lot1 == res1) && (lot2 == res2) && (lot3 == res3) && (lot4 == res4) && (lot5 == res5) && (lot6 == res6))
			{
				editlottery >>
			}
		}
	}


	return 0;
} */

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

	ifstream read2012{"2012.txt", ios::in};
	ifstream read2013{"2013.txt", ios::in};
	ifstream read2014{"2014.txt", ios::in};
	ifstream read2015{"2015.txt", ios::in};
	ifstream read2016{"2016.txt", ios::in};
	ifstream read2017{"2017.txt", ios::in};

	int count = 0;
	int repeating = 0;
	int total = 0;
	struct location
	{
		int var1;
		int var2;
		int var3;
		int var4;
		int var5;
		int var6;
		int var7;
	};

	struct location loc;

	for (int i = 1; i <= 33; i++)
	{
		for (int j = 1; j <= 33; j++)
		{
			for (int k = 1; k <= 33; k++)
			{
				for (int l = 1; l <= 33; l++)
				{
					for (int m = 1; m <= 33; m++)
					{
						for (int n = 1; n <= 33; n++)
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
									repeating = 0;
									ifstream read2012{"2012.txt", ios::in};
									while (read2012 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									ifstream read2013{"2013.txt", ios::in};
									while (read2013 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									ifstream read2014{"2014.txt", ios::in};
									while (read2014 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									ifstream read2015{"2015.txt", ios::in};
									while (read2015 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									ifstream read2016{"2016.txt", ios::in};
									while (read2016 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									ifstream read2017{"2017.txt", ios::in};
									while (read2017 >> loc.var1 >> loc.var2 >> loc.var3 >> loc.var4 >> loc.var5 >> loc.var6 >> loc.var7)
									{
										if ((loc.var1 == i) && (loc.var2 == j) && (loc.var3 == k) && (loc.var4 == l) && (loc.var5 == m) && (loc.var6 == n))
										{
											repeating++;
											total += repeating;
										}
									}
									lottery << count++ << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << " " << repeating << std::endl;
									std::cout << count << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << std::endl;
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout << rand() % (count + 1 - 0) + 0 << std::endl;
	std::cout << count;
	std::cout << total;
}