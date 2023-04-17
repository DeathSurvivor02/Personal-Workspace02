#include "CSStudent.h"
void CSStudent::setlaptop_fee()
{
	double fee;
	std::cout << "Please enter the laptop fee" << std::endl;
	std::cin >> fee;
	Laptop_fee = fee;
}
double CSStudent::getLaptop_fee()
{
	return Laptop_fee;
}
CSStudent::CSStudent()
{

	//Student();
	calculateTotalFees();
}
double CSStudent::calculateTotalFees(){
	return Student::calculateTotalFees() + Laptop_fee;
}
