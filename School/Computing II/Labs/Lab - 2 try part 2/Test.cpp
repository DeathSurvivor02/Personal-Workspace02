#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
using namespace std;

int main()
{
	int type;
	std::cout << "What type of shipping are you planning to do?";
	std::cin >> type;
	if (type == 1)
	{
		Package package;
	} 
	return 0;
}