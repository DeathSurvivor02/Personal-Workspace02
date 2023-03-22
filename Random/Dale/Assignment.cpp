#include <iostream>
#include <string>

using namespace std;

//error                                  
//optimize Check discord to see the link for this
// error message						 



class Aeroplane
{
public:
	Aeroplane(); //constructor without parameters
	Aeroplane(string m, int s); //constructor with parameters
	
	void setModel(string m)
	{
        model = m;
    }
	void setSeats(int s)
	{
		seats = s;
	}
	string getModel()
	{
		return model;
	}
	int getSeats()
	{
        return seats;
    }
	void displayAeroplane()
	{
        cout << "Model: " << getModel() << endl;
		cout << "Seats: " << getSeats() << endl;
	}



private:
	string model;
	int seats;
};

Aeroplane::Aeroplane(string m, int s)
{

	string getSeats();
	string getModel();

	
}
Aeroplane::Aeroplane()
{
	setModel(string m);
	setSeats(int s);


}
int main()
{

	class Aeroplane aeorplane; //instanciate
	class Aeroplane aeorplane("modelplane", 120);
	
	return 0;
}