#include <iostream>
#include <stack>

using namespace std;

int main()
{

	stack<int>numStack;
	int ele;
	if (numStack.empty())
	{
		std::cout << "Stack is empty";
		std::cout << "Enter a number to enter in the stack: ";
		std::cin >> ele;
		numStack.push(ele);

	}
	else 
	{
		std::cout << "Stack is not empty";
		std::cout << "Stack size is " << numStack.size() << std::endl;
	}
	return 0;
}
