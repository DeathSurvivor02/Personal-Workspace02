/*
Name: Ean Bynoe

Student Number: 301390261

Description: This code is designed to ask the user for their age and last name.
It then will print the Words of the age once their age is over the age of 21
*/


//Variable Declaration & Initialization

string name_Bynoe = "";
int age_Ean;

int modded_age;
int divided_age;

int start_age;
int end_age;

string spelling_start = "";
string spelling_end = "";

//Input from User
Console.Write("Enter you last name:\n");
name_Bynoe = Console.ReadLine();

Console.Write("Enter your age:\n");
age_Ean = Convert.ToInt32(Console.ReadLine());


//Calculation for the age spelling
modded_age = age_Ean % 10;
start_age = age_Ean / 10;

//Checks to see if the age is over 21
if (age_Ean>= 21)
{
    //Display the First part of the age
    switch (start_age)
    {

        case 2:
            spelling_start = "Twenty";
            break;

        case 3:
            spelling_start = "Thirty";
        break;

        case 4:
            spelling_start = "Forty";
            break;

        case 5:
            spelling_start = "Fifty";
            break;

        case 6:
            spelling_start = "Sixty";
            break;

        case 7:
            spelling_start = "Seventy";
            break;

        case 8:
            spelling_start = "Eighty";
            break;

        case 9:
            spelling_start = "Ninety";
            break;

    }
    //Display the Second part of the age
    switch (modded_age)
    {
        case 1:
            spelling_end = "-one";
            break;
        case 2:
            spelling_end = "-two";
            break;
        case 3:
            spelling_end = "-three";
            break;
        case 4:
            spelling_end = "-four";
            break;
        case 5:
            spelling_end = "-five";
            break;
        case 6:
            spelling_end = "-six";
            break;
        case 7:
            spelling_end = "-seven";
            break;
        case 8:
            spelling_end = "-eight";
            break;
        case 9:
            spelling_end = "-nine";
            break;
    }
    Console.Write($"Hi, {name_Bynoe}, you are {spelling_start}{spelling_end} years old");
}
else
    Console.Write($"Hi, {name_Bynoe}, you have entered an invalid age value");