// Description: Prompts for the Last name of the user
Console.Write("Enter your Last Name: ");
string lastName = Console.ReadLine();
// Description: Prompts for the student of the user
Console.Write("Enter your student number: ");
int studentNumber = Convert.ToInt32(Console.ReadLine());


Console.WriteLine("This program will find and display smallest and largest element in an Integer array:");
Console.Write("Enter the array count: ");
int count = Convert.ToInt32(Console.ReadLine());
int[] arr = new int[count];
// Description: stores the values of the array
Console.WriteLine($"Enter {count} values to the array: ");
for (int i = 0; i < count; i++)
{
    Console.Write($"Enter array element {i + 1}: ");
    arr[i] = Convert.ToInt32(Console.ReadLine());
}
// Description: Calles the Largest and Smallest function
Smallest();
Largest();
Console.WriteLine($"Thank you, {lastName}. Part is Done");

// Description: Defines a function called largest that finds the largest number
void Largest()
{
    int largest = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        else
            continue;
    }
    Console.WriteLine($"The Largest element in the array is: {largest}");

}
// Description: Defines a function called smallest that finds the smallest number 
void Smallest()
{
    int smallest = arr[0];
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        else
            continue;
    }
    Console.WriteLine($"The smallest element in the array is: {smallest}");

}