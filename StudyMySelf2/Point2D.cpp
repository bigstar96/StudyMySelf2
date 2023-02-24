#include "Point2D.h"

void Point2D::Point2D_Set(int x, int y)
{
	mX = x;
	mY = y;
}

double Point2D::Point2D_Length()
{
	return sqrt(mX * mX + mY * mY);
}

void Point2D::Point2D_Print()
{
	std::cout << "(" << mX << ", " << mY << ")" << std::endl;
}
