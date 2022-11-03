#include <iostream>
// #include <string>
#include <ctime>
// #include <cmath>
// #include <fstream>
using namespace std;
// #include <bits/stdc++.h>

// generate 6 numbers from 1 to 31 and store unrepeated numbers in a file.
//  if the numbers are generated those numbers will not be placed in the file.

// void gennumbers();

struct winning
{
	int num[6];
};

int main()
{

	srand(time(NULL));
	int possibilities = 906192; 
	struct winning win[906192];
	// bool ps1[6] = {false, false, false, false, false, false};
	for (int i = 0; i < possibilities; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			win[i].num[j] = rand() % 31 + 1;
			// std::cout << win[i].num[j];
			/*

			while ((ps1[0] == false) && (ps1[1] == false) && (ps1[2] == false) && (ps1[3] == false) && (ps1[4] == false) && (ps1[5] == false))
						{
							for (int k = 0; k < 6; k++)
							{
								while (ps1[k] == false)
								{
									for (int y = 0; y < k; i++)
									{
										while (win[i].num[j] == win[i].num[y])
										{
											win[i].num[j] = rand() % 31 + 1;
										}
									}
									ps1[k] = true;
								}
							}
						}

			 */
			std::cout << std::endl;
		}
	}
	for (int i = 0; i < possibilities; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << win[i].num[j];
		}
		std::cout << std::endl;
	}
	std::cout << possibilities << std::endl;
}