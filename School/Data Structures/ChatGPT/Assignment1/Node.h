#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
	std::string month;
	int year;
	std::string artist;
	std::string song;
	std::string label;
	int weeksAtNumberOne;

	Node *next;

	Node(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		this->month = month;
		this->year = year;
		this->artist = artist;
		this->song = song;
		this->label = label;
		this->weeksAtNumberOne = weeksAtNumberOne;
		this->next = NULL;
	}
};

#endif // NODE_H
