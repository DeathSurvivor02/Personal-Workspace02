#include <iostream>

#include "Display.h"
#include "Player.h"

int main()
{
	// variables
	char player_letter;


	// class variables
	Display display;
	PlayerInfo player;

	player.player_name();
	player_letter = player.player_option();
	display.empty_display();
	display.player_display();
	return 0;
}