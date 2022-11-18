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
	float temp = health + experience + happiness;
	float story_state_factor = (temp/MAX) * 1.0;
	
	float health = 0.0;
	float experience = 0.0;
	float happiness = 0.0;
	
};
class choice
{
	public:
	float health_increment;
	float experience_increment;
	float happiness_increment;
};

class event
{
	public:

	float trigger_factor = 0.0;

};
void update_attributes();
void second_story_arc();
#endif