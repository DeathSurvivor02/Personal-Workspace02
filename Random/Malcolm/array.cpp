#include <iostream>
using namespace std;
int marks;
int opt;
int answer;
char replay;
int main(void)
{
	cout << "Would you like to do?\n";
	cout << "1. Enter/Input each students mark.\n";
	cin >> opt;
	do
	{
		cout << "Enter the option that you would like.\n";
		cout << "A. Display all the students grades entered in the class.\n";
		cout << "B. Search for any entered mark and return the index location.\n";
		cout << "C. Determine the class average.\n";
		cout << "D. Determine which student gained the highest mark in the class and the location (index) of that mark.\n";
		cout << "E. Determine which student gained the lowest mark in the class and the location (index) of that mark.\n";
		cout << "F. Cancle\n";
		cout << "What is your selection?\n";
		cin >> replay;

		if (replay == 'A')
		{
			marks = grades_entered(opt);
		}
		if (replay == 'B')
		{
			Search = Search(opt);
		}
		if (replay == 'C')
		{
			average = average(opt);
		}
		if (replay == 'D')
		{
			highest_mark();
		}
		if (replay == 'E')
		{
			exit(0);
		}
		cout << "Do you wish to do something else with the grades entered? (Y/N)\n";
		cin >> answer;
	} while (answer == 'Y');
	// menu for the code

	int grades[7];
	int key;
	int g;

	//"drudge" filling the grades
	grades[0] = 20;
	grades[1] = 40;
	grades[2] = 100;
	grades[3] = 80;
	grades[4] = 10;
	grades[5] = 60;
	grades[6] = 50;
	grades[7] = 90;

	cout << "Enter the number you want to find (from 0 to 100)";
	cin >> key;
	int flag = 0; // set flag to off

	for (g = 0; g < 7; g++) // start to loop through the grades
	{
		if (grades[g] == key) // if match is found
		{
			flag = 1; // turn flag on
			break;	  // break out of for loop
		}
	}

	if (flag) // if flag is TRUE (1)
	{
		cout << "Your number is at subscript position " << g << ".\n";
	}
	else
	{
		cout << "Sorry, I could not find your number in this array." << endl
			 << endl;
	}

	return 0;
}
