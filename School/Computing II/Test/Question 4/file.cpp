#include <fstream>
// #include <ofstream>
#include <iostream>

int main()
{
	int num;
	int largest =-999;
	std::ifstream input{"input.txt", std::ios::in};
	std::ofstream output{"output.txt", std::ios::out};
	while (input >> num)
	{
		if (num > largest)
		{
			largest = num;
		}
	}
	output << largest;
	output.close();
	input.close();
	std::cout << largest << std::endl;
	return 0;
}