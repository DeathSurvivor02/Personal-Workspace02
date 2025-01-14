// Game.cpp
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "WordApp.h"
#include "Letter.h"
#include "WordApp.cpp"
using namespace std;
int main()
{
	// Load words from a file into a vector
	ifstream wordFile("words.txt");
	if (!wordFile.is_open())
	{
		cout << "Error opening words.txt file." << endl;
		return 1; // Exit with an error code
	}

	vector<string> words;
	string word;

	while (wordFile >> word)
	{
		words.push_back(word);
	}

	// Seed for random word selection
	srand(static_cast<unsigned int>(time(0)));

	// Select a random word
	string selectedWord = words[rand() % words.size()];

	// Create WordApp object
	WordApp obj(selectedWord);

	int maxGuesses = selectedWord.length() + 2; // Adjust as needed

	while (obj.getRemainingGuesses() > 0 && !obj.isWordGuessed())
	{
		obj.display();

		// Get user input for guess
		char guess;
		cout << "Enter your guess: ";
		cin >> guess;

		// Process the guess
		obj.hide(guess);
	}

	// Display the result
	obj.display();
	if (obj.isWordGuessed())
	{
		cout << "Congratulations! You guessed the word." << endl;
	}
	else
	{
		cout << "Sorry, you ran out of guesses. The correct word was: " << selectedWord << endl;
	}

	return 0;
}
