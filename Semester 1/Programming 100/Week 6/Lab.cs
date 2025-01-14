string spelling;
int age;
string name = "";
string group = "";
Console.Write("Enter your last name: ");
name = Console.ReadLine();
Console.Write("Enter your age: ");
age = Convert.ToInt32(Console.ReadLine());
if (age <= 0)
{
    group = "none";
}
else if (1 <= age && age <= 12)
{
    group = "Child";
}
else if (13 <= age && age <= 19)
{
    group = "Teenager";
}
else if (20 <= age)
{
    group = "Adult";
}

switch (age)
{
    case 1:
        spelling = "One";
        break;

    case 2:
        spelling = "Two";
        break;

    case 3:
        spelling = "Three";
        break;

    case 4:
        spelling = "Four";
        break;

    case 5:
        spelling = "Five";
        break;

    case 6:
        spelling = "Six";
        break;

    case 7:
        spelling = "Seven";
        break;

    case 8:
        spelling = "Eight";
        break;

    case 9:
        spelling = "Nine";
        break;

    case 10:
        spelling = "Ten";
        break;

    case 11:
        spelling = "Eleven";
        break;

    case 12:
        spelling = "Twelve";
        break;

    case 13:
        spelling = "Thirteen";
        break;

    case 14:
        spelling = "Fourteen";
        break;

    case 15:
        spelling = "Fifteen";
        break;

    case 16:
        spelling = "Sixteen";
        break;

    case 17:
        spelling = "Seventeen";
        break;

    case 18:
        spelling = "Eighteen";
        break;

    case 19:
        spelling = "Nineteen";
        break;

    default:
        spelling = "invalid age";
        break;
}
switch (group)
{
    case "none":
        Console.WriteLine($"Hi, {name}, enter a valid age value.");
        break;

    case "Child":
        Console.WriteLine($"Hi {name}, your age is {spelling} and you are a {group}.");
        break;

    case "Teenager":
        Console.WriteLine($"Hi {name}, your age is {spelling} and you are a {group}.");
        break;

    case "Adult":
        Console.WriteLine($"Hi {name}, your age is {age} and you are a {group}.");
        break;

}
