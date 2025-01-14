/*
* Name: Ean Bynoe
* Date: October 17, 2024
* Week 11: Arrays
*Description: Takes the input from the user and displays the array in normal, reverse and ascending order
*/


//Description: Prompts the user to enter the total numbers in the array
Console.WriteLine("Enter array count value: ");
int count_Bynoe = Convert.ToInt32(Console.ReadLine());

// Description: Create an array of size from he user input
int[] array_Ean = new int[count_Bynoe];
Console.WriteLine($"\n\nEnter {count_Bynoe} array items: ");


for (int i = 0; i < count_Bynoe; i++)
{
    array_Ean[i] = Convert.ToInt32(Console.ReadLine());
}

// Description: Display the array in normal order
Console.WriteLine("\n\nArray elements: ");
for (int i = 0; i < count_Bynoe; i++)
{
    Console.WriteLine(array_Ean[i]);
}

// Description: Display the array in reverse order using while loop
count_Bynoe2 = count_Bynoe;
Console.WriteLine("\n\nArray elements in reverse order: ");
while (count_Bynoe2 > 0)
{
    Console.WriteLine(array_Ean[count_Bynoe - 1]);
    count_Bynoe2--;
}

// Description: Display the array in ascending order using do-while loop
count_Bynoe2 = count_Bynoe;
Console.WriteLine("\n\nArray elements in ascending order: ");
Array.Sort(array_Ean);
do
{
    Console.WriteLine(array_Ean[count_Bynoe - count_Bynoe2]);
    count_Bynoe2--;
} while (count_Bynoe2 > 0);