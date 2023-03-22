#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
private:
	Node *front;
	Node *rear;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (front == NULL)
		{
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void dequeue()
	{
		if (front == NULL)
		{
			std::cout << "Queue is empty\n";
			return;
		}
		Node *temp = front;
		front = front->next;
		delete temp;
		if (front == NULL)
		{
			rear = NULL;
		}
	}
	void display()
	{
		if (front == NULL)
		{
			std::cout << "Queue is empty\n";
			return;
		}
		Node *current = front;
		while (current != NULL)
		{
			std::cout << current->month << " " << current->year << " " << current->artist << " " << current->song << " " << current->label << " " << current->weeksAtNumberOne << "\n";
			current = current->next;
		}
	}
};

#endif // QUEUE_H
