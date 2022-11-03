#include <string>
#include <iostream>
#include "Student.h"
//using namespace Student;

//using namespace std;
//using namespace Student;
//using namespace Student;

Student::Student()
{
	setName();
	setID_number();
	setYears();
	setFees();
}
void Student::setName()
{
	std::string name;
	std::cout << "Please enter the name of the student" << std::endl;
	std::cin >> name;
	Name = name;

}
void Student::setID_number()
{
	int id;
	std::cout << "Please enter the ID number od the student" << std::endl;
	std::cin >> id;
	ID_number = id;
}
void Student::setYears()
{
	int years;
	std::cout << "Please enter the number of years the student has been at the university" << std::endl;
	std::cin >> years;
	Years = years;
}
void Student::setFees()
{
	double fees;
	std::cout << "Please enter the annual fees" << std::endl;
	std::cin >> fees;
	Fees = fees;
}
std::string Student::getName()
{
	return Name;
}
int Student::getYears()
{
	return Years;
}
int Student::getID_number()
{
	return ID_number;
}
double Student::getFees()
{
	return Fees;
}
double Student::calculateTotalFees()
{
	double totalfees;
	totalfees = Years * Fees;
	return totalfees;
}

