#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	struct Record
	{
		char month[10];
		int year;
		char Artist[50];
		char songTitle[50];
		char recordLabel[50];
		int numberOfWeeks;
	};
	typedef struct Record record;
	ifstream dataFileOpen("RAFData.dat", ios::in);

	if (!dataFileOpen)
	{
		std::cout << "RAFDATA could not be accessed." << std::endl;
		exit(1);
	}
	while (!dataFileOpen.eof())
	{
		dataFileOpen.read(reinterpret_cast<char*>((&record), sizeof(Record)));
		std::cout <<"\n" << record.month[10] << "\t" << record.year << "\t" << record.Artist[10] << "\t" << record.songTitle[10] << "\t" << record.recordLabel[10] << "\t" << record.numberOfWeeks;
	}
	cout << "\n";
	dataFileOpen.close();
}