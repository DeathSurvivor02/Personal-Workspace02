#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <vector>
class SetNode
{
private:
	string month[10];
	int year;
	string artist[50];
	string title[50];
	string label[15];
	int numweeks;

	/* meh: he explained something and replaced all of the chars to string */
	// todo: variables should be stored in vectors

public:
	// constructor
	SetNode(string, int, string, string, string, int);

	// functions: accessors
	string getAllData();
	string getMonth(){return month}
	int getYear(){return year;}
	string getArtist(){return artist;}
	string getTitle(){return title;}
	string getLabel(){return label;}
	// functions: mutators
};

SetNode::SetNode(string mon, int yr, string singer, string song, string recordLabel, int weeks)
{
	month = mon;
	year = yr;
	artist = singer;
	title = song;
	label = recordLabel;
	numweeks = weeks;
}
string SetNode::getAllData()
{
	string str = month;
	str.append(, );
	str.append(to_string(year) + ", ");
	str.append(artist+ ", ");
	str.append(title+ ", ");
	str.append(label+ ", ");
	str.append(to_string(numweeks) );

}

class Set
{
	private:
	// need to have a container (vector)
	vector <setNode> elements;

	public:
	Set(){elements.resize(0);/*lets the vector start at size 0*/}

	// functions: mutators
	void add(string, int, string, stirng, string, int );


	// functions: accessors
	bool find(string);
};

bool Set::Find(string song)
{
	// strcmp(s1,s2);//compares two strings 
	/* in bool 0 is false */
	// if (!s1.compare(s2)); // returns 0 if true
	for(int x=0;x<elements.size();x++)
	{
		if (strcmp(song,elements[x])-> getTitle() == 0)   /* if(!song.compare(elements[x])) */
		{
			return true;
		}
	}
	return false;
}

void Set::add(string mon, int yr, string singer, string song, string recordLabel, int weeks)
{

}