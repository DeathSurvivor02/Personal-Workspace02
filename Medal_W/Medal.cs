using System;

namespace Medal_W;



public class MedalClass
{
	// Variables:
	string name;
	string theEvent;
	string color;
	int year;
	bool isRecord;

	//~Properties:

	public string Name { get; }
	public string TheEvent { get; }
	public MedalColor Color { get; }
	public int Year { get; }
	public bool IsRecord { get; }

	// Constructor:
	public MedalClass(string name, string theEvent, MedalColor color, int year, bool isRecord)
	{
		Name = name;
		TheEvent = theEvent;
		Color = color;
		Year = year;
		IsRecord = isRecord;
	}

	//Functions:
	public override string ToString()
	{
		if (IsRecord)
			return ($"{Year} - {TheEvent}(R) {Name}({Color})");
		else
			return ($"{Year} - {TheEvent} {Name}({Color})");

	}

}