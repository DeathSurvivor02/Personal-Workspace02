#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int A = 0;
	int B = 0;
	int diff = 0;


	cout << "Please enter two unequal numbers\n";
	// system("exit");
	exit(0);
	cin >> A;
	cin >> B;
	while (A == B)
	{
		cout << "Please enter 2 unequal numbers\n";
		cin >> A;
		cin >> B;
	}
	if (A != B)
	{
		if (A < B)
		{
			diff = B - A;
			cout << "The difference between " << A << " and " << B << "  is: " << diff;
		}
		else
		{
			diff = A - B;
			cout << "The difference between " << A << " and " << B << " is: " << diff;
		}
	}
	return 0;
}
