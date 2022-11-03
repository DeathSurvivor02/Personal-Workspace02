/* 





 */

#include <iostream>

int L_search(int size, int arr[], int key);
int L_search(int size, int arr[], int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}

	return -1;
}
int main()
{
	int size = 0;
	int key = 0;
	int result = 0;
	std::cout << "Enter the size of the array you wish to search:" << std::endl;
	std::cin >> size;
	
	int arr[];
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter a value for this location:";
		std::cin >> arr[i];
		std::cout << std::endl;
	}
	std::cout << "Enter a value to search\n";
	std::cin >> key;

	std::cout << L_search(size, arr[i], key) << std::endl;
	system("cls");
	if (result <= 0)
	{
		std::cout << "The number was found in the array " << result << std::endl; 
	}
	else
	{
		std::cout << "The number was not found in the array ";
	}
	return 0;
}

/* 


 */