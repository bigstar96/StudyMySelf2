#include <iostream>
#include "ClassString.h"


int main()
{
	ClassString empty;
	std::cout << empty << std::endl;

	ClassString sized(10);
	std::cout << sized << std::endl;

	ClassString s1("test");
	std::cout << s1 << std::endl;

	ClassString s2(s1);
	std::cout << s2 << std::endl;

	ClassString s3 = s1 + s2;
	std::cout << s3 << std::endl;

	s3 += s3;
	std::cout << s3 << std::endl;

	std::cout << s1[0] << s1[1] << s1[2] << s1[3] << s1[4] << std::endl;

	// s3[0] = "T";

	empty = s3;
	std::cout << empty << std::endl;

	empty = empty;
	std::cout << empty << std::endl;
}