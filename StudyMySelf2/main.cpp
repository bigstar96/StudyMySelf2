#include <iostream>
#include "Cat.h"


// object Oriented programming (OOP 객체지향 프로그래밍)
class Point2D
{
	int mX;
	int mY;

public:
	void SetX(int x);
	void SetY(int y);
	void Set(int x, int y);
	int GetX();
	int GetY();

	void Print();
};

void Point2D::SetX(int x)
{
	mX = x;
}

void Point2D::SetY(int y)
{
	mY = y;
}

void Point2D::Set(int x, int y)
{
	mX = x;
	mY = y;
}

int Point2D::GetX()
{
	return mX;
}

int Point2D::GetY()
{
	return mY;
}

void Point2D::Print()
{

}


int main()
{
	Cat nacho;
	nacho.Meow();

	// dynamic allocation
	Cat* pCancho = new Cat;
	pCancho->Meow();
	delete pCancho;
}

