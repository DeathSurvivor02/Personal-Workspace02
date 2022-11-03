#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H

#include "Student.h" 

class MathStudent : public Student
{
public:
    MathStudent(const string&, const int, int, double, double);

    void setTutorialFee( double ); 
    double getTutorialFee() const; 

    double calculateTotalFees() const; 
private:
    double tutorialFee; 
}; 

#endif
