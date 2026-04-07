namespace Setget
{
	internal class Student
	{
		private string name; //!Private field
		private int age; //Private field

		public string Name
		{
			get { return name; }
			set { name = value; }
		}

		public int Age
		{
			get { return age; }
			set
			{
				if (value < 0)
				{
					age = value;
				}
				else
				{
					Console.WriteLine("Age must be positive.");
				}
			}
		}


	}
}