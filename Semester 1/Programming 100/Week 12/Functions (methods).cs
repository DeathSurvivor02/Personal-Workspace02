// Todo: Ask for the size of the array

int ArraySize()
{
    int count = 0;
    bool conditional = false;
    while (conditional == !true)
    {
        Console.WriteLine("Enter array count value: ");
        count = Convert.ToInt32(Console.ReadLine());
        if ((5 > count) || (count > 10))
        {
            Console.WriteLine("Invalid count value ");
            conditional = false;
        }
        else
        {
            conditional = true;
        }
    }
    return count;
}

void ArrayDeclaration(int count, int[] array)
{
    Console.WriteLine($"Enter {count} array items");
    for (int i = 0; i < count; i++)
    {
        array[i] = Convert.ToInt32(Console.ReadLine());
    }
}
void ArrayDisplay(int count, int[] array)
{
    foreach (var item in array)
    {
        Console.WriteLine($"{array}");
    }

}
int main()
{
    int count = ArraySize();
    int[] array = new int[count];
    ArrayDeclaration(count, array);
    ArrayDisplay(count, array);
    return 0;
}


main();