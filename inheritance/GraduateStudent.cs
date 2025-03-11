using System;

namespace inheritance
{
	internal class GraduateStudent : Student
	{
		public new static int TotalStudents = 0;

		public GraduateStudent()
		{
			TotalStudents++;
			Console.WriteLine("GraduateStudent constructor called");
		}


		public override void DisplayInfo()
		{
			Console.WriteLine("Graduate Student info");
		}

		public void Study()
        {
            Console.WriteLine("Graduate student studying");
        }
	}
}
