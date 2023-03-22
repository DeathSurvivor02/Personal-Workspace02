#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
public:
	string data;
	int id;
	Node *next;

	Node(string data, int id)
	{
		this->data = data;
		this->id = id;
		this->next = NULL;
	}
};

#endif
