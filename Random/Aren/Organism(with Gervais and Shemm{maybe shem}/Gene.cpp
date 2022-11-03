#include <random>
#include <iostream>
#include "Environment.h"
using namespace std;

// uh idk

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

void Environment::iteration()
{
	for (int i = 1; i< 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			environment[i][]
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
	uniform_int_distribution<> dist(0, 6);
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
	cout << "Column " << j << " was changed.";
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