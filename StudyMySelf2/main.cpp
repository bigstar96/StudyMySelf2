#include <iostream>

class Point2D
{
private:
	int mX{};
	int mY{};

public:
	Point2D() = default;
	Point2D(int x, int y) : mX{ x }, mY{ y } {}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;
	}

	friend Point2D operator+(const Point2D& x, const Point2D& y);
};

Point2D operator+(const Point2D& x, const Point2D& y)
{
	Point2D newPt{ 0,0 };

	newPt.mX = x.mX + y.mX;
	newPt.mY = x.mY + y.mY;

	return newPt;
}

int main()
{
	Point2D pt1{ 2,3 };
	Point2D pt2{ 3,4 };
	Point2D pt3{};
	Point2D pt4{};

	pt3 = pt1 + pt2;
	pt3.Print();

	pt4 = (pt1 + pt2) + pt3;
	pt4.Print();

}

