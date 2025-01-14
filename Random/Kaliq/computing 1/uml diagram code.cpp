#include <iostream>
#include <string>

using namespace std;
int main()
{
	string name;
	int years;
	Doctor aDoctor;
	name = Doctor.setName();
	years = Doctor.setYears();
	Doctor bDoctor.Doctor("This nigger", 1941);
	return 0;
}

class Doctor // class
{
private:
	string name;
	int years;

public:
	Doctor();						//? Normal constructor
	Doctor(string name, int years); //*Predefined constructor
	void setName(string name)
	{
		std::cout "what is your name?";
		cin >> name;
	}
	void setYears(int Year);
	string getName();
	int getYears(){return years;}
	void treatPatient();
	void displayDoctor();
}

Doctor::Doctor()
{
	setName(name);
	setYear(years);
	cout << getName();
	treatPatient(); // unknown
	displayDoctor();
}

Doctor::Doctor(name, Year)
{
	treatPatient(); // unknown
	displayDoctor();
}
void Doctor::setName()
{
	cout << "what is your name?" << endl;
	cin >> name;
}
string Doctor::getName()
{
	return name;
}
void Doctor::setYears()
{
	cout << "how old are you?" << endl;
	cin >> years;
}
string Doctor::getYears()
{
	return years;
}