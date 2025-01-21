// See https://aka.ms/new-console-template for more information
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Medal_W;

public class Medal
{
	static void Main(string[] args)
	{
		//* Create a medal object
		MedalClass m1 = new MedalClass("Horace Gwaynne", "Boxing", MedalColor.Gold, 2012, true);
		//* Print the object
		Console.WriteLine(m1);

		//* print only the name of the medal object
		Console.WriteLine(m1.Name);


		//* Create another object
		MedalClass m2 = new MedalClass("Michael Phelps", "Swimming", MedalColor.Gold, 2012, false);

		//create another object
		//print the updated m2
		Console.WriteLine(m2);
		//create a list to store the medal objects
		List<MedalClass> medals = new List<MedalClass>() { m1, m2 };
		medals.Add(new MedalClass("Ryan Cochrane", "Swimming", MedalColor.Silver, 2012, false));
		medals.Add(new MedalClass("Adam van Koeverden", "Canoeing", MedalColor.Silver, 2012, false));
		medals.Add(new MedalClass("Rosie MacLennan", "Gymnastics", MedalColor.Gold, 2012, false));
		medals.Add(new MedalClass("Christine Girard", "Weightlifting", MedalColor.Bronze, 2012, false));
		medals.Add(new MedalClass("Charles Hamelin", "Short Track", MedalColor.Gold, 2014, true));
		medals.Add(new MedalClass("Alexandre Bilodeau", "Freestyle skiing", MedalColor.Gold, 2012, true));
		medals.Add(new MedalClass("Jennifer Jones", "Curling", MedalColor.Gold, 2014, false));
		medals.Add(new MedalClass("Charle Cournoyer", "Short Track", MedalColor.Bronze, 2014, false));
		medals.Add(new MedalClass("Mark McMorris", "Snowboarding", MedalColor.Bronze, 2014, false));
		medals.Add(new MedalClass("Sidney Crosby ", "Ice Hockey", MedalColor.Gold, 2014, false));
		medals.Add(new MedalClass("Brad Jacobs", "Curling", MedalColor.Gold, 2014, false));
		medals.Add(new MedalClass("Ryan Fry", "Curling", MedalColor.Gold, 2014, false));
		medals.Add(new MedalClass("Antoine Valois-Fortier", "Judo", MedalColor.Bronze, 2012, false));
		medals.Add(new MedalClass("Brent Hayden", "Swimming", MedalColor.Bronze, 2012, false));
		//prints a numbered list of 16 medals.
		Console.WriteLine("\n\nAll 16 medals");
		foreach (var medal in medals)
		{
			Console.WriteLine($"{medal}");
		}
		//prints a numbered list of 16 names (ONLY)
		Console.WriteLine("\n\nAll 16 names");
		foreach (var medal in medals)
		{
			Console.WriteLine($"{medals.IndexOf(medal) + 1}. {medal.Name}");
		}
		//prints a numbered list of 9 gold medals
		Console.WriteLine("\n\nAll 9 gold medals");
		foreach (var medal in medals)
		{
			if (medal.Color == MedalColor.Gold)
			{

				Console.WriteLine($"{medals.IndexOf(medal) + 1}. {medal}");
			}
			else
				continue;
		}
		//prints a numbered list of 9 medals in 2012
		Console.WriteLine("\n\nAll 9 medals");
		foreach (var medal in medals)
		{
			if (medal.Year == 2012)
			{
				Console.WriteLine($"{medals.IndexOf(medal) + 1}. {medal}");
			}
		}
		//prints a numbered list of 4 gold medals in 2012
		Console.WriteLine("\n\nAll 4 gold medals");
		foreach (var medal in medals)
		{
			if (medal.Color == MedalColor.Gold && medal.Year == 2012)
			{
				Console.WriteLine($"{medals.IndexOf(medal) + 1}. {medal}");
			}
		}
		//prints a numbered list of 3 world record medals
		Console.WriteLine("\n\nAll 3 records");
		foreach (var medal in medals)
		{
			if (medal.IsRecord)
            {
                Console.WriteLine($"{medals.IndexOf(medal) + 1}. {medal}");
            }
		}
		//saving all the medal to file Medals.txt
		Console.WriteLine("\n\nSaving to file");
		
	}
}
