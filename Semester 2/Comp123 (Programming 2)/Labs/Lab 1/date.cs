using System;

class DateClass
{
	static void Main(string[] args)
	{

	}
}

public class Date
{
	//Variables:
	int day = 1;
	int month = 1;
	int year = 2022;

	//Functions:
	public string ToString();
	void Add(int days);
	void Add(int month, int days);
	// void Add();

	//Constructor:
	public Date(int day, int month, int year)
	{
		this.day = day;
		this.month = month;
		this.year = year;
	}

	public override string ToString()
	{
		return ($"Days: {day}, Month: {month}, Year: {year}");
	}
}
