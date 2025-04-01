using System;
using System.Collections.Generic;

// IPayable Interface
// defines salary calculation contract
interface IPayable
{
    double CalculateSalary();
}

// IReportable Interface
// defines reporting contract
interface IReportable
{
    void GenerateReport();
}

// Abstract Base Class Employee
abstract class Employee
{
    protected string name;
    protected int id;
    protected string department;

    public Employee(string name, int id, string department)
    {
        this.name = name;
        this.id = id;
        this.department = department;
    }
}

// SalariedEmployee Class
class SalariedEmployee : Employee, IPayable, IReportable
{
    private double monthlySalary;

    public SalariedEmployee(string name, int id, string department, double monthlySalary)
        : base(name, id, department)
    {
        this.monthlySalary = monthlySalary;
    }

    public double CalculateSalary()
    {
        return monthlySalary;
    }

    public void GenerateReport()
    {
        Console.WriteLine($"Salaried Employee: {name}, ID: {id}, Department: {department}, Salary: {CalculateSalary():C}");
    }
}

// HourlyEmployee Class
class HourlyEmployee : Employee, IPayable, IReportable
{
    private double hourlyRate;
    private int hoursWorked;

    public HourlyEmployee(string name, int id, string department, double hourlyRate, int hoursWorked)
        : base(name, id, department)
    {
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    public double CalculateSalary()
    {
        return hourlyRate * hoursWorked;
    }

    public void GenerateReport()
    {
        Console.WriteLine($"Hourly Employee: {name}, ID: {id}, Department: {department}, Salary: {CalculateSalary():C}");
    }
}

// ContractEmployee Class
class ContractEmployee : Employee, IPayable, IReportable
{
    private double contractAmount;

    public ContractEmployee(string name, int id, string department, double contractAmount)
        : base(name, id, department)
    {
        this.contractAmount = contractAmount;
    }

    public double CalculateSalary()
    {
        return contractAmount;
    }

    public void GenerateReport()
    {
        Console.WriteLine($"Contract Employee: {name}, ID: {id}, Department: {department}, Salary: {CalculateSalary():C}");
    }
}

// Test Harness
partial class Program
{
    static void Main()
    {
        List<IPayable> employees = new List<IPayable>
        {
            new SalariedEmployee("Annu", 101, "Finance", 5000),
            new HourlyEmployee("Ben", 102, "IT", 20, 160),
            new ContractEmployee("Liu", 103, "Marketing", 12000)
        };

        foreach (var employee in employees)
        {
            Console.WriteLine($"Salary: {employee.CalculateSalary():C}");

            if (employee is IReportable reportable)
            {
                reportable.GenerateReport();
            }
        }
    }
}
 