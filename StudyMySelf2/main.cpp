#include <iostream>
#include "Point2D.h"


int main()
{
	Point2D pt;
	pt.Point2D_Set(3, 3);
	std::cout << pt.Point2D_Length() << std::endl;
	pt.Point2D_Print();
}

