#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>

class STL_mapStudent
{
public:
	std::string M_mName;
	int M_mScore;
};

void mapAddStudent(std::map<int, STL_mapStudent>& container);
void mapDeleteStudent(std::map<int, STL_mapStudent>& student);
void mapStudentPrint(std::map<int,STL_mapStudent>::value_type& pair);
void mapAllStudentPrint(std::map<int, STL_mapStudent>& container);
void mapAverageTotalPrint(std::map<int, STL_mapStudent>& container);
void mapAboveAveragePrint(std::map<int, STL_mapStudent>& container);
