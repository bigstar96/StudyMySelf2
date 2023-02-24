#pragma once

class DateClass
{
	int mDay;
	int mMonth;
	int mYear;

public:
	DateClass(int y, int m, int d) :mYear{ y }, mMonth{ m }, mDay{ d }
	{
	}

	void Print();
};

