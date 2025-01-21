using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CarClass;




class Car 
{
	static void Main(string[] args)
	{
		// Description: Creating instancing from the class Car
		CarProject car1 = new CarProject("Mercedes", 2023, 60000, true);
		CarProject car2 = new CarProject("Toyota", 2022, 55000, true);
		CarProject car3 = new CarProject("Porsche", 1996, 125000);
		CarProject car4 = new CarProject("Lamborghini", 1997, 500000, true);
		
		Console.WriteLine(car1.ToString());
		Console.WriteLine(car2.ToString());
		Console.WriteLine(car3.ToString());
		Console.WriteLine(car4.ToString());
		
	}
}