#include <iostream>



int main()
{
	int myInteger = 1000;
	unsigned char myCharacter = myInteger;

	std::cout << myInteger << std::endl;
	std::cout << int(myCharacter) << std::endl;
}