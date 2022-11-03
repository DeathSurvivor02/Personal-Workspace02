#include <iostream>
#include <iomanip>
#include "Mansion.h" 


int main() {
    Mansion Mansion("Address Location", 1234, 1500.99, 500.5, 200.21);
    std::cout << "Mansion: " << Mansion.calculatePrice() << std::endl;
    
}