using System;

class PrimeNumbers
{
    static void Main()
    {
        Console.WriteLine("Enter the range to find prime numbers:");
        Console.Write("Start number: ");
        int start = Convert.ToInt32(Console.ReadLine());

        Console.Write("End number: ");
        int end = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine($"\nPrime numbers between {start} and {end} are:");

        for (int num = start; num <= end; num++)
        {
            if (IsPrime(num))
            {
                Console.Write(num + " ");
            }
        }

        Console.WriteLine("\n\nProgram completed!");
    }

    // Function to check if a number is prime
    static bool IsPrime(int number)
    {
        if (number < 2)
        {
            return false; // Numbers less than 2 are not prime
        }

        for (int i = 2; i <= Math.Sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return false; // If divisible by any number, not prime
            }
        }

        return true; // Prime if no divisors found
    }
}
