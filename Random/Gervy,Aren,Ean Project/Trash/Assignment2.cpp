/**
 * @file Assignment2.cpp
 * @authors Ean Bynoe (eanbynoe@gmail.com), Gervais Atwell (gervais@gmail.com), Aren Brathwaite (nbrathwaite@gmail.com)
 * @brief:
 * @version 1.0
 * @date 2022-11-13 11:20:30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

class story_state_attributes
{
	class choice choice;
	int const MAX = 100;

public:
	int health = 0;
	int experience = 0;
	int happiness = 0;

	void incrementHealth()
	{
		health = choice.health_increment;
	};
	void decrementHealth()
	{
		health = choice.health_decrement;
	};

	void incrementExperience()
	{
		experience = choice.experience_increment;
	};
	void decrementExperience()
	{
		experience = choice.experience_decrement;
	};

	void incrementHappiness()
	{
		happiness = choice.happiness_increment;
	};
	void decrementHappiness()
	{
		happiness = choice.happiness_decrement;
	};
};
class choice
{
public:
	int health_increment = 0.1;
	int experience_increment = 0.1;
	int happiness_increment = 0.1;

	int health_decrement = 0.1;
	int experience_decrement = 0.1;
	int happiness_decrement = 0.1;
};
class Health : private story_state_attributes
{

	float health;
};
class story_state_factor : public story_state_attributes
{

	double temp = 0.0;
	story_state_factor::temp = health + experience + happiness;
	if (temp >= MAX)
	{
		temp = MAX
	}
	story_state_factor = temp / MAX * 1.0
};
class Experience : private story_state_attributes
{

	float experience;
};
class Happiness : private story_state_attributes
{

	float happiness;
};

int main()
{
}

void menu()
{
	int choice = 0;
	string name;
	cout << "Welcome to  ____  Game" << endl;
	cout << " What is your name?" << endl;
	// cin >> name;
	getline(cin, name);
	cout << "\t\t\t\t\t\tMenu\n";
	cout << "\t\t\t1. Start Story \t\t\t\t Start the story \n";
	cout << "\t\t\t2. End         \t\t\t\t Exit the program \n"
		<< "select an option: ";

	cin >> choice;
	switch (choice)
	{
	case /* constant-expression */ (1):
		/* code */ Story() break;

	default:
		break;
	}
}
