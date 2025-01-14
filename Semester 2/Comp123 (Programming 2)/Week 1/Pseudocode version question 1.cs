using System;

class PrimeNUmbers
{
	public static void Main()
	{
		Console.WriteLine("Enter the range to find the prime numbers");

		Console.WriteLine("Enter the start value: ");
		int start = Convert.ToInt32(Console.ReadLine());

		Console.WriteLine("Enter the end value: ");
		int end = Convert.ToInt32(Console.ReadLine());

		Console.WriteLine($"The prime numbers between {start} and {end} are: ");
		for (int i = start; i <= end; i++)
		{
			if (IsPrime(i))
			{
				Console.Write($"{i} ");
			}

			// Console.WriteLine();


		}


		// Function: Checks to see if the number passed through is prime or not
		static bool IsPrime(int number)
		{
			if (number < 2)
			{
				return false;
			}
			for (int i = 2; i <= Math.Sqrt(number); i++)
			{
				if (number % i == 0)
				{
					return false;
				}
			}
			return true;  //~ if not divisible by any number, makes it prime
		}
	}
}