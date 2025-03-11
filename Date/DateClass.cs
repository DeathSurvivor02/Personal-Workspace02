

namespace DateClass;

public class DateClass
{
	//Variables:
	private int day;
	private int month;
	private int year;



	//Constructor:
	public DateClass(int day, int month, int year)
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

	public void Add(int day)
	{
		this.day += day;
		Normalize();
	}

	public void Add(int days, int month)
	{
		this.day += days;
		this.month += month;
		Normalize();
	}

	public void Add(DateClass other)
	{
		this.day += other.day;
		this.month += other.month;
		this.year += other.year;

		Normalize();

	}

	public void DateWord()
	{
		switch (this.month)
		{
			case 1:
				Console.WriteLine($"{day} January {year}");
				break;
			case 2:
				Console.WriteLine($"{day} February {year}");
				break;
			case 3:
				Console.WriteLine($"{day} March {year}");
				break;
			case 4:
				Console.WriteLine($"{day} April {year}");
				break;
			case 5:
				Console.WriteLine($"{day} May {year}");
				break;
			case 6:
				Console.WriteLine($"{day} June {year}");
				break;
			case 7:
				Console.WriteLine($"{day} July {year}");
				break;
			case 8:
				Console.WriteLine($"{day} August {year}");
				break;
			case 9:
				Console.WriteLine($"{day} September {year}");
				break;
			case 10:
				Console.WriteLine($"{day} October {year}");
				break;
			case 11:
				Console.WriteLine($"{day} November {year}");
				break;
			case 12:
				Console.WriteLine($"{day} December {year}");
				break;
		}
	}

	public void Normalize()
	{
		while ((month > 12) || (day > 31))
		{

			switch (month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					if (day > 30)
					{
						day -= 30;
						month++;
					}
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					if (day > 31)
					{
						day -= 31;
						month++;
					}
					break;
				case 2:
					if ((day > 29) && (year % 4 == 0))
					{
						day -= 29;
						month++;
					}
					else if (day > 28)
					{
						day -= 28;
						month++;
					}
					break;
			}

		}
	}

}
