// #include <iostream>

// /**
//  * @brief generates a set of number including a special character
//  * 
//  * @return int 
//  */
// int main()
// {
	
// }

#include <string>
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number" << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
	cout << endl;

    for (int i = 0; i < num; i++)
    {
        for (int j = 6 ; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}