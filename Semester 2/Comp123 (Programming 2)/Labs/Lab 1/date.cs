using System;

// class DateClass
{
	static void Main(string[] args)
	{
		Date birthday = new Date(9,10,2002);
		Console.WriteLine(birthday.ToString);

	}
}

public class Date
{
	//Variables:
	int day = 1;
	int month = 1;
	int year = 2022;

	//Constructor:
	public Date(int day, int month, int year)
	{
		this.day = day;
		this.month = month;
		this.year = year;
	}

	//Functions:
	public override string ToString()
	{
		return ($"Days: {day}, Month: {month}, Year: {year}");
	}
	public void Add(int days)
	{
		day += days;
	}
	public void Add(int days, int month)
	{
		this.month += month;
		day += days;
	}
	
	public void Add(Date other)
	{
		day += other.day;
		month += other.month;
		year += other.year;
	}
	public void Normalize()
	{
		//Todo: Use switch case instead of if statement
		if((day > 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
		{
			day -=31;
			month++;
		}
		if ((day > 30) && (month ==4||month ==6 || month == 9 || month == 11)) 
		{
			day -=30;
			month++;
		}

		if ((day == 29) && (month > 2) && (year%4 == 0))
		{
			day -= 29;
			month++;
		}
		if ((day > 28) && (month == 2) && (year%4 != 0))
		{
			day -= 28;
			month++;
		}
		while(month > 12)
		{
			month -=12;
			year++;
		}
	}
}
