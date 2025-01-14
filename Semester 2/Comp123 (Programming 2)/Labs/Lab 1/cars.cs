using System;

class CarClass
{

	static void Main()
	{

	}
}
public class Car
{
	// public
	//Variables:
	private int year;
	private string model;
	private bool isDrivable;
	private double price;

	//Functions:


	//*Declarations:
	//~Constructor:
	public Car(string model, int year, double price, bool isDrivable = true)
	{
		this.model = model;
		this.year = year;
		this.isDrivable = isDrivable;
		this.price = price;
	}

	//Description: Converts the variables to string and returns them.
	public override string ToString()
	{
		return $"Model: {model}, Year: {year}, Price: {price}, Drivable: {isDrivable}";
	}

	
}