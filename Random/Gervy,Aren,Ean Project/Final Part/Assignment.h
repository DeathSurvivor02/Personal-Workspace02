#ifndef __ASSIGNMENT__H__
#define __ASSIGNMENT__H__

#include <iostream>

using namespace std;

int menu();
void start_story();

const float MAX = 100;

class story_state_attributes
{
	public:
	double temp = 0.0 /* = health + experience + happiness */;
	double story_state_factor = 0.0;
	
	double health;
	double experience;
	double happiness;
	
};
class choice
{
	public:
	double health_increment;
	double experience_increment;
	double happiness_increment;
	char option;
	char option2;
};

class event
{
	public:

	float trigger_factor;

};
void update_attributes();
void second_story_arc();
#endif