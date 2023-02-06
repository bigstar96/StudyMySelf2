#include <iostream>



int main()
{
	int array[2][3]{
		{1,2,3},
		{4,5,6}
	};

	/*int(*p)[3] = array;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << *((*p) + j) << " ";
		}
		p++;
		std::cout << std::endl;
	}*/

	int* p = &array[0][0];
	
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << *p++ << " ";
		}
		std::cout << std::endl;
	}

}