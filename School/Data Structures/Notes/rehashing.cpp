//
//  Rehashing.cpp
//  Rehashing
//
//  Created by Dr. John Charlery on 02/15/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//
// Hashing with Rehashing technique for Collision Resolution
//
// Hashing the values: 2, 10, 17, 27, 15, 3, 61, 8, 21, 12, 5, 0, 4, 13, 26, 7, 9 and 23
// into a 30 member hash table.
//
//  Hashing Functions:
//      1.      (3*x) % 30
//      2.      (5*x) % 30
//      3.      (7*x) % 30
//      4.      (9*x) % 30
//      5.      (11*x) % 30
//      6.      (13*x) % 30
//      7.      (15*x) % 30
//      8.      (17*x) % 30
//      9.      (19*x) % 30
//     10.      (21*x) % 30
//     11.      (23*x) % 30

#include <iostream>
using namespace std;

// Global data
int data[18] = {2, 10, 17, 27, 15, 3, 61, 8, 21, 12, 5, 0, 4, 13, 26, 7, 9, 23};
// int hashtable[30] = { [0 ... 29] = -99 };       // Initialize table with -99

int hashtable[30];

void hashData()
{
	int index;
	int indexTable[11]; // To store the indices from the 11 functions
	bool succeed;

	//  Hash the values from the data array into the hashtable, using
	//  “Rehashing” as the Collision Resolution technique.

	int coeff; // Coefficient change for the hashing functions
	int hash;  // Subscript number for hash function

	for (int x = 0; x < 18; x++)
	{
		succeed = false;
		coeff = 0;

		// Store the hashing functions indices in indexTable
		for (int k = 0; k < 11; k++)
		{
			indexTable[k] = ((3 + coeff) * data[x]) % 30;
			coeff += 2;
		}

		hash = 0;
		index = indexTable[0]; // Start with the subscript from the first hashing function

		while (succeed == false)
		{
			if (hashtable[index] == -99) // The subscript is available
			{
				hashtable[index] = data[x];
				succeed = true;
			}

			else // Go to the next subscript and see if it is available
			{
				hash++;		   // Get the index from the next hashing function.
				if (hash < 11) // Test if # of viable hashing functions is exceeded
					index = indexTable[hash];
				else
					break; // Could not find a place for the data value
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 30; i++)
	{
		hashtable[i] = -99;
	}
	hashData(); // Load the data into the hash table

	// Display the contents of the hash table
	cout << "Locations in Hashtable where the values were hashed:\n";

	for (int x = 0; x < 30; x++)
	{
		cout << x << " : ";
		if (hashtable[x] == -99)
			cout << "\n";
		else
			cout << hashtable[x] << "\n";
	}

	return 0;
}