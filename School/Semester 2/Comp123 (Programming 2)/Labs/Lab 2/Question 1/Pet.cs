using System;


public class Pet
{
	// Variables:
	string name;
	string owner;
	int age;
	string description;
	bool isHouseTrained;


	//Description: Properties
	public string Name //!setter is absent
	{
		get { return name; }
		// set {Name = value; }
	}

	public string Owner //~setter private
	{
		get { return owner; }
		private set { owner = value; }
	}

	public int Age //!setter is absent
	{
		get { return age; }
	}

	public string Description //~setter private
	{
		get { return description; }
		private set { description = value; }
	}

	public Pet(string name, int age, string description)
	{
		this.name = name;
		this.age = age;
		this.description = description;
	}

	public override string ToString()
	{
		return ($"Name of Pet: {name} \n"
			+ $"Owner: {owner} \n"
			+ $"Age: {age} \n"
			+ $"Description: {description}"
			+ ($"\nIs House Trained: {isHouseTrained}"
				+ (description == "" ? "" : $" \nAdditional Details: {description}")));
	}


	public void SetOwner(string owner)
	{
		this.owner = owner;
	}

	public void Train()
	{
		isHouseTrained = true;
	}

}