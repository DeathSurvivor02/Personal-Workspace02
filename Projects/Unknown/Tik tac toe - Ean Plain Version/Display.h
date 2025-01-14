#ifndef _DISPLAY_H_
#define _DISPLAY_H_

/**
 * @file Display.h
 * @author your name (you@domain.com)
 * @brief This file shows the display of the tik tac toe locations
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include "TestingFile.cpp"

class Display
{
public:
	// variables
	void empty_display();
	char player_option();
	void player_display();
	void player_gameplay();
};
// functions
void Display::empty_display()
{

	/*description: this displays the board as it would be at the start of the round*/
	std::cout << "     |     |     \n";
	std::cout << "  1  |  2  |  3  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  4  |  5  |  6  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  7  |  8  |  9  \n";
	std::cout << "     |     |     \n";
}

void Display::player_display()
{
	//! very inefficient
/* 	char loc_1 = '1';
	char loc_2 = '2';
	char loc_3 = '3';
	char loc_4 = '4';
	char loc_5 = '5';
	char loc_6 = '6';
	char loc_7 = '7';
	char loc_8 = '8';
	char loc_9 = '9'; */

	char location[10] =  {'0', '1', '2', '3', '4', '5', ' 6', '7', '8', '9'};


	/*description: this displays the board as it would be at the start of the round*/
	std::cout << "     |     |     \n";
	std::cout << "  " << location[1] << "  |  " << location[2] << "  |  " << location[3] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << location[4] << "  |  " << location[5] << "  |  " << location[6] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << location[7] << "  |  " << location[8] << "  |  " << location[9] << "  \n";
	std::cout << "     |     |     \n";
}
void Display::player_gameplay()
{
	bool win_condition = false;
	char win_letter = '';

	//* Horizontal Wins for both X and O
	if ()

	//? Vertical Wins for both X and O
	if (((loc_1 && loc_4 && location[7]) == 'O') || ((loc_2&& loc_5&&loc_8)=='O') || ((loc_3&&loc_6&&loc_9)=='O'))
	{
		win_condition = true;
		win_letter = 'O';
	}
	if (((loc_1 && loc_4 && location[7]) == 'X') || ((loc_2&& loc_5&&loc_8)=='X') || ((loc_3&&loc_6&&loc_9)=='X'))
	{
		win_condition = true;
		win_letter = 'X';
	}

	//& Diagonal Wins for both X and O
	if (((loc_1 && loc_5 && loc_9) == 'O')|| ((loc_3 && loc_5 && loc_7)== 'O'))
	{
		win_condition = true;
		win_letter = 'O';
	}

	if (((loc_1 && loc_5 && loc_9) == 'X')|| ((loc_3 && loc_5 && loc_7)== 'X'))
	{
		win_condition = true;
		win_letter = 'X';
	}
}
#endif