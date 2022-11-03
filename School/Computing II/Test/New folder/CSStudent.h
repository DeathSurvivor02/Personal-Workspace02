#ifndef CSSTUDENT_H
#define CSSTUDENT_H

#include "Student.h" 

class CSStudent : public Student
{
public:
    CSStudent(const string&, const int, int, double, double);

    void setLaptopFee( double ); 
    double getLaptopFee() const; 

    double calculateTotalFees() const; 
private:
    double laptopFee; 
}; 

#endif
