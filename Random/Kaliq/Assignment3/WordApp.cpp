#include <iostream>
#include <vector>
#include "Words.h"
#include "Letter.h"
using namespace std;


WordApp::WordApp(string word)
{
	for (char c : word)
	{
		Letter L(c);
		theword.push_back(L);
	}
}

void WordApp::hide(char character)
{
	for (Letter &l : theword)
	{
		if (l.value == character)
		{
			l.visible = false;
		}
	}
}

void WordApp::display()
{
	for (Letter l : theword)
	{
		char v = (l.visible) ? l.value : '-';
		cout << v << " ";
	}
}



