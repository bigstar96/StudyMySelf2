#include <iostream>



int main()
{
	int count{ 0 };

	while (count < 100)
	{
		std::cout << count << "\t" << count * count << std::endl;
		count++;
	}

	std::cout << std::endl;

	return 0;
}
