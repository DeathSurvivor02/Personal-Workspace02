/*Name: Ean Bynoe
*Date: November 27, 2024
*Student Number: 301390261
*Description: Purpose of the code is to prompt the user to enter count of array elements. 
*             Count value is between >5 and <10 will be accepted. The array will be searched for a
*              value and confirm if the value is in the array, along with it's location
*/
//Prompting and accepting count
int BynoeCount;
Console.WriteLine("Please enter the array count value: ");
BynoeCount = Convert.ToInt32(Console.ReadLine());

//Array size which is allowed is in range
if (BynoeCount > 5 && BynoeCount < 10)
{
    //Creating array
    int[] EanArray = new int[BynoeCount];

    //Inputing the array items
    Console.WriteLine($"Please enter {BynoeCount} array items");
    for (int i = 0; i < BynoeCount; i++)
    {

        EanArray[i] = Convert.ToInt32(Console.ReadLine());
    }

    //Space for code comprehension
    Console.WriteLine("");

    //Displaying array
    foreach (var item in EanArray)
    {
        Console.WriteLine(item);
    }

    //Creating value to search, and finding it's index
    int search;
    int index;
    Console.WriteLine("Enter a value to search: ");
    search = Convert.ToInt32(Console.ReadLine());

    //Position of value = index + 1 which is index++
    index = Array.BinarySearch(EanArray, search);
    index++;

    //If the index is less than zero, the value is not present in the array
    if (index < 0)
    {
        Console.WriteLine($"The value {search} is not present in the array");
    }
    //If the index is greater than or equal to zero, the value is present in the array
    else
    {
        Console.WriteLine($"The value {search} is present in the array at location {index}");
    }
}

//Array size which is allowed is not in range
else
{
    Console.WriteLine("Invalid count value");
}