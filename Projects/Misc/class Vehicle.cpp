/* class Vehicle
{
	Doors()
	{
		int doors = 0;
		cout << "How many doors do you have?" << endl;
		cin >> doors;
	};
	Windows();
	Vehicle();
};

Vehicle::Vehicle()
{
	int doors, windows = 4;
	Doors();
	Windows();
}

int main()
{
	Vehicle mercedes;

} */

#include <iostream>

// Base class
class Shape
{
public:
	Shape(int w, int h)
	{
		width = w;
		height = h;
	}

protected:
	int width;
	int height;
};

// Derived class
class Rectangle : public Shape
{
public:
	Rectangle(int w, int h) : Shape(w, h)
	{
		// Additional initialization for Rectangle class
	}
	int getArea()
	{
		return (width * height);
	}
};

int main()
{
	Rectangle rect(5, 7);

	// Print the area of the object.
	std::cout << "Total area: " << rect.getArea() << std::endl;

	return 0;
}
