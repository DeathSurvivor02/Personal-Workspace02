
namespace Pet;

public class Main
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Pet pet1 = new Pet("Buddy", 5, "Brown");
			Pet pet2 = new Pet("Max",  4, "Orange and White");
			Pet pet3 = new Pet("Jose", 2 , "Butters");
			Pet pet4 = new Pet("Sparkles", 9, "Black and Brown");


			List<Pet> pets = new List<Pet>();

			pets.Add(pet1);
            pets.Add(pet2);
            pets.Add(pet3);
            pets.Add(pet4);



			foreach (var pet in pets)
            {
                Console.WriteLine($"Name: {pet.Name}, Age: {pet.Age}, Color: {pet.Color}");
            }

		}
	}
}