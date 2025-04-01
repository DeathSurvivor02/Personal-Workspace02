using System;
using System.Collections.Generic;
using System.Linq;

internal class Program
{
    static void Main(string[] args)
    {
        // Initialize the list of students
        List<Student> students = new List<Student>
        {
            new Student { Name = "Ali", Score = 85 },
            new Student { Name = "Sara", Score = 90 },
            new Student { Name = "John", Score = 78 },
            new Student { Name = "Mary", Score = 92 },
            new Student { Name = "David", Score = 88 }
        };

        // Initialize the list of courses
        List<Course> courses = new List<Course>
        {
            new Course { StudentName = "Ali", CourseName = "Math" },
            new Course { StudentName = "Sara", CourseName = "Science" },
            new Course { StudentName = "John", CourseName = "History" },
            new Course { StudentName = "Mary", CourseName = "English" },
            new Course { StudentName = "David", CourseName = "Art" }
        };

        // LINQ query to get students with scores greater than 80, ordered by score descending
        var topStudents = from s in students
                          where s.Score > 80
                          orderby s.Score descending
                          select s;

        // Print the results
        Console.WriteLine("Top Students:");
        foreach (var student in topStudents)
        {
            Console.WriteLine($"Name: {student.Name}, Score: {student.Score}");
        }
    }
}

// Define the Student class
internal class Student
{
    public string Name { get; set; }
    public int Score { get; set; }
}

// Define the Course class
internal class Course
{
    public string StudentName { get; set; }
    public string CourseName { get; set; }
}
