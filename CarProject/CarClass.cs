using System;

namespace CarClass
{


	public class CarProject
	{
		// Variables:
		private int year;
		private string model;
		private bool isDrivable;
		private double price;


		//~Constructors
		public CarProject(string model, int year, double price, bool isDrivable = true)
		{
			this.model = model;
			this.year = year;
			this.isDrivable = isDrivable;
			this.price = price;
		}

		// Functions:
		public override string ToString()
		{
			return ($"Model: {model} \n"
				+ $"Year: {year} \n"
				+ $"Price: {price} \n"
				+ $"Drivable: {isDrivable}");
		}


	}

}