/* included predetermined files */
#include <iostream>
#include <vector>
#include <string>

#include <ctime> //maybe
#include <random>

/* Included made files */
#include "words.txt"
#include "WordApp.cpp"
#include "Words.h"
using namespace std;

int main()
{

	/* Review: Start */

	/* Variables: */
	std::string line;
	int lineNumber = 1;
	int rand = 0;
	int totalWords = 0;

	srand(static_cast<unsigned>(time(0))); // creates a random time to be use for the random number generator

	// Maybe: (chat gpt code- kinda)
	std::ifstream inputFile("words.txt");

	/* Description: checks to see if the file works or not */
	if (!inputFile.is_open())
	{
		std::cout << "Error: Couldn't open file!" << std::endl;
		return 1; // return 1 states there's an error in the code more specifically opening the file
	}
	/* Description: if the above code doesn't print any error, it reads the file  */
	while (std::getline(inputFile, line))
	{
		int wordCount = 0;
		for (char character : line)
		{
			if (character == ' ') // if the character is a space it will count it as a word
			{
				wordCount++;
			}
		}
		totalWords = wordCount;
		// std::cout << wordCount << std::endl;
	}

	// Todo: create random number generator
	rand = rand() % totalWords + 1;

	/* Review: End */

	/* Todo: Picks a word from the file  */
	if(!inputFile.is_open())
	{
		std::cout << " Error Couldn't open file!" << std::endl;
	}

	/* Todo: this needs to change to take in different words */
	WordApp obj("Barbados");
	obj.hide('a');
	obj.display();
	return 0;
}

/* Class: Letter */

