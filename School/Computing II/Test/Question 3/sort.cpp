sort(z.begin(), z.end());

for(size_t i{ 0 }; i < z.size(); i++ )
{
	if (z[i] > largest)
	{
		largest = z[i];
	}
}

std::cout << "The largest element is " << largest << std::endl;