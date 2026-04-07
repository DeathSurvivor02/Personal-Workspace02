Console.WriteLine("Table of 5!");
int i = 1;
int count = 10;
while (i < count)
{
    if (i % 4 != 0)
    {
        Console.WriteLine($"5 X {i} = {5 * i}");
        i++;
    }
    else {
    i++;
    continue;
    }
}
