/*
 * Create a class called Circle that contains three integer 
 * fields to store the x and y values of its centre and its radius.
 *  In the class include methods for setting and getting the x, y 
 * and radius values. Create another class called DrawDemo main 
 * method create two instances of the and include in it the Circle 
 * main method. Inside the class and set the values of each class 
 * accordingly. Also, include code that will retrieve those values 
 * and print them on the screen
 */

public class Circle {
	private int x;
	private int y;
	private int radius;

	//function

	public Circle(int x, int y, int radius)
	{
		this.x = x;
		this.y = y;
		this.radius = radius;
	}

	public void SETx(int x_value) {
		x = x_value;
	}

	public void SETy(int y_value) {
		y = y_value;
		y. = radius;
	}

	public void SETradius(int radius_value) {
		radius = radius_value;
	}

	public int GETx() {
		return (x);
	}

	public int GETy() {
		return (y);
	}

	public int GETradius() {
		return (radius);
	}
};

public class DrawDemo {
	public void main() 
	{
		Circle circle_1 = new Circle(10,21, 30 );
		Circle circle_2 = new Circle(15, 12, 30);

	}
}