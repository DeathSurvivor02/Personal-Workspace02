// Description: takes in a value from the main function and converts it to usd and returns the value to the main function
double cadtousd(double cad)
{
    return (cad * 0.736);
}
// Description: calls the other function cadtousd and stores everything in one place rather than globally
void Main()
{
    Console.Write("Enter CAD value: ");
    double cadValue = Convert.ToInt32(Console.ReadLine());
    double conversion = cadtousd(cadValue);
	// Description: Displays the value in 3 decimal places
    Console.WriteLine($"{cadValue} CAD = {conversion:d3}");
}
Main();