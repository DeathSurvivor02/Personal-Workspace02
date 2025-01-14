/**
 * @file Environment.cpp
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:  
 * @version 1.0
 * @date 2022-10-07 09:24:10
 * 
 * @copyright Copyright (c) 2022
 *   
 */

#include <random>
#include <iostream>
#include "Environment.h"
using namespace std;

void Environment::grid_0()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 2);

	for (int i = 0; i < 10; i++) // column
	{
		for (int j = 0; j < 10; j++) // row
		{

			int ean = dist(gen);
			environment[i][j] = 0;

			cout << environment[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n\n\n";
}

// random grid generation
void Environment::random_gen()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	for (int count = 0; count < 30; count++)
	{
		int i = dist(gen);
		int j = dist(gen);
		if (environment[i][j] != 1)
		{
			environment[i][j] = 1;
		}
		else
		{
			int i = dist(gen);
			int j = dist(gen);
			environment[i][j] = 1;
		}
	}
}

// program iteration, runs 5 times
void Environment::iteration()
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if ((environment[i + 1][j] + environment[i - 1][j] + environment[i][j + 1] + environment[i][j - 1]) > 2)
			{
				environment[i][j] = 1;
			}
			else // if not
			{
				environment[i][j] = 0;
			}
		}
	}
}

// Mutations
void Environment::increment()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int i = dist(gen);
	// cout << i << endl;
	for (int j = 0; j < 10; j++) // row
	{
		environment[i][j] += 1;
		if (environment[i][j] > 2)
		{
			environment[i][j] = 0;
		}
	}
}

void Environment::cross_merge()
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	// uniform_int_distribution<> dist1(0, 6);
	int temp[9];
	int num1 = dist(gen);
	int num2 = dist(gen);
	while (num1 == num2)
	{
		int num1 = dist(gen);
		int num2 = dist(gen);
	}
	for (int i = 0; i < 6; i++)
	{
		temp[i] = environment[num1][i];
		environment[num1][i] = environment[num2][i];
		environment[num2][i] = temp[i];
	}
}

void Environment::rotate()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9); // randomly select column
	int j = dist(gen);
	for (int i = 0; i < 9; i++)
	{
		if (environment[i][j] == 0)
		{
			environment[i][j] = 1;
		}
		else if (environment[i][j] == 1)
		{
			environment[i][j] = 2;
		}
		else if (environment[i][j] == 2)
		{
			environment[i][j] = 0;
		}
	}
	cout << "Column " << j << " was changed.\n";
}

void Environment::reverse()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int temp[9];
	int num = dist(gen);
	for (int j = 0; j < 9; j++)
	{
		temp[j] = environment[num][j];
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 9; i > 0; i--)
		{
			environment[num][j] = temp[i];
		}
	}
}

void Environment::geneflip()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	uniform_int_distribution<> dist1(0, 2);
	int num = dist(gen);
	int num1 = dist(gen);
	int num2 = dist1(gen);
	environment[num][num1] = num2;

	cout << " Column " << num << "Row " << num1 << " was changed to " << num2 << endl;
}

void Environment::replace()
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	uniform_int_distribution<> dist1(0, 2);
	int i = dist(gen);
	int ran = dist1(gen);
	bool pass = true;
	int count = 0;
	for (int j = 0; j < 9; j++)
	{
		environment[i][j] = 0;
	}
	while (count < 5)
	{
		while (environment[i][ran] != 1)
		{
			environment[i][ran] = 1;
		}
		if (environment)
			count++;
	}
}

void Environment::swap()
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int temp[9];
	int randrow = dist(gen);
	int randrow2 = dist(gen);

	for (int j = 0; j < 9; j++)
	{
		temp[j] = environment[randrow][j];
		environment[randrow][j] = environment[randrow2][j];
		environment[randrow2][j] = temp[j];
	}
	cout << " Rows " << randrow << " and " << randrow2 << " were swapped " << endl;
}

void Environment::print()
{

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; ++j)
		{
			cout << environment[i][j] << "\t";
		}
		cout << endl; // here
	}
}

int main()
{
	Environment envi;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 7);
	int count = 5;
	envi.grid_0();
	envi.random_gen();
	envi.print();
	cout << endl;
	int mute = dist(gen);
	cout << mute << endl;
	for (int i = 0; i < 5; i++)
	{

		switch (dist(gen))
		{
		case 1:
			envi.increment();
			envi.print();
			cout << endl;
			break;

		case 2:
			envi.cross_merge();
			envi.print();
			cout << endl;
			break;

		case 3:
			envi.rotate();
			envi.print();
			cout << endl;
			break;

		case 4:
			envi.reverse();
			envi.print();
			cout << endl;
			break;

		case 5:
			envi.geneflip();
			envi.print();
			cout << endl;
			break;

		case 6:
			envi.replace();
			envi.print();
			cout << endl;
			break;

		case 7:
			envi.swap();
			envi.print();
			cout << endl;
			break;

		default:
			envi.print();
			cout << endl;
		}

		// count = count--;
		// int mute = dist(gen);
	}
	return 0;
}
