
/*
 * @file Assignment Final push.cpp
 * @author: Chad Proverbs (`24), Gervais Atwell (gervais.atwell@mycavehill.uwi.edu) and Aren Brawthwaite (aren.brathwaite@mycavehill.uwi.edu)
 * @brief:
 * @version 1.0
 * @date 2022-11-17 10:55:38
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assignment.h"
using namespace std;

int menu();
// void second_story_arc(char option);
void start_story();
void update_attributes();

int main()
{
	int option;
	option = menu();
	switch (option)
	{
	case 1:
		start_story();
		break;
	case 2:
		exit(1);
		break;

	default:
		cout << option << " was not an option. Please enter a valid number\n";
		cin >> option;
		break;
	}
	return 0;
}

int menu()
{
	int option = 0;
	cout << "_________________________________________________________________________________________________________________\n";
	cout << "|\t\t\t\tOption\t\t\t|\t\t\tDescription\t\t\t|\n";
	cout << "|_______________________________________________________|_______________________________________________________|\n"
		 << "|1. Start Story\t\t\t\t\t\t| Start the Story\t\t\t\t\t|\n"
		 << "|2. Exit\t\t\t\t\t\t| Exit the Program\t\t\t\t\t|\n";
	cout << "|_______________________________________________________|_______________________________________________________|\n";
	cout << "Select an option:\n";
	cin >> option;
	return option;
}

void start_story()
{
	class story_state_attributes ssa;
	class choice Choice;
	class event event;
	// char choice;
	cout << "You have enrolled into the course COMP1210 Computing I.\n"
		 << "During the first lecture, the lecturer goes through the structure of the course,\n"
		 << "the expectations, the rules, the deadlines and the projects. You learn that the\n"
		 << "projects will be done in pairs or pair-programming to help with the learning experience.\n"
		 << "You have been assigned to work with a student called Max X";

	cout << "Max X sends you an email asking to meet online to discuss the project.\n"
		 << "Max X wishes to meet during the upcoming Friday so that you both can begin as soon as possible.\n";

	cout << "A. You agree to  meet on Friday\n"
		 << "B. You have classes on Friday and so request a meeting on Thursday.\n"
		 << "C. You ignore Max X\n"
		 << "D. You have a fete on Friday so you postpone the meeting till Monday.\n"
		 << "E. Return to Main Menu\n";
	cout << "Please select a choice: \n";
	// char option;
	cin >> Choice.option;

	switch (Choice.option)
	{
	case 'A':
		cout << "The user selected " << Choice.option << endl;
		// cout << " You have agreed to meet on Friday.\n";
		Choice.health_increment = 0;
		Choice.happiness_increment = 0.9;
		Choice.experience_increment = 0.3;
		event.trigger_factor = 1;
		update_attributes();
		second_story_arc();


		return;
		break;
	case 'B':
		cout << "The user selected " << Choice.option;
		// cout << "You have classes on Friday so request a meeting on Thursday.\n";
		Choice.health_increment = 0;
		Choice.happiness_increment = 0.6; // happiness was reduced by .3 because you could not meet on friday
		Choice.experience_increment = 0.3;
		update_attributes();
		second_story_arc();
		// cout << ssa.happiness;
		break;
	case 'C':
		cout << "The User selected " << Choice.option;
		// cout << "You've ignored Max X.\n";
		Choice.health_increment = 0;
		Choice.happiness_increment = 0.3;
		Choice.experience_increment = 0.3;
		update_attributes();
		second_story_arc();

		break;
	case 'D':
		cout << "The User selected " << Choice.option;
		// cout << "You have a fete on Friday so you postpone the meeting till Monday";
		Choice.health_increment = 0;
		Choice.happiness_increment = 0.1;
		Choice.experience_increment = 0.3;
		update_attributes();
		second_story_arc();

	case 'E':
		cout << "The User selected " << Choice.option;
		break;
	default:
		cout << "The choice you selected is not an option. Please enter a make a valid choice\n";
		// cin >> Choice.option;
		cout << endl;
		break;
	}
}

void second_story_arc()
{
	class event event;
	class story_state_attributes ssa;
	class choice Choice;
	// Choice.option = Choice.option;
	char any;
	// cout << //unknown
	if ((Choice.option == 'A') && (event.trigger_factor >= ssa.story_state_factor))
	{

		cout << "You meet on Friday and finish the entire assignment.\n"
			 << "Max submitted it to the Lecturer along with an excellent peer review and\n"
			 << "you got an A on the project.";
		system("pause");

		// cout << "Press and key to Return to Main Menu";
		cin >> any;
		return;
	}
	else if ((Choice.option == 'B') && (event.trigger_factor >= ssa.story_state_factor))
	{
		cout << "You meet on thursday and are only able to finish half of the assignment because\n"
			 << "Max had to leave for Band practice. You reschedule another meeting for friday.\n";

		cout << "A. You finish the remainder of the project ahead of Friday and send to Max\n"
			 << "B. You do attempt to finish the project but you meet Max on Friday\n"
			 << "C. You cancel the friday meeting to spend time with your family\n"
			 << "D. You do not complete the project and miss the Friday meeting.\n"
			 << "E. Return to Main Menu\n";
		cin >> Choice.option;
	}
	else if ((Choice.option == 'C') && (event.trigger_factor >= ssa.story_state_factor))
	{
		cout << "Max emails you two more times on wednesday and thursday ";

		cout << "F. You Ignore Max's emails\n"
			 << "G. You reply to Max's emails and confirm the meeting for Friday\n"
			 << "H. You start the work but forgets to reply to Max's emails\n"
			 << "I. You start the work and confirm the meetings for Friday\n"
			 << "E. Return to Main Menu\n";
		cin >> Choice.option;
	}
	else if ((Choice.option == 'D') && (event.trigger_factor >= ssa.story_state_factor))
	{
		cout << "Max X arrives at the online meeting on Monday, and is visibly annoyed\n"
			 << "because there are pictures on Instagram showing that you were having a great time at the fete.\n"
			 << "Nevertheless, Max X continues with the meeting. You both agree to perform\n"
			 << "various tasks over the week and agree to meet weekly on Thursday so that\n"
			 << "you can attend your Friday fetes";

		cout << "J. You complete the work and meet on Thursdays\n"
			 << "K. You do not complete the work but still meet on Thursdays\n"
			 << "L. You complete the work but miss the Thursday meeting\n"
			 << "M. You do not complete the work and miss the Thursday meetings\n"
			 << "E. Return to Main Menu\n";
		cout << "Select an option: \n";
		cin >> Choice.option;
	}
	else if ((Choice.option == 'E') && (event.trigger_factor >= ssa.story_state_factor))
	{
		return;
	}
	else
	{
		cout << "Confirm your choice \n";
		// continue;
		cin >> Choice.option;
		cout << endl;
	}

	switch (Choice.option)
	{
	case 'A':
		cout << "Max thanks you for finishing the project and submits it along with a good peer review\n";
		// cout << "Press any Key to Return to Main Menu\n";
		system("pause");
		main();
		break;

	case 'B':
		cout << "You meet Max on Friday and get the remainder of the project finish.\n";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'C':
		cout << "The canceled Friday meeting was rescheduled to Sunday."
			 << "You and Max were able to finish and submit the project on Sunday";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'D':
		cout << "Max X has reported the matter to the lecturer and Max X has been assigned a new partner.";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'E':
		cout << "Returning to Main Menu";
		system("pause");
		main();
		break;

	case 'F':
		cout << "You continue to ignore Max's emails so he reports the matter\n"
			 << "to the lecturer and is assigned a new partner.\n";
			//  << "Press and Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'G':
		cout << "Upon meeting on Friday you and Max finish the project\n"
			 << "When you submitted the project on Friday you were the first group to do so,\n"
			 << "so the lecturer gave you an extra mark'";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'H':
		cout << "Max complains to the lecturer that you have not done your part.\n"
			 << "When the lecturer checks up on you, you show him the work you have done\n"
			 << "but said you forgot to email Max confirming a meeting time.\n"
			 << "You and Max then joins your parts together and submits the final project";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'I':
		cout << "Since you started the work earlier, you and Max were able to finish the project on Friday\n"
			 << "You then submitted the project along with your peer reviews";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'J':
		cout << "Max also completed his half of the project\n"
			 << "The two of you submit the project and get a B.\n";
			//  << "Press and Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'K':
		cout << "Max has gotten frustrated with you and has threatened to report\n"
			 << "you to the lecturer if you do not do your part.\n"
			 << "You finished your half of the project, sends it to Max X and he submits it to the lecturer";
		// cout << "Press any Key to Return to Main Menu";
		system("pause");
		main();
		break;

	case 'L':
		cout << "Max X has reported the matter to the lecturer and Max X has been assigned a new partner.\n";
			//  << "Press any Key to Return to Main Menu";
		// cin  >> any;
		system("pause");
		main();
		break;

	case 'M':
		cout << "Max X has reported the matter to the lecturer and Max X has been assigned a new partner.\n";
			//  << "Press any Key to Return to Main Menu";
		// cin  >> any;
		system("pause");
		main();
		break;
	}
}

void update_attributes()
{

	class story_state_attributes ssa;
	class choice choice;
	ssa.health = ssa.health + choice.health_increment;
	ssa.happiness = ssa.happiness + choice.happiness_increment;
	ssa.experience = ssa.experience + choice.experience_increment;
	ssa.temp = ssa.health + ssa.happiness + ssa.experience;
	ssa.story_state_factor = (ssa.temp / MAX) * 1.0;
	// cout << ssa.temp;
}