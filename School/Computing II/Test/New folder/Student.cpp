#include <stdexcept>
#include "Student.h"
using namespace std;

Student::Student(const string &studentName, const int studentID, int studentYears, double studentAnnualFees)
	: name(studentName), ID(studentID)
{
	setYears(studentYears);
	setAnnualFees(studentAnnualFees);
}

void Student::setYears(int studentYears)
{
	if (studentYears < 0)
	{
		throw invalid_argument("Years must be >= 0");
	}
	years = studentYears;
}

int Student::getYears() const
{
	return years;
}

void Student::setAnnualFees(double studentAnnualFees)
{
	if (studentAnnualFees < 0.0)
	{
		throw invalid_argument("studentAnnualFees must be >= 0.0");
	}
	annualFees = studentAnnualFees;
}

double Student::getAnnualFees() const
{
	return annualFees;
}

double Student::calculateTotalFees() const
{
	return getYears() * getAnnualFees();
}
