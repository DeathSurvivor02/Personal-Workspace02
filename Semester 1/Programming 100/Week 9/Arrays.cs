/*
    *Date: 7th Nov, 2024
    * Name: Ean Bynoe
    * Student #: 301390261
*/

/* 
    * This Program is a console-based program that will prompt the user to enter his/her name and age.
    * Using a while loop display all the ODD numbers in their age.
    * Using a do-while loop display all the EVEN numbers in their age
    * Using a for loop display the sum of the series up to the age value
 */

//Variables (Initialization):
string lastName = "";
int age = 0;
int odd = 0;
int even = 0;
int sum = 0;


//Output: Prompts the user to enter their name and age
//Input: Stores the value within one of the variables from above
Console.WriteLine("Enter your Last Name: ");
lastName = Console.ReadLine();

Console.WriteLine("Enter your age: ");
age = Convert.ToInt32(Console.ReadLine());


//Description: While Loop
while (odd < age)
{
    //Conditional: Check if the number is odd
    if (age % 2 != 0)
    {
        //Output: Display the odd number
        Console.WriteLine(odd);
    }
    odd++;
}
//Description: Do-While Loop
do 
{
    //Conditional: Check if the number is even
    if (age % 2 == 0)
    {
        //Output: Display the even number
        Console.WriteLine(age);
    }
    even++;
} while (even < age);

//Description: For Loop
Console.WriteLine("Using for loop:");
for (int i = 0; i <= age; i++)
{
        sum += i;
}
Console.WriteLine($"Sum of the series from 1 to {age} is {sum} ");