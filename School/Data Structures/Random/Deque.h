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
	void enqueueHead(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			head->setNext(temp);
			head->temp;
		}
	}
	void enqueueTail(std::string month, int year, std::string artist, std::string song, std::string label, int weeksAtNumberOne)
	{
		Node *temp = new Node(month, year, artist, song, label, weeksAtNumberOne);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->setNext(temp);
			tail->temp;
		}
	}
	string dequeueHead()
	{
		string temp;
		if (head == NULL && tail == NULL)
		{
			return << "Deque is empty\n";
		}

		else if (head == tail)
		{
			temp = head->getRecord();
			delete head;
			head = tail = NULL;
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
		delete temp;
	}

	string dequeueTail()
	{
		if (head == NULL)
		{
			return << "Deque is empty\n";
		}
		if (tail != NULL)
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			Node *tempPtr = head;
			while (tempPtr->getNext() != tail)
			{
				tempPtr = tempPtr->getNext();
				tempPtr->setNext(NULL);
				delete tail;
				tail = tempPtr;
			}
		}
		return temp;
	}

	string showHead()
	{
		if (head == NULL)
		{
			return "Deque is empty.";
		}
		else
			return tail->getRecord();
	}

	string showAll()
	{
		if (head == NULL)
		{
			return "Deque is empty.";
		}
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
};

#endif // DEQUE_H
