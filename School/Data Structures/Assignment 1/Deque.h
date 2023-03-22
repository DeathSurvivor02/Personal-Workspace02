#ifndef __Deque__H
#define __Deque__H

import java.util.Deque;

package methods;
#include <iostream>
#include <String.h>
using namespace std;


class Deque
{
	private:
		Node *head;
		Node *tail;
	public:
		Dequeu();
		void enqueueHead(string)
		void enqueueTail(string)
		string dequeueHead();
		string dequeueTail();
		string showHead();
		string showTail();
		string showAll();	
		bool find(string);
};


Deque::Dequeu()
{
	head = tail = NULL;

}

void Dequeue::enqueueHead(string value) //enqueue
{
	Node *temp = new Node(value);
	if (head == NULL && tail == NULL) //check if empty
	{
		head = tail = temp; //set head and tail to point to new node
	}
	else 
	{
		temp -> setNext(head); //set next pointer in temp to old head (deque)
		head = temp; //set head to new node/head

	}
}

void Dequeue::enqueueTail(string value) //enqueue tail
{
	Node *temp = new Node(value);
	if (head == NULL && tail == NULL)
	{
		head = tail = temp;
	}
	else
	{
		temp -> setNext(tail); //set next pointer in temp to old head
		tail = temp; //set tail to point to new node
	}	
}

string Deque::dequeueHead()
{
	string temp;
	if (head ==NULL && tail == NULL)
	{
		return ("Deque is empty");
	}
	else 
	{
		if (head ==tail) //only if it had 1 node
		{
			temp = head -> tail;
			delete head;
			head = tail - NULL;
			return temp;
		}
		else
		{
			temp = head -> getValue();
			Node *remove = head;
			head = head -> getNext();
			delete remove;
			return temp;
		}
	}
}

string Deque::dequeueTail()
{
	string temp;
	if (head == NULL && tail == NULL)
	{
		return("Deque is empty");
	}
	else 
	{
		if (head == tail) //only if it had 1 node
		{
			temp = tail -> head;
			delete tail;
			tail = head - NULL;
			return temp;
		}
		else 
		{
			temp = tail -> getValue();
			Node *remove = tail;
			tail = tail -> getNext();
			delete remove;
			return temp;
		}
	}
}

bool Deque::find(string value)
{
	if (head == NULL && tail == NULL)
		return false;
	Node* temp = head;
	while (temp == NULL && temp -> getValue() != value)
	{
		temp = temp -> getNext();
	}
	if (temp == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string Deque::showHead()
{
	// string temp;
	if (head == NULL && tail == NULL)
	{
		return "Deque is empty!";
	}
	else
	{
		return head -> getValue();
	}
}

string Deque::showTail()
{
	// strnig temp;
	if (tail == NULL && head == NULL)
	{
		return "Deque is empty!";
	}
	else
	{
		return tail -> getValue();
	}
}

string Deque::showAll()
{
	string temp;
	if (head == NULL && tail == NULL)
	{
		return "Deque is empty!";
	}
	Node *temp head;
	while (temp != NULL)
	{
		all += temp -> getValue();
		all += "+";
		temp = temp -> getNext();
	}
}


#endif	