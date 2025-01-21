using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace DateClass;

class Date
{

	static void Main(string[] args)
	{

		// Description: Create new instances of the class Date
		DateClass date1 = new DateClass(9, 10, 2002);


		// Description: Prints the date of the first instance
		Console.WriteLine(date1.ToString());
		//Description: Adds (44) days to the date in the object
		date1.Add(44);

		// Description: Prints the updated date of the first instance after adding days.
		Console.WriteLine(date1.ToString());

		// Description: Adds (22) days and 4 months to the date
		date1.Add(22, 4);

		// Description: Prints the updated date of the first instance after adding days and months.
		Console.WriteLine(date1.ToString());
		DateClass otherDate = new DateClass(12, 12, 2005);

		date1.Add(otherDate);
		Console.WriteLine(date1.ToString());

		date1.DateWord();


	}

}