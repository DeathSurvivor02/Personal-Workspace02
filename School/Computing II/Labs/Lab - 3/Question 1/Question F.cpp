// Determine and display the smallest and largest values contained in 98-element array w.

#include <iostream>
#include <array>
using namespace std;

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	std::array<float, 99> w;
	float largest = w[0];
	for (int i = 0; i <= 98; i++) // gets the values of the position of the array
	{
		std::cout << "Enter a float for the array position #" << i << " : ";
		std::cin >> w[i];
		std::cout << std::endl;
	}

	// this sorts the numbers in the array (bubble sorting..i think)
	float temp;
	for (int i = 0; i < 98; i++)
	{
		for (int j = 0; j < 98; j++)
		{
			if (w[j] > w[j + 1])
			{
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
			}
		}
	}

	// searching for the smallest value;
	float smallest = w[0];
	for (int i = 0; i <= 98; i++)
	{
		if (w[i] < smallest)
		{
			// replaces the smallest previously found value with the new value
			smallest = w[i];
		}
		if (w[i] > largest)
		{
			largest = w[i];
		}
	}
	std::cout << "The smallest value is " << w[0] << std::endl;
	std::cout << "The largest value is " << w[98] << std::endl;
	return 0;
}
