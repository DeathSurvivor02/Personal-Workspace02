using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Pet_W;

public class PetClass
{
	static void Main(string[] args)
	{
		//Todo: Create 4 objects

		Pet pet1 = new Pet("Max", 6, "Pitbull");
		Pet pet2 = new Pet("Buddy", 3, "Golden Retriever");
		Pet pet3 = new Pet("Socks", 1, "Beagle");
		Pet pet4 = new Pet("Rex", 8, "Labrador");


		//Todo: Create a list to store all the above objects

		List<Pet> pets = new List<Pet>() { pet1, pet2, pet3, pet4 };

		// Todo: Use some of the methods on some of the objects

		pet1.Train();
		pet2.SetOwner("Anthony");
		pet3.SetOwner("Julia");
		pet3.Train();



		//Todo: Using a suitable looping statement, display all the objects in the collection.

		foreach (Pet pet in pets)
		{

			Console.WriteLine(pet.ToString()); 
		}

		//Todo: Prompt the user for an owner’s name and then display only the pets belonging to a particular person

		Console.WriteLine("Enter the name of the owner.");
		string name = Console.ReadLine();
		foreach (Pet pet in pets)
		{
			if (pet.Owner == name)
			{
				Console.WriteLine(pet.ToString());
			}
		}
	}
}

