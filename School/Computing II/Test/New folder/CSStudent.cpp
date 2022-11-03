#include <stdexcept>
#include "CSStudent.h"

    CSStudent::CSStudent(const string &studentName, const int studentID, int studentYears, double studentAnnualFees, 
    double studentLaptopFee)
    : Student(studentName, studentID, studentYears, studentAnnualFees)
    {
        setLaptopFee(studentLaptopFee);
    }
    
    void CSStudent::setLaptopFee(double studentLaptopFee)
    {
        if (studentLaptopFee < 0.0) 
        {
          throw invalid_argument("Laptop Fee must be >= 0.0");
        }
        laptopFee =  studentLaptopFee;
    }

     double CSStudent::getLaptopFee() const
    {
        return laptopFee;
    } 

     double CSStudent::calculateTotalFees() const
    {
        return Student::calculateTotalFees() + getLaptopFee();
    } 
