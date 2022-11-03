// Number Guessing Game
// Applies the srand() function and loops.
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	char answer;
	int opt;
	int level(int opt);
	int Easy(int opt);
	int Normal(int opt);
	int Hard(int opt);
	// generates random number between 1 and 50
	int randomNumber = (rand() % 10 + 1
	int randomNumber = rand() % 50 + 1;
	int guess = 0;

	cout << "\tThe Number Guessing Game\n\n"; // Title of program.

	cout << "\tGame Introduction\n\n"; // Game Introduction

	cout << "\tThe number guessing game consists of three (3) levels Easy, Normal and Hard. You will be able you pick which diffty you want.\n\n"; // Game Introduction details

	cout << "\tGAME RULES\n\n"; // Game Rules

	cout << "\tThe Number Guessing Game you have ten (10) trys and you will be told if the number is higher or lower the the number you entered and - if you didn't got with in thos ten trys you less and if you did get the number you win\n\n"; // Game Rule details

	int counter = 0;


	cout << "Choose a difficulty\n";

	cout << "1. level 1 Easy\n";

	cout << "2. level 2 Normal\n";

	cout << "3. level 3 Hard\n";

	cin >> opt;
	do
	{
		if (opt == 1)
		{

		}

		cout << counter << endl;
		counter = counter + 1;
		cout << "Enter your guess (#1-50): ";
		cin >> guess; // put variable into 'guess'

		// If guess is < than the random number, display
		if (guess < randomNumber)
			cout << "Your guess was too low\n\n";
		// If guess is > than the random number, display
		if (guess > randomNumber)
			cout << "Your guess was too high\n\n";

	} while (guess != randomNumber);
	(answer == 'Y');
	cout << "\nCongratulations! You've guessed the number.\n\n";
	// While guess is not equal to the random number

	cout << "Do you wish to plan again? (Y/N)\n";
	cin >> answer;
	
	system("pause");
	(counter = 10);

	// End of game system
	return 0;
}