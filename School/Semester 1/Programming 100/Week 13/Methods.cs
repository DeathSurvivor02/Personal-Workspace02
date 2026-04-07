/* 
* Name: Ean Bynoe
* Date: November 27, 2024
* Student Number: 301390261
* Description: Ask the user for the value of numbers to be entered in the array. The numbers are then stored in an array and the average of the numbers is calculated and displayed.
*             
*              
*/
//Description: Purpose of the code is to prompt the user to enter count of array elements.
Console.Write("Enter the count: ");
int count = Convert.ToInt32(Console.ReadLine());

// Description: The method EanAdd is created to calculate the average of the numbers entered by the user.
float EanAdd(int count)
{
	int[] arr = new int[count];
	float sum = 0;
	Console.WriteLine($"Enter {count} integer numbers:");
	// Description: The for loop is used to store the numbers entered by the user in an array and calculate the sum of the numbers.
	for (int i = 0; i < count; i++)
	{
		Console.Write($"Number {i + 1}: ");
		arr[i] = Convert.ToInt32(Console.ReadLine());
		sum += arr[i];
	}

	return (sum / count:F3);
}

float average = EanAdd(count);
Console.WriteLine($"The average value is: {average:F3}");
Console.WriteLine("Thank you, Ean.");