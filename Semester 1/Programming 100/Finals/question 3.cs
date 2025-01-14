// Description:  Main function stores all the data together, calls all other function (more like in c++)
void Main()
{
    string Fname;
    string Lname;
    int ID;
    int display = 0;
    StudentInfo(out Fname, out Lname, out ID);
    StudentDisplay(Fname, Lname, ID);
    DecorationDisplay(3);

}

// Function: returns 3 different values into their parental counterparts in the Main() function
void StudentInfo(out string firstName, out string lastName, out int studentNumber)
{
    int display = 1;
    Console.WriteLine("Enter Student Information:");
    DecorationDisplay(display);
    Console.Write("Enter your First Name: ");
    firstName = Console.ReadLine();

    Console.Write("Enter your Last Name: ");
    lastName = Console.ReadLine();

    Console.Write("Enter your Student Number: ");

    studentNumber = Convert.ToInt32(Console.ReadLine());
}

// Description:  takes values from the Main() but does not edit them externally, while displaying the student's information
void StudentDisplay(string firstName, string lastName, int studentNumber)
{
    int display = 2;
    Console.WriteLine("Student's Information:");
    DecorationDisplay(display);
    Console.WriteLine($"Student's full name: {firstName} {lastName}");
    Console.WriteLine($"Registration Number: {studentNumber}");
}

// Description: a function to display the 'decoration within the code, while using case tools
void DecorationDisplay(int value)
{
    switch (value)
    {
        case 1:
            for (int i = 0; i <= 30; i++)
            {
                Console.Write("=");
            }
            Console.WriteLine();
            break;
        case 2:
            for (int i = 0; i <= 29; i++)
            {
                Console.Write("+");
            }
            Console.WriteLine();
            break;
        case 3:
            for (int i = 0; i <= 30; i++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
            break;
    }
}
Main();