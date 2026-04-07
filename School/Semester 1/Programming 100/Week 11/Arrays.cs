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

// Description: Display the array elements normally
Console.WriteLine("\n\nArray elements: ");
for (int i = 0; i < count_Bynoe; i++)
{
    Console.WriteLine(array_Ean[i]);
}

// Description: Display the array elements in reverse order
Console.WriteLine("\n\nArray elements in reverse order: ");
Array.Reverse(array_Ean);
for (int i = 0; i < count_Bynoe; i++)
{
    Console.WriteLine(array_Ean[i]);
}

//Description Display in ascending order
Console.WriteLine("\n\nArray elements in ascending order: ");
Array.Sort(array_Ean);
for (int i = 0; i < count_Bynoe; i++)
{
    Console.WriteLine(array_Ean[i]);
}