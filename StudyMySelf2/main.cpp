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
	const Point2D& operator++();
	const Point2D& operator++(int value);

	operator const float()
	{
		return float(sqrt(mX * mX + mY * mY));
	}

	void operator()()
	{
		mX = 0;
		mY = 0;
	}

	void operator()(int x, int y)
	{
		mX = x;
		mY = y;
	}

	friend std::ostream& operator<< (std::ostream& os, const Point2D point)
	{
		os << "(" << point.mX << ", " << point.mY << ")";
		return os;
	}
};

Point2D operator+(const Point2D& x, const Point2D& y)
{
	Point2D newPt{ 0,0 };

	newPt.mX = x.mX + y.mX;
	newPt.mY = x.mY + y.mY;

	return newPt;
}

// 전위 연산자
const Point2D& Point2D::operator++()
{
	mX++;
	mY++;

	return *this;
}

// 후위 연산자
const Point2D& Point2D::operator++(int)
{
	Point2D temp(mX, mY);
	++(*this);
	return temp;
}


class MyArray
{
private:
	int mArray[10];

public:
	MyArray() : mArray{} {}

	int& operator[](int index)
	{
		return mArray[index];
	}
};

class Character
{

public:
	Character& Move()
	{
		std::cout << "Move" << std::endl;
		return *this;
	}

	Character& TurnLeft()
	{
		std::cout << "Turn Left" << std::endl;
		return *this;
	}

	Character& TurnRight()
	{
		std::cout << "Turn Right" << std::endl;
		return *this;
	}

};


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

	Point2D pt5{ 2,3 };
	++pt5;
	pt5.Print();

	MyArray ay1;
	
	ay1[0] = 1;

	std::cout << ay1[0] << std::endl;
	std::cout << ay1[1] << std::endl;

	Point2D pt6{ 2,3 };
	float dist{ pt6 };
	std::cout << pt6 << std::endl;

	Point2D pt7{ 2,3 };
	pt7();
	pt7.Print();
	pt7(2, 3);
	pt7.Print();

	std::cout << pt1 << pt2 << pt3 << pt4 << pt5 << pt6 << pt7 << std::endl;

	Character player;
	player.Move()
		.TurnLeft()
		.TurnRight();
}
