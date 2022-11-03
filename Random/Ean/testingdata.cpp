 #include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int result;
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
	cout << "Enter the result: " << std::endl;
	cin >> result;
	cout << result << std::endl;
    cout << endl;
}