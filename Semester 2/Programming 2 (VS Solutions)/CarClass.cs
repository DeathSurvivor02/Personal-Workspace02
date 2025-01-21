using System;

public class Car
{
    //Variables:
    int year;
    string model;
    bool isDrivable;
    double price;

    public Car1(string model int year, double price, bool isDrivable = true)
	{
		this.model = model;
        this.year = year;
        this.isDrivable = isDrivable;
        this.price = price;
    }

    public override string ToString()
    {
        return $"Model: {model}, Year: {year}, Price: {price}, Drivable: {isDrivable}";
    }
}
