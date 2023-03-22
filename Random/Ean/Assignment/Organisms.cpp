#ifndef __Organisms__H__
#define __Organisms__H__
#include "Organism Simulator.h"
#include <iostream>
#include <string>
#include <header>

using namespace std;

void Organism_Sim::random_gen()
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

void Organism_Sim::increment()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int i = dist(gen);
	// std::cout << i << endl;
	for (int j = 0; j < 10; j++) // row
	{
		environment[i][j] += 1;
		if (environment[i][j] > 2)
		{
			environment[i][j] = 0;
		}
	}
}

void Organism_Sim::cross_merge()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	uniform_int_distribution<> dist1(0, 6);
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

void Organism_Sim::rotate()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9); // randomly select column
	int i = dist(gen);
	for (int j = 0; j < 9; j++)
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
	std::cout << "Column " << i << " was changed.";
}

void Organism_Sim::Reverse()
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

void Organism_Sim::GeneFlip()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	uniform_int_distribution<> dist1(0, 2);
	int num = dist(gen);
	int num1 = dist(gen);
	int num2 = dist1(gen);
	environment[num][num1] = num2;

	std::cout << " Column " << num << "Row " << num1 << " was changed to " << num2 << std::endl;
}

void Organism_Sim::Replace()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	uniform_int_distribution <> dist1(0, 2); 
	int i = dist(gen);
	int ran = dist1(gen);
	bool pass = true;
	int count = 0; 
	for (int j = 0; j < 9; j++)
	{
		environment[i][j] = 0;

	}
	while(count < 5)
	{
		while(environment[i][ran] != 1)
		{
			environment[i][ran] = 1;
		}
		if (environment)
		count++;
	}


}

void Organism_Sim::Swap()
	{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int temp[9];
	int randCol = dist(gen);
	int num;

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
	std::cout << " Rows " << i <<
	
	}


#endif