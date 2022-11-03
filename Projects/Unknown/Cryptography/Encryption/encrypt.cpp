#include <iostream>

int main()
{
	char plain = 'A';
	char cipher;
	cipher = plain+2;
	// std::cout << cipher;



// encrypted
	char plaintext = 'J';
	char ciphertext;
	char key = 'B';

	ciphertext = (plaintext+key)%26 + 65;
	std::cout << ciphertext;

// decryption
	char plaintext = 'K';
	char ciphertext;
	char key = 'B';

	ciphertext = (plaintext-key+26)%26 + 65;
	std::cout << ciphertext;
	
}