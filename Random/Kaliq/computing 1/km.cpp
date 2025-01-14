#include <iostream>
using namespace std;


int fun(int x=0, int y=2);

int main(){
	cout << fun(5);
	return 0;

}


int fun(int x, int y) 
{
	return (x+y);}