#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"

class Deque
{
private:
	Node *head;
	Node *tail;

public:
	Deque()
	{
		head = NULL;
		tail = NULL;
	}
	void addFront(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}
	void addBack(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	void removeFront()
	{
		if (head == NULL)
		{
			std::cout << "Deque is empty\n";
			return;
		}
		Node *temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		else
		{
			tail = NULL;
		}
		delete temp;
	}
	void removeBack()
	{
		if (head == NULL)
		{
			std::cout << "Deque is empty\n";
			return;
		}
		Node *temp = tail;
		tail = tail->prev;
		if (tail != NULL)
		{
			tail->next = NULL;
		}
		else
		{
			head = NULL;
		}
		delete temp;
	}
	void display()
	{
		if (head == NULL)
		{
			std::cout << "Deque is empty\n";
			return;
		}
		Node *current = head;
		while (current != NULL)
		{
			std::cout << current->month << " " << current->year << " " << current->artist << " " << current->song << " " << current->label << " " << current->weeksAtNumberOne << "\n";
			current = current->next;
		}
	}
};

#endif // DEQUE_H
