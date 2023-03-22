#ifndef PQUEUE_H
#define PQUEUE_H

#include "Node.h"

class PQueue
{
private:
	Node *head;

public:
	PriorityQueue()
	{
		head = NULL;
	}
	void insert(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = temp;
			return;
		}
		if (temp->getWeeks() > head->getWeeks())
		{
			temp->setNext(head);
			head = temp;
			return;
		}
		Node *previous = head;
		Node *current = head->getNext();

		while (current != NULL && current->getWeeks() > temp->getWeeks())
		{
			previous = current;
			return;
		}
		temp->setNext(current);
		previous->setNext(temp);
		return;
	}
	void dequeue()
	{
		if (head == NULL)
		{
			std::cout << "Priority Queue is empty\n";
			return;
		}
		Node ptr = head;
		string str = head->getRecord();

		delete ptr;
		return str;
	}
	string getAllrecords()
	{
		if (head == NULL)
			return "The priority queue is empty";
		Node* ptr = head;
		string str = "";
		while (ptr != NULL)
		{
			str.append(ptr->getRecord());
			str.append("\n");
			ptr = ptr->getNext();
		}

		return str;
	}
	string getFront()
	{
		if (head == NULL)
		{
			return "The priority queue is empty";
		}
		return head->getRecord();
	}
	string getLast()
	{
		if(head == NULL)
		{
			return "The priority queue is empty";
		}
		Node* ptr = head;
		while (ptr -> getNext() != NULL)
		{
			ptr = ptr -> getNext();
		}
		return (ptr -> getRecord());
	}
	void purge() { head = NULL; }
};

#endif // PQUEUE_H
