#include <iostream>
#include <graphics.h>
using namespace std;

int NumberLog[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char GameField[] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
int v, j, ControlLoc;
char GameChar;

int main()
{

	for (j = 0; j < 7; j++)
	{
		for (v = 0; v < 9; v++)
		{
			cout << NumberLog[v];
			if (v == 2 || v == 5)
			{
				cout << endl;
			}
		}
		cout << endl;

		for (v = 0; v < 9; v++)
		{
			cout << GameField[v];
			if (v == 2 || v == 5)
			{
				cout << endl;
			}
		}
		cout << endl;

		cout << "\n which location would u like to play";
		cin >> ControlLoc;
		cout << "would you like to place X or O";
		cin >> GameChar;

		GameField[ControlLoc] = GameChar;

		cout << endl;

		for (v = 0; v < 9; v++)
		{
			cout << GameField[v];
			if (v == 2 || v == 5)
			{
				cout << endl;
			}
		}
		// Check for a winning combination
		if (GameField[0] == 'X' && GameField[1] == 'X' && GameField[2] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[3] == 'X' && GameField[4] == 'X' && GameField[5] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[6] == 'X' && GameField[7] == 'X' && GameField[8] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[0] == 'X' && GameField[3] == 'X' && GameField[6] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[1] == 'X' && GameField[4] == 'X' && GameField[7] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[2] == 'X' && GameField[5] == 'X' && GameField[8] == 'X')
		{
			cout << "winner is X";
			break;
		}
		if (GameField[0] == 'X' && GameField[4] == 'X' && GameField[8] == 'X')
		{
			cout << "winner is X";
			break;
		}

		if (GameField[2] == 'X' && GameField[4] == 'X' && GameField[6] == 'X')
		{
			cout << "winner is X";
			break;
		}
		if (GameField[0] == 'O' && GameField[1] == 'O' && GameField[2] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[3] == 'O' && GameField[4] == 'O' && GameField[5] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[6] == 'O' && GameField[7] == 'O' && GameField[8] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[0] == 'O' && GameField[3] == 'O' && GameField[6] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[1] == 'O' && GameField[4] == 'O' && GameField[7] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[2] == 'O' && GameField[5] == 'O' && GameField[8] == 'O')
		{
			cout << "winner is O";
			break;
		}
		if (GameField[0] == 'O' && GameField[4] == 'O' && GameField[8] == 'O')
		{
			cout << "winner is O";
			break;
		}

		if (GameField[2] == 'O' && GameField[4] == 'O' && GameField[6] == 'O')
		{
			cout << "winner is O";
			break;
		}
	}

	// Ends The Game Loop

	return 0;
}