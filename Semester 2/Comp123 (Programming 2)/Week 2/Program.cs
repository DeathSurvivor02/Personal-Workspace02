using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Setget
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Student student = new Student();

			//* Use properties to assign values
			student.Name = "John Doe";
            student.Age = 25;

			//*Access value through properties
			Console.WriteLine($"Student Name: {student.Name}");
            Console.WriteLine($"Student Age: {student.Age}");

			//*Attempt to set invalid data
			student.Age = -10; // should throw an exceptioneeeeeeee

		}
	}
}