#include <iostream>
#include <vector>
using namespace std;
class Letter
{
public:
	char value;
	bool visible;
	Letter(char val) : value(val), visible(true) {}
};
class WordApp
{
private:
	vector<Letter> theword;

public:
	WordApp(string word)
	{
		for (char c : word)
		{
			Letter L(c);
			theword.push_back(L);
		}
	};
	void hide(char character)
	{
		for (Letter &l : theword)
		{
			if (l.value == character)
			{
				l.visible = false;
			}
		}
	}
	void display()
	{
		for (Letter l : theword)
		{
			char v = (l.visible) ? l.value : '-';
			cout << v << " ";
		}
	};
};
int main()
{
	WordApp obj("Barbados");
	obj.hide('a');
	obj.display();
	return 0;
}
