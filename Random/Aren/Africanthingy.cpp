#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <iomanip>
#include <cstdlib>

using namespace std;

void functiongame()
{
	int randnum;
	string ans;
	string startgame;

	srand(time(NULL));

	do
	{
		randnum = rand() % (54 + 1 - 1) + 1;
	} while (startgame == " YES ");

	cout << endl;

	if (randnum == 1)
	{
		cout << " The presented country is: -------";
	}
	else if (randnum == 2)
	{
		cout << " The presented country:  ------ ";
	}
	else if (randnum == 3)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 4)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 5)
	{
		cout << " The presented country: ------- ---- ";
	}
	else if (randnum == 6)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 7)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 8)
	{
		cout << " The presented country: ---- ----- ";
	}
	else if (randnum == 9)
	{
		cout << " The presented country: ------- ------- -------- ";
	}
	else if (randnum == 10)
	{
		cout << " The presented country: ---- ";
	}
	else if (randnum == 11)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 12)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 13)
	{
		cout << " The presented country: ----------- -------- -- ----- ";
	}
	else if (randnum == 14)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 15)
	{
		cout << " The presented country: ---------- ------ ";
	}
	else if (randnum == 16)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 17)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 18)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 19)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 20)
	{
		cout << " The presented country: --- ------ ";
	}
	else if (randnum == 21)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 22)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 23)
	{
		cout << " The presented country: ------ - ------ ";
	}
	else if (randnum == 24)
	{
		cout << " The presented country: ----- ----- ";
	}
	else if (randnum == 25)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 26)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 27)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 28)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 29)
	{
		cout << " The presented country: ---------- ";
	}
	else if (randnum == 30)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 31)
	{
		cout << " The presented country: ---- ";
	}
	else if (randnum == 32)
	{
		cout << " The presented country: ---------- ";
	}
	else if (randnum == 33)
	{
		cout << " The presented country: --------- ";
	}
	else if (randnum == 34)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 35)
	{
		cout << " The presented country: ---------- ";
	}
	else if (randnum == 36)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 37)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 38)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 39)
	{
		cout << " The presented country: -------- -- --- ----- ";
	}
	else if (randnum == 40)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 41)
	{
		cout << " The presented country: --- ---- --- ------- ";
	}
	else if (randnum == 42)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 43)
	{
		cout << " The presented country: ---------- ";
	}
	else if (randnum == 44)
	{
		cout << " The presented country: ------ ----- ";
	}
	else if (randnum == 45)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 46)
	{
		cout << " The presented country: ----- ------ ";
	}
	else if (randnum == 47)
	{
		cout << " The presented country: ----- ----- ";
	}
	else if (randnum == 48)
	{
		cout << " The presented country: ----- ";
	}
	else if (randnum == 49)
	{
		cout << " The presented country: -------- ";
	}
	else if (randnum == 50)
	{
		cout << " The presented country: ---- ";
	}
	else if (randnum == 51)
	{
		cout << " The presented country: ------- ";
	}
	else if (randnum == 52)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 53)
	{
		cout << " The presented country: ------ ";
	}
	else if (randnum == 54)
	{
		cout << " The presented country: -------- ";
	}
	else
		cout << " Error something went wrong ";
}

int main()
{

	int i = 0;
	// Create and open a text file
	// Writefile.open("African Countries.txt");
	ofstream WriteFile{"African Countries.txt", ios::app};
	ifstream ReadFile{"African Countries.txt", ios::in};
	if (!WriteFile || !ReadFile)
	{
		cerr << "File cannot be opened!" << endl;
		exit(EXIT_FAILURE);
	}
	// Write to the file
	// Writefile << "Files can be tricky, but it is fun enough!", "congo";
	// Close the file
	// Writefile.close();
	// Create a text string, which is used to output the text file
	string myText;
	// Read from the text file
	ifstream MyReadFile("African Countries.txt");
	// string afcountries;
	array<string, 54> afcountries;
	// Use a while loop together with the getline() function to read the file line by line
	// while (getline(MyReadFile, myText))
	while (ReadFile >> quoted(myText))
	{
		// Output the text from the file
		afcountries[i] = myText;
		cout << afcountries[i] << endl;
		i++;
	}
	// Close the file
	// MyReadFile.close();
	return 0;
}