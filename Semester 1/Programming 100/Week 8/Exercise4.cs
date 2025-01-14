int n,i,total = 0;

Console.WriteLine("Enter a number: "); 
n = Convert.ToInt32(Console.ReadLine());
while (i < n)
{
    total += i;
    Console.WriteLine(i);
    Console.WriteLine(total)
    i++;
}
i = 0;
do 
{
    if (i % 2 == 0)
    {
        Console.WriteLine(i);
    }
}while (i < n);
