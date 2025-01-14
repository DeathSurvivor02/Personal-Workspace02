#include <iostream>  
#include <string> 
using namespace std;

string vigenere(string plainText, string key, bool EncDec);
void caeser(string plainText, string key, bool EncDec);

// #if 1

// int main()
// {
// 	int option = 0;

// 	string vkey;
// 	bool again = 0;
// 	char x;
// 	string plainText;
// 	string cipherText;

// 	cout <<"Welcome to  Encryption-Decryption Station!" << endl;
// 	do {

// 	}
// }

int main()
{
	string plainText;
	string cipherText;
	string key;
	cout << "Enter a plain text, please";
	cin >> plainText;
	cout << "Enter a  kry, please";
	cin >> key;

	string newkey=key;
	while(newkey.length()<plainText.length())
	{
		newkey+=key;

	}
	for (int i = 0; i <plainText.length(); i++)
	{
		cipherText+=(plainText[i]-newkey[i]+26)%26+65;
	}
	cout << cipherText << endl;
}