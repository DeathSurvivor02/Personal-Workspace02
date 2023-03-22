/**
 * @file CSStudent.cpp
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:  
 * @version 1.0
 * @date 2023-02-06 09:07:42
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdexcept>
#include "CSStudent.h"

/**
 * @brief:  Construct a new CSStudent::CSStudent object
 * 
 * @param studentName 
 * @param studentID 
 * @param studentYears 
 * @param studentAnnualFees 
 * @param studentLaptopFee 
 *  @author: Ean Bynoe  
 */
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
