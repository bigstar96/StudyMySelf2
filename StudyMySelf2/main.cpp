#include <iostream>



int main()
{
	struct OneByte
	{
		char OBChar;
	};
	std::cout << sizeof(OneByte) << std::endl;

	struct EightByte
	{
		char EBChar;
		int EBInt;
	};
	std::cout << sizeof(EightByte) << std::endl;

#pragma pack(push, 1)
	struct FiveByte
	{
		char FBChar;
		int FBInt;
	};
#pragma pack(pop)
	std::cout << sizeof(FiveByte) << std::endl;
}