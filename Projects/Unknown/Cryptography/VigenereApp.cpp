#include <iostream>
#include <string>
using namespace std;
string vigenere(string text, string key, bool EncDec);

int main()
{

	string plainText, cipherText, key;
	char x;
	do
	{
		cout << "Welcome to the encryption decryption station!" << endl;
		cout << "Please choose  one of the folloeing options." << endl;
		cout << "1. Encryptions" << endl
			 << "2. Decryptions" << endl
			 << "3. Exit" << endl;

		int option;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Please enter a plain text" << endl;
			cin >> plainText;
			cout << "Please enter a key" << endl;
			cin >> key;
			cipherText = vigenere(plainText, key, 0);
			cout << "Cipher Text: " << cipherText << endl;
			// Function: vigenere()
			cout << "Press Y/y to repeat the process" << endl;
			cin >> x;
			break;
		case 2:
			cout << "Please enter a cipher text" << endl;
			cin >> cipherText;
			cout << "Please enter a key" << endl;
			cin >> key;
			cipherText = vigenere(plainText, key, 1);
			cout << "Cipher Text: " << cipherText << endl;
			// Function: vigenere()
			cout << "Press Y/y to repeat the process" << endl;
			cin >> x;
			break;
		case 3:
			x = 'n';
			break;
		}
	} while (x == 'Y' || x == 'y');
}
string vigenere(string text, string key, bool EncDec)
{
	string newkey = key, newText;
	while (newkey.length() < text.length())
	{
		newkey += key;
	}
	if (EncDec == 0)
	{
		for (int i = 0; i < text.length(); i++)
		{
			newText += (text[i] + newkey[i]) % 26 + 65;
		}
	}
	else
	{
		for (int i = 0; i < text.length(); i++)
		{
			newText += (text[i] - newkey[i] + 26) % 26 + 65;
		}
	}
	return newText;
}