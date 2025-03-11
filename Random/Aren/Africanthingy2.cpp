#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <iomanip>
#include <cstdlib>

// using namespace std;

void functionGame()
{
	// Variables:
	int randNum;
	string answer;
	bool startGame;

	srand(time(NULL));

	//& Condition:
	do
	{
		randNum = rand() % (54 + 1 - 1) + 1;
	} while (startGame == false);
	std::cout << endl;

	//
	//? Switch statement
	switch (randNum)
	{
	case 1:
		cout << " The presented country is: -------";
		break;
	case 2:

		cout << " The presented country:  ------ ";
		break;
	case 3:

		cout << " The presented country: ----- ";
		break;
	case 4:

		cout << " The presented country: -------- ";
		break;
	case 5:

		cout << " The presented country: ------- ---- ";
		break;
	case 6:

		cout << " The presented country: ------- ";
		break;
	case 7:

		cout << " The presented country: -------- ";
		break;
	case 8:

		cout << " The presented country: ---- ----- ";
		break;
	case 9:

		cout << " The presented country: ------- ------- -------- ";
		break;
	case 10:

		cout << " The presented country: ---- ";
		break;
	case 11:

		cout << " The presented country: ------- ";
		break;
	case 12:

		cout << " The presented country: -------- ";
		break;
	case 13:

		cout << " The presented country: ----------- -------- -- ----- ";
		break;
	case 14:

		cout << " The presented country: ----- ";
		break;
	case 15:

		cout << " The presented country: ---------- ------ ";
		break;
	case 16:

		cout << " The presented country: ------- ";
		break;
	case 17:

		cout << " The presented country: -------- ";
		break;
	case 18:

		cout << " The presented country: -------- ";
		break;
	case 19:

		cout << " The presented country: ----- ";
		break;
	case 20:

		cout << " The presented country: --- ------ ";
		break;
	case 21:

		cout << " The presented country: ----- ";
		break;
	case 22:

		cout << " The presented country: ------ ";
		break;
	case 23:

		cout << " The presented country: ------ - ------ ";
		break;
	case 24:

		cout << " The presented country: ----- ----- ";
		break;
	case 25:

		cout << " The presented country: ----- ";
		break;
	case 26:

		cout << " The presented country: ------- ";
		break;
	case 27:

		cout << " The presented country: ------ ";
		break;
	case 28:

		cout << " The presented country: ----- ";
		break;
	case 29:

		cout << " The presented country: ---------- ";
		break;
	case 30:

		cout << " The presented country: ------ ";
		break;
	case 31:

		cout << " The presented country: ---- ";
		break;
	case 32:

		cout << " The presented country: ---------- ";
		break;
	case 33:

		cout << " The presented country: --------- ";
		break;
	case 34:

		cout << " The presented country: ------- ";
		break;
	case 35:

		cout << " The presented country: ---------- ";
		break;
	case 36:

		cout << " The presented country: ------- ";
		break;
	case 37:

		cout << " The presented country: ----- ";
		break;
	case 38:

		cout << " The presented country: ------- ";
		break;
	case 39:

		cout << " The presented country: -------- -- --- ----- ";
		break;
	case 40:

		cout << " The presented country: ------ ";
		break;
	case 41:

		cout << " The presented country: --- ---- --- ------- ";
		break;
	case 42:

		cout << " The presented country: ------- ";
		break;
	case 43:

		cout << " The presented country: ---------- ";
		break;
	case 44:

		cout << " The presented country: ------ ----- ";
		break;
	case 45:

		cout << " The presented country: ------- ";
		break;
	case 46:

		cout << " The presented country: ----- ------ ";
		break;
	case 47:

		cout << " The presented country: ----- ----- ";
		break;
	case 48:

		cout << " The presented country: ----- ";
		break;
	case 49:

		cout << " The presented country: -------- ";
		break;
	case 50:

		cout << " The presented country: ---- ";
		break;
	case 51:

		cout << " The presented country: ------- ";
		break;
	case 52:

		cout << " The presented country: ------ ";
		break;
	case 53:

		cout << " The presented country: ------ ";
		break;
	case 54:

		cout << " The presented country: -------- ";
		break;

		//... Continue for the remaining cases
	default:
		std::cout << " Error something went wrong ";
		break;
	}
}

int main()
{
	// Variables:
	int count = 0;
	string myText;

	std::ofstream WriteFile{"African Countries.txt", ios::app};
	std::ifstream ReadFile{"African Countries.txt", ios::in};
	if (!WriteFile ||!ReadFile)
	{
		std::cerr << "File was not able to be opened" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	ifstream MyReadFile("African Countries.txt");
	array<string, 54> countries;
	while ()

}