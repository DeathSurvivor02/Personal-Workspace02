#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string.h>
#include <fstream>
// using namespace std;
class PlayerInfo
{
public:
	char player_option();
	void player_name();
};

char PlayerInfo::player_option()
{
	char choice;
	std::cout << "Do you want to be 'X' or 'O'?" << std::endl;
	std::cin >> choice;
	while ((choice != 'X' || choice != 'x' || choice != 'O' || choice != 'o'))
	{
		if (choice == 'o' || choice == 'O')
		{
			std::cout << "You will play as 'O' " << std::endl;
			break;
		}
		else if (choice == 'x' || choice == 'X')
		{
			std::cout << "You will play as 'X' " << std::endl;
			break;
		}
		std::cout << "You can only be 'X' or 'O'.\nPlease enter your option." << std::endl;
		std::cin >> choice;
	}
	return choice;
}

void PlayerInfo::player_name()
{
	std::ofstream Record{"RecordofPlayers.txt", ios::out};
	std::string name;
	int count = 0;
	std::cout << "What is the name of the player?" << std::endl;
	getline(std::cin,name);
	std::cout << "Welcome " << name << "!" << std::endl;
	Record << count++ << " Player Name: " << name << " " << std::endl;

}
#endif