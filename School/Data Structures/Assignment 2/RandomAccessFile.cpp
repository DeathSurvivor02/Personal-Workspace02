#include <iostream>
#include <fstream>
using namespace std;
// using namespace

struct record
{
	char month[10];
	int year;
	char artist[50];
	char title[50];
	char label[15];
	int numweeks;
};

typedef struct record Record;
int main()
{
	ifstream infile("Catalog.dat", ios::in | ios::binary);
	Record rec;

	/*description: reads one record from the infile  */
	infile.read(reinterpret_cast<char *>(&rec), sizeof(Record));

	// description: display the record just read

	cout << "Month = " << rec.month << endl;
	cout << "Year = " << rec.year << endl;
	cout << "Artist = " << rec.artist << endl;
	cout << "Title = " << rec.title << endl;
	cout << "Label = " << rec.label << endl;
	cout << "Weeks = " << rec.numweeks << endl;

	infile.seekg(0);
	while (!infile.eof())
	{
		// read one record from the file
		infile.read(reinterpret_cast<char *>(&rec), sizeof(Record));

		cout << "Month = " << rec.month << endl;
		cout << "Year = " << rec.year << endl;
		cout << "Artist = " << rec.artist << endl;
		cout << "Title = " << rec.title << endl;
		cout << "Label = " << rec.label << endl;
		cout << "Weeks = " << rec.numweeks << endl;
	}

	return 0;
}