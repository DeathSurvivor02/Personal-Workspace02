/*Comments:
*
*Date Created: 14/11/2024
*Name: Ean Bynoe
*Student Number: 301390261
*
*Description: This program prompts the user for the student number and last name.
*               It then displays the last two digits of the student number.
*               It then displays all numbers from 0 to the last two digits that are divisible by 5 using a while loop.
*               It then displays all numbers from 0 to the last two digits that are divisible by 10 using a do-while loop.
*               It then displays the sum of all numbers from 0 to the last to digits of the student number
*/

//Variables:
string IName_Satish;
int stuNuber_Anisha;
int final;
int count = 0;
int sum = 0;

//Input: asks the user for the student number and last name
Console.WriteLine("Enter your last name: ");
IName_Satish = Console.ReadLine();

Console.WriteLine("Enter your student number: ");
stuNuber_Anisha = Convert.ToInt32(Console.ReadLine());
final = stuNuber_Anisha % 100;
Console.WriteLine($"Hi {IName_Satish}, last two digits of your student number is {final}.");

//Description: While loop
Console.WriteLine("Displaying divisible of 5 using while loop:");
while (count <= final)
{
    if ((count % 5 == 0) &&( count != 0))
    {
        Console.WriteLine(count);
    }
    count++;
}

count = 0;

//Description: do-while loop    
Console.WriteLine("Displaying divisible of 10 using do-while loop:");
do
{
    if ((count % 10 == 0) && (count != 0))
    {
        Console.WriteLine($"{count}");
    }
    count++;
} while (count <= final);


//Description: for loop
Console.WriteLine($"Displaying the sum of series from 1 to {final} using for loop:");
for (int i = 0; i <= final; i++)
{

        sum += i;
}
Console.WriteLine(sum);


