#include <stdexcept>
#include "MathStudent.h"

MathStudent::MathStudent(const string &studentName, const int studentID, int studentYears, double studentAnnualFees,
						 double studentTutorialFee)
	: Student(studentName, studentID, studentYears, studentAnnualFees)
{
	setTutorialFee(studentTutorialFee);
}

void MathStudent::setTutorialFee(double studentTutorialFee)
{
	if (studentTutorialFee < 0.0)
	{
		throw invalid_argument("Tutorial Fee must be >= 0.0");
	}
	tutorialFee = studentTutorialFee;
}

double MathStudent::getTutorialFee() const
{
	return tutorialFee;
}

double MathStudent::calculateTotalFees() const
{
	return Student::getYears() * (Student::getAnnualFees() + getTutorialFee());
}
