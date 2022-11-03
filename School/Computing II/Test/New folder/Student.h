#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
    public:
    Student(const string&, const int, int, double);

    void setYears(int);  
    int getYears() const; 

    void setAnnualFees(double);
    double getAnnualFees() const;

    double calculateTotalFees() const; 

private:
    string name;
    int ID;
    int years;
    double annualFees;
	
}; 

#endif
