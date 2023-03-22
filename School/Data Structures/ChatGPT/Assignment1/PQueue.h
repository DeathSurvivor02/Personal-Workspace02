#ifndef PQUEUE_H
#define PQUEUE_H

#include "Node.h"

class PQueue
{
private:
	Node *head;

public:
	PQueue()
	{
		head = NULL;
	}
	void enqueue(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL || weeksAtNumberOne > head->weeksAtNumberOne)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			Node *current = head;
			while (current->next != NULL && weeksAtNumberOne <= current->next->weeksAtNumberOne)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
	void dequeue()
	{
		if (head == NULL)
		{
			std::cout << "Priority Queue is empty\n";
			return;
		}
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	void display()
	{
		if (head == NULL)
		{
			std::cout << "Priority Queue is empty\n";
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

#endif // PQUEUE_H
