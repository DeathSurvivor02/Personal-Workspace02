#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <string>

using namespace std;
class Queue
{
private:
	Node *head;
	Node *tail;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	void enqueue(string month, int year, string artist, string song, string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->setNext(temp);
			tail = temp;
		}
	}
	string dequeue()
	{
		string temp;
		if (head == NULL)
		{
			return ("Queue is empty\n");
		}
		else if (head == tail)
		{
			temp = head->getRecord();
			Node *remove = head;
			head = head->getNext();
			delete remove;
			return temp;
		}
		else
		{
			temp = head->getRecord();
			Node *remove = head;
			delete remove;
			return temp;
		}
	}
	string showHead()
	{
		if (head == NULL)
		{
			return ("Queue is empty\n");
		}
		else 
			return head -> getRecord();
	}
	string showTail()
	{
		if (head == NULL)
		{
			return ("Queue is empty\n");
		}
		else 
			return tail -> getRecord();
	}
	string showAll()
	{
		if (head == NULL)
			return ("Queue is empty\n");
		Node* ptr = head;
		string str = "";
		while(ptr != NULL)
		{
			str.append(ptr -> getRecord());
			str.append("\n");
			ptr = ptr -> getNext();
		}
		return str;
	}
	void purge() { head = NULL; }
};

#endif // QUEUE_H
