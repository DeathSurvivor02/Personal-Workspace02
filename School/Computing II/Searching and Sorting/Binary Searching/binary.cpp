#include <iostream>

// using namespace std;

int main() int main()
{
	int size = 0;

	std::cout << "Testing..." << std::endl;
	std::cout << "Binary Search..." << std::endl;

	std::cout << "Enter the size of the array" << std::endl;
	std::cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "\nEnter the value for the cell in the array" << std::endl;
		std::cin >> arr[i];
	}

	int key = 0;
	std::cout << "Enter the key to be search: ";
	std::cin >> key;
}

int binarySearch(int size, int arr[], int key)
{
	bool found = false;
	int top = 0;
	float loc = 0;
	int base = 0;
	loc = size/2;
	if (loc % 1 = 0.5)
	{
		loc = loc - 0.5;
	}
	while (found == false)
	{
		if (key > loc)
		{
			base = loc;

		}
		if (key < loc)
		{
			top = loc;
		}

	}
}