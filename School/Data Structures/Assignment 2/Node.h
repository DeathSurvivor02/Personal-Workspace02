#ifndef NODE_H
#define NODE_H

class Node
{
public:
	char month[10];
	int year;
	char artist[50];
	char song[50];
	char label[15];
	int weeksAtNumberOne;

	// checkover

	Node *next;

	Node(char month[10], int year, char artist[50], char song[50], char label[15], int weeksAtNumberOne)
	{
		this->month[10] = month[10];
		this->year = year;
		this->artist[50] = artist[50];
		this->song[50] = song[50];
		this->label[15] = label[15];
		this->weeksAtNumberOne = weeksAtNumberOne;
	}
};

#endif // NODE_H
