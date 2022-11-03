#include <iostream>
#include <iomanip>
#include "CSStudent.h" 
#include "MathStudent.h"  

int main() {
    CSStudent csstudent1("CS Student 1", 12341234, 2, 5.5, 200.21);
    MathStudent mathstudent1("Math Student 1", 24682468, 3, 5.5, 25.9);

    cout << "csstudent1: " << csstudent1.calculateTotalFees() << endl;
    cout << "mathstudent1: " << mathstudent1.calculateTotalFees() << endl;
}
