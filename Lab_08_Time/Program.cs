using Lab_08_Time;
using System;
using System.Collections.Generic;

class Program1
{
    static void Main()
    {
        List<Time> times = new List<Time>()
        {
            new Time(9, 35),
            new Time(18, 5),
            new Time(20, 50),
            new Time(10),
            new Time()
        };

        // Display all objects in Hour12 format
        TimeFormat format = TimeFormat.Hour12;
        Console.WriteLine($"\n\nTime format is {format}");
        foreach (Time t in times)
        {
            Console.WriteLine(t);
        }

        // Change format to Mil
        format = TimeFormat.Mil;
        Console.WriteLine($"\n\nSetting time format to {format}");
        Time.SetFormat(format);
        foreach (Time t in times)
        {
            Console.WriteLine(t);
        }

        // Change format to Hour24
        format = TimeFormat.Hour24;
        Console.WriteLine($"\n\nSetting time format to {format}");
        Time.SetFormat(format);
        foreach (Time t in times)
        {
            Console.WriteLine(t);
        }
    }
}
