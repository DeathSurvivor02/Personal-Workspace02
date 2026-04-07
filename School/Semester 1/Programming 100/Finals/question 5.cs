// Description: takes in the value from Main() but wont change the value of x directly
int Square(int x)
{
    x = x * x;
    return x;
}
// Description: Directly changes the value of x from in the Main() and returns it
int Square2(ref int x)
{
    x = x * x;
    return x;
}

// Description: Stores everything and calls the 2 functions
void Main()
{
    int squareValue = 0;
    int squareValue2 = 0;
    Console.WriteLine("Enter an integer Value: ");
    int x = Convert.ToInt32(Console.ReadLine());
    squareValue =  Square(x);
    Console.WriteLine($"Square value using regular parameter: {squareValue }");

    Console.WriteLine("Enter an integer Value: ");
    x = Convert.ToInt32(Console.ReadLine());
    squareValue2 = Square2(ref x);
    Console.WriteLine($"Square value using ref parameter: {squareValue2}");


}
Main();