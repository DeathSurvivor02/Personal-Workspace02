/**
 * @file Organism Simulator.cpp
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:
 * @version 1.0
 * @date 2022-10-05 07:36:28
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @file Organism Simulator.cpp
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:  
 * @version 1.0
 * @date 2023-02-06 09:07:32
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <random>
#include <iostream>
using namespace std;

int environment[10][10];
void increment();
void random_gen();
void cross_merge();
void rotate();


int main()
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

			std::cout << environment[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n";
	random_gen();
	// increment();
	for (int i = 0; i < 10; i++) // column
	{
		for (int j = 0; j < 10; j++) // row
		{
			std::cout << environment[i][j] << "\t";
		}
		std::cout << endl;
	}

	std::cout << "\n\n\n";
	cross_merge();
	for (int i = 0; i < 10; i++) // column
	{
		for (int j = 0; j < 10; j++) // row
		{
			std::cout << environment[i][j] << "\t";
		}
		std::cout << endl;
	}
	return 0;
}

void random_gen()
{

}

// Cell Mutation
void increment()
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

void cross_merge()
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

void rotate()
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

void Reverse()
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

void GeneFlip()
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

void Replace()
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

void Swap()
	{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);
	int temp[9];
	int randCol = dist(gen);
	int randCol2 = dist(gen);

	for (int j = 0; j < 9; j++)
	{
		temp[j] = environment[randCol2][j];
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 9; i > 0; i--)
		{
			environment[j][j] = temp[i];
		}
	}
	std::cout << " Rows " << randCol << " and " << randCol2 << " were swapped " << std:: endl;
	
	}
