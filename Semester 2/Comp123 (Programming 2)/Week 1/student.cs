using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentClassdemo
{
	public class Student
	{
		private int id;
		private string name;
		private double grade;
		private bool isEnrolled;

		public Student(int id, string name, double grade, bool isEnrolled = true)
		{
			this.id = id;
			this.name = name;
			this.grade = grade;
			this.isEnrolled = isEnrolled;
		}
	}
}
