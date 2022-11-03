#include <iostream>
#include <vector>

using namespace std;

void lab3question1()
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 26;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int g = i + 1; g < nums.size(); g++)
		{
			if (nums[i] + nums[g] == target)
			{
				cout << i << " " << g;
			}
		}
	}
}
/* void lab3question2()
{
	int array[] = {3, 6, 1, 0};
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (array[i] > max);
		max = array[i];
		for (int i = 0; i < 4; i++)
			if (array[i] * 2 >= max)
			{
				cout << max;
			}
			else
			{
				cout << 1;
			}
	}
} */
int lab3question2()
{

	int size, max = 0;
	cout << "Enter the size of the array" << endl;
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the size of the array" << endl;
		cin >> array[i];
	}

	// searches the max value for the array
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] != max)
		{

			if ((array[i] / max) >= 2)
			{

				return i;
			}
			else
				return -1;
		}
	}
}

void lab3question3()
{
	string S1 = "Timothy";
	string S2 = "Tim";
	for (int i = 0; i < S1.size(); i++)
	{
		if (S1[i] == S2[0])
		{
			if (S1.substr(i, S2.size()) == S2)
			{
				cout << "YES";
			}
		}
	}
}
int main()
{
	lab3question1();
	int value = lab3question2();
	cout << value << endl;
	lab3question3();

	return 0;
}