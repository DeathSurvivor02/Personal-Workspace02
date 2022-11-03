#include <iostream>
#include <array>

// #include <algorithm> // contains sort and binary search

using namespace std;
/* int main()
{
	array<int, 98> w;
	for (int i = 0; i <= sizeof(LSarray); i++)
	{
		std::cin >> LSarray[i];
	}
	
} */
int main()
{
    //array <float, 99> w;


    int w[99];
    int i = 0;
    int count = 0;

    while (count < 100)
    {
        i = rand() % 10;

        w[count] = i;
        count++;
    }

    int largestnum;
    int smallestnum;

    largestnum = w[0];
    smallestnum = w[0];


    for (int i = 0; i < 100; i++)
    {
        if (w[i] > largestnum)
        {
            largestnum = w[i];
        }

    }


    for (int i = 0; i < 100; i++)
    {
        if (w[i] < smallestnum)
        {
            smallestnum = w[i];
        }

    }
    cout << " The largest number is: " << largestnum << endl;
    cout << " The smallest number is: " << smallestnum;

    return 0;
}