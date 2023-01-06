#include <iostream>



int main()
{
	int alpha{ 255 }, red{ 255 }, green{ 0 }, blue{ 0 };

	unsigned int color;

	color = alpha << 24 | red << 16 | green << 8 | blue;

	std::cout << std::hex;
	std::cout << color << std::endl;

	alpha = color >> 24;
	red = color >> 16 & 0xFF;
	green = color >> 8 & 0xFF;
	blue = color & 0xFF;

	std::cout << alpha << ", "
		<< red << ", "
		<< green << ", "
		<< blue << std::endl;
}
