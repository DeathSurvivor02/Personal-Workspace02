/*
    *Date: 12th Dec, 2024
    * Name: Ean Bynoe
    * Student #: 301390261 
    * This program asks for the Last name of the user and their birth year
    * It then calls  a method with a passed parameter to ask for the first name and then concatenates the first and last name
    * It then calls another method with a passed parameter to check if the birth year is a leap year and if it is an even or odd year
 */

class FinalExam
{
    void Main()
    {

        //Variables (Initialization):
        Console.Write("Enter your Last Name: ");
        string Bynoe = Console.ReadLine();
        Console.Write("Enter your Birth year: ");
        int iBYBynoe = Convert.ToInt32(Console.ReadLine());
        bool leapYear = false;
        bool evenOddYear = false;

        //Description: Calling methods:
        EanBynoeMethod1(Bynoe);
        BynoeEanMethod2(iBYBynoe, out leapYear, out evenOddYear);

        //Description: Checking if birth year is a leap year and if it is even or odd
        if (leapYear)
            Console.WriteLine("Your birth year is a leap year");
        else
            Console.WriteLine("Your birth year is not a leap year");
        if (evenOddYear)
            Console.WriteLine("Your birth year is an even year");
        else
            Console.WriteLine("Your birth year is an odd year");
    }
}
void EanBynoeMethod1(string Bynoe)
{
    Console.Write("Enter your First Name: ");
    string firstName = Console.ReadLine();
    Bynoe = firstName + " " + Bynoe;
    Console.WriteLine("Your full name is: " + Bynoe);
}


void BynoeEanMethod2(int iBYBynoe, out bool leapYear, out bool evenOddYear)
{
    if (iBYBynoe % 2 == 0)
        evenOddYear = true;

    else
        evenOddYear = false;

    if (iBYBynoe % 4 == 0)
        leapYear = true;
    else
        leapYear = false;

}
