#include <iostream>
#include <string>
#include "Package.cpp"
#include "TwoDayPackage.cpp"
#include "OvernightPackage.cpp"

int main()
{
	


	OvernightPackage item1("Nathan  ", "4th Avenue", "Lahore",
		"Pakistan", "89754", "Ali", "456 bent street", "Chicago", "Illinois",
		"87540", 15.00, 1.50, 1.10);
	TwoDayPackage item2("Curtis", "987 1st Street", "Mumbai",
		"India", "87654", "Hassan", "833 palm Street", "Chaniot", "Pakistan",
		"98763", 18.00, 1.50, 8.00);

	cout << endl;
	cout << " Overnight Delivery \n";
	cout << "_______________________________________________________\n";
	cout << "Sender:       " << item1.getsender_name() << "\n";
	cout << "Address:      " << item1.getsender_address() << "\n";
	cout << "City:         " << item1.getSendCity() << " " <<
		item1.getsender_state() << " " << item1.getsender_ZIP() << "\n";
	cout << "\n";
	cout << "Recipient:    " << item1.getrecipient_name() << "\n";
	cout << "Address:      " << item1.getsender_address() << "\n";
	cout << "City:         " << item1.getrecipient_city() << " " <<
		item1.getrecipient_state() << " " << item1.getrecipient_ZIP() << "\n";
	cout << "Cost         $" << item1.calculateCost() << "\n";


	cout << "\n\n";

	cout << " 2 Day Delivery \n";
	cout << "_______________________________________________________\n";
	cout << "Sender:       " << item2.getsender_name() << "\n";
	cout << "Address:      " << item2.getsender_address() << "\n";
	cout << "City:         " << item2.getSendCity() << " " <<
		item2.getsender_state() << " " << item2.getsender_ZIP() << "\n";
	cout << "\n";
	cout << "Recipient:    " << item2.getrecipient_name() << "\n";
	cout << "Address:      " << item2.getsender_address() << "\n";
	cout << "City:         " << item2.getrecipient_city() << " " <<
		item2.getrecipient_state() << " " << item2.getrecipient_ZIP() << "\n";
	cout << "Cost         $" << item2.calculateCost() << "\n";


	system("pause");
	return 0;
}
