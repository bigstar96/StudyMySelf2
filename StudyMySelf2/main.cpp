#include <iostream>



int main()
{
	int array[2][3];

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << &array[i][j] << " ";
		}
		std::cout << std::endl;
	}


	int array1[2][3];
	int (*p)[3] = &array1[0];

	int array2[2][3][4];
	int(*nums)[3][4]{ array2 };

	int array3[2][3];
	int(*p2)[3] = array3;

	std::cout << p << " " << *p << " " << p + 1 << " " << *(p + 1) << " " << *(p + 1) + 2
		<< " " << *(*p + 1);
}