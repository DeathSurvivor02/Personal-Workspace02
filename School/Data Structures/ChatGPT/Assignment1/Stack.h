#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
private:
	Node *top;

public:
	Stack()
	{
		top = NULL;
	}
	void push(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		temp->next = top;
		top = temp;
	}
	void pop()
	{
		if (top == NULL)
		{
			std::cout << "Stack is empty\n";
			return;
		}
		Node *temp = top;
		top = top->next;
		delete temp;
	}
	void display()
	{
		if (top == NULL)
		{
			std::cout << "Stack is empty\n";
			return;
		}
		Node *current = top;
		while (current != NULL)
		{
			std::cout << current->month << " " << current->year << " " << current->artist << " " << current->song << " " << current->label << " " << current->weeksAtNumberOne << "\n";
			current = current->next;
		}
	}
};

#endif // STACK_H
