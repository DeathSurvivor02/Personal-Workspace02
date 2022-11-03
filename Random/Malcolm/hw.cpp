#include <iostream>

using namespace std;
int animaltype;
char reply;
char type;

void Dog(int InsFee = 0)
{
	cout << "Is the Dog neutered Y/N? ";
	cin >> reply;

	if (reply == 'Y')

	{
		InsFee = 80;
	}
	if (reply == 'N')
	{

		InsFee = 60;
	}
	cout << "\n Your total Insurance for your pet is $" << InsFee;
}

void Cat(int InsFee = 0)
{
	cout << "Is the Cat neutered Y/N? ";
	cin >> reply;

	if (reply == 'Y')

	{
		InsFee = 80;
	}
	if (reply == 'N')

	{
		InsFee = 60;
	}
	cout << "\n Your total Insurance for your pet is $" << InsFee;
}

void Bird()
{
	cout << "Nothing";
}
void Reptile()
{
	cout << "Nothing";
}

int main()
{
	int InsFee = 0;
	char repeat;

	{
		do
			cout << "Hello World what's your animal type? ";
		cin >> type;

		if (type == 'D'|| type == 'd')

		{
			Dog();
		}

		if (type == 'C' || type == 'c')

		{
			Cat();
		}

		if (type == 'B' ||  type == 'b')

		{
			Bird();
		}

		if ((type == 'R') || (type == 'r'))

		{
			Reptile();
		}
		if (type != 'R' && type != 'B' && type != 'C' && type != 'D')
		{
			cout << "\n ERROR INVALID ANIMAL\n";
		}

			cout << "\n Do you want to insure another animal Y/N?";
			cin >> repeat;
		}while (repeat == 'Y')
}
		
