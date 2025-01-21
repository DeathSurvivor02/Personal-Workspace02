using System;

namespace Pet_W;

public class Pet
{

	// Variables:
	string name;
	string owner;
	int age;
	string description;
	bool isHouseTrained;


	//~Properties 
	public string Name { get; }
	public string Owner { get; private set; }
	public int Age { get; }
	public string Description { get; }
	public bool IsHouseTrained { get; private set; }


	// Constructor:
	public Pet(string name, int age, string description)
	{
		Name = name;
		Age = age;
		Description = description;
		Owner = "no one";
		IsHouseTrained = false;
	}

	// Functions:
	public override string ToString()
	{
		return ($"Name: {Name}\nAge: {Age}\nDescription: {Description}\nOwner: {Owner}\nIs house trained: {IsHouseTrained}\n\n");
	}

	public void Train()
	{
		IsHouseTrained = true;
	}

	public void SetOwner(string newOwner)
	{
		Owner = newOwner;
	}
}
