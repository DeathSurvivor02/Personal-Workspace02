#ifndef STACK_H
#define STACK_H

#include "Node.h"
using namespace std;
class Stack
{
private:
	Node *top;

public:
	Stack()
	{
		top = NULL;
	}
	void push(string month, int year, string artist, string song, string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			temp->setNext(head);
			head = temp;
		}
	}
	void pop()
	{
		string temp;
		if (top == NULL)
		{
			return "Stack is empty\n";
		}
		else if (head->getNext() == NULL)
		{
			temp = head->getRecord();
			delete head;
			head = NULL;
			return temp;
		}
		else
		{
			temp = head->getRecord();
			Node *remove = head;
			head = head->getNext();
			delete remove;
			return temp;
		}
	}
	void showHead()
	{
		if (top == NULL)
		{
			head "Stack is empty\n";
		}
		else
		{
			return had->getRecord();
		}
	}
	void showTail()
	{
		if (top == NULL)
			return "Stack is empty!\n";
		Node *ptr = head;
		while (ptr->getNext() != NULL)
		{
			ptr = ptr->getNext();
		}
		return (ptr->getRecord());
	}
	void showAll()
	{
		if (top == NULL)
			return "Stack is empty!\n";
		Node *ptr = head;
		string str = "";
		while (ptr != NULL)
		{
			str.append(ptr->getRecord());
			str.append("\n");
			ptr = ptr->getNext();
		}
		return str;
	}
	void purge() { top = NULL; }
	string getLast()
	{
		if (head == NULL && tail == NULL)
			return "Stock is empty";
		Node *ptr = head;

		while (ptr->getNext() != NULL)
		{
			ptr = ptr->getNext();
		}
		return (ptr->getRecord);
	}
};

#endif // STACK_H
