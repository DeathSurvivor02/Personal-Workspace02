#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	string month;
	int year;
	string artist;
	string song;
	string label;
	int weeksAtNumberOne;

	Node *next;

	Node(string month, int year, string artist, string song, string label, int weeksAtNumberOne)
	{
		this->month = month;
		this->year = year;
		this->artist = artist;
		this->song = song;
		this->label = label;
		this->weeksAtNumberOne = weeksAtNumberOne;
		this->next = NULL;
	}

	void setMonth(string month) { this->month = month; }
	void setYear(int year) { this->year = year; }
	void setArtist(string artist) { this->artist = artist; }
	void setTitle(string song) { this->song = song; }
	void setLabel(string label) { this->label = label; }
	void setWeeks(int weeksAtNumberOne) { this->weeksAtNumberOne = weeksAtNumberOne; }
	void setNext(Node *ptr) { next = ptr; }

	string getMonth() { return month; }
	int getYear() { return year; }
	string getArtist() { return artist; }
	string getLabel() { return label; }
	string getSong() { return song; }
	int getWeeks() { return weeksAtNumberOne; }
	Node *getNext() { return next; }
	string getRecord();

	Node()
	{
		month = "";
		year = -1;
		artist = "";
		label = "";
		label = "";
		weeksAtNumberOne = -1;
		next = NULL;
	}
};
    string Node::getRecord()
	{
	   
    	string str = "";
		str.append(getMonth());
		str.append("\t");
		str.append(to_string(getYear()));
		str.append("\t");
		str.append(getArtist());
		str.append("\t");
		str.append(getLabel());
		str.append("\t");
		str.append(getSong());
		str.append("\t");
		str.append(getLabel());
		str.append("\t");
		str.append(to_string(getWeeks()));

		return str;
	}
#endif // NODE_H
