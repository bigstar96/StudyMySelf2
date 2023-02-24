#pragma once
#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;

public:
	void Point2D_Set(int x, int y);
	double Point2D_Length();
	void Point2D_Print();
	
};

