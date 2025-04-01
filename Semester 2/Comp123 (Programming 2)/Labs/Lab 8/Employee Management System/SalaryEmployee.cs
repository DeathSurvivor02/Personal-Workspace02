using System;

namespace Employee_Management_System;

public class SalaryEmployee : Employee_Class
{
	double monthlySalary;

	SalaryEmployee(string name, int id, string department, double monthlySalary) : base(name, id, department)
	{
		this.monthlySalary = monthlySalary;
	}

	public double CalculateSalary()
	{
		return monthlySalary;
	}

	public void GeneratqReport()
	{
	    Console.WriteLine($"Employee Name: {name}\nEmployee ID: {id}\nDepartment: {department}\nMonthly Salary: {CalculateSalary()}");
	}
}
