using System;

namespace Employee_Management_System;

public class HourlyEmployee : Employee_Class
{
	double hourlyRate;
	int hoursWorked;

	public HourlyEmployee(string name, int id, string department ,double hourlyRate, int hoursWorked):base(name, id, department, hourlyRate, hoursWorked
    {
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }
}
