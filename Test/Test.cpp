#include <iostream>
#include "Student.h"
// #include "Student.cpp"
#include "CSStudent.h"
// #include "CSStudent.cpp"
#include "MathStudent.h"
// #include "MathStudent.cpp"
using namespace std;
int main()
{
    Student Stud;
    std::cout << "The total cost for a normal Student is $" << Stud.calculateTotalFees() << std::endl;
    std::cout << "-----------" << std::endl;
    CSStudent CStud; 
    std::cout << "The total cost for a CS Student is $" << CStud.calculateTotalFees() << std::endl;
    std::cout << "-----------" << std::endl;
    MathStudent MStud;

    std::cout << "The total cost for a Math Student is $" << MStud.calculateTotalFees() << std::endl;
    std::cout << "-----------" << std::endl;
	return 0;
}