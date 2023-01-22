#include <iostream>
#include <stdarg.h>

void function(int count, ...)
{
	va_list params;
	va_start(params, count);
	for (int i = 0; i < count; ++i)
	{
		std::cout << va_arg(params, int);
	}
	std::cout << std::endl;
}



int main()
{
	function(1, 1);
	function(2, 2, 3);

	return 0;
}