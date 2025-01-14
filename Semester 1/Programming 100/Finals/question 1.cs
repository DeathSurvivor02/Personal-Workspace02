// Date: December 11, 2024
// Name: Ean Bynoe

//Description: Prompt the user for First name, last 2 digits of your student number
Console.Write("Enter your First Name:");
string firstName = Console.ReadLine();
Console.Write("Enter the last 2 digits of your Student Number: ");
int studentNumber = Convert.ToInt32(Console.ReadLine());

// Description: Calculates and Prints whether or not the number is even or odd
if (studentNumber % 2 == 0)
{
    Console.WriteLine($"Hi {studentNumber}, the enter number is even");
}
else
{
    Console.WriteLine($"Hi {firstName}, the enter number is odd");
}

Console.WriteLine("This program will perform search operation in an Integer array:");

//~ Part 2:
// Description: Prompt for the size of an integer array
Console.Write("Enter the array count: ");
int arrSize = Convert.ToInt32(Console.ReadLine());
int[] arr = new int[arrSize];
for (int i = 0; i < arrSize; i++)
{
    Console.Write($"Enter array element {i + 1}: ");
    arr[i] = Convert.ToInt32(Console.ReadLine());
}

// Description: Makes the loop condition true before it starts
bool loop = true;
while (loop)
{
    // Description: Prompts for the number that is to be searched
    Console.Write("Enter the number to be searched: ");
    int searchNumber = Convert.ToInt32(Console.ReadLine());

    int count = 0; //!Stores the array position if the value is found
    bool found = false; //!Makes sures there's a condition to see if the loop finds the value on not when it is completed
    while (count < arrSize)
    {
        if (searchNumber == arr[count])
        {
            found = true;
            break;
        }
        else
        {

            found = false;
            count++;
        }
    }
    if (!found)
        Console.WriteLine($"Number {searchNumber} is not found");
    else
        Console.WriteLine($"Number {searchNumber} is found in the array at position {count + 1}");

    Console.Write("Do you want to do search again(Y/N):");
    string condition = Console.ReadLine();
    if (condition == "y" || condition == "Y")
        loop = true;
    else
        loop = false;
}

Console.WriteLine($"Thank you, {firstName}, Part 1 of Final Assignment is done, best wishes for your Part 2.");