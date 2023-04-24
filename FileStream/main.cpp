#include <iostream>
#include <fstream>

bool LoadFile(const char* filename)
{
	/*
	std::ifstream ist(filename);
	if (!ist)
	{
		std::cerr << filename << " 파일을 찾을 수 없습니다." << std::endl;
		return false;
	}

	char ch;
	while (ist >> ch)
	{
		// 심각한 오류
		if (!ist.bad())
		{
			std::cerr << "파일이 손상되었습니다." << std::endl;
			ist.close();
			return false;
		}
		// 논리 오류 (파일 구성이 잘못 되었으니 개발자에게 알려줍시다.)
		if (!ist.fail())
		{
			std::cerr << "잘못된 파일 포멧입니다." << std::endl;
			ist.close();
			return false;
		}
		std::cout << ch;
	}
	*/

	std::ifstream ist;
	ist.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		ist.open(filename);
		char ch;
		while (ist.get(ch))
		{
			std::cout << ch;
		}
		ist.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "파일 연산 도중 예외가 발생했습니다.\n" << e.what() << std::endl;
		ist.close();
		return false;
	}

	return true;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;
public:
	Monster() : mName{}, mLevel{}, mHP{}, mMP{} {}

	Monster(std::string name, int level, int hp, int mp) :
		mName{ name },
		mLevel{ level },
		mHP{ hp },
		mMP{ mp }
	{}
	void WriteBinary() {}
	void ReadBinary() {}
	void WriteText() {}
	void ReadText() {}
	friend std::istream& operator >> (std::istream& inputStream, Monster& monster);
	friend std::ostream& operator << (std::ostream& ostream, Monster& monster);
};

std::istream& operator >> (std::istream& inputStream, Monster& monster)
{
	std::string buffer;
	try
	{
		std::getline(inputStream, buffer, ',');
		monster.mName = buffer;
		std::getline(inputStream, buffer, ',');
		monster.mLevel = std::stoi(buffer);
		std::getline(inputStream, buffer, ',');
		monster.mHP = std::stoi(buffer);
		std::getline(inputStream, buffer);
		monster.mMP = std::stoi(buffer);
	}
	catch (std::exception e)
	{
		std::cerr << "데이터 형식이 잘못 되었습니다.\n";
	}
	return inputStream;
}

std::ostream& operator << (std::ostream& ostream, Monster& monster)
{
	try
	{
		ostream << monster.mName << ","
			<< monster.mLevel << ","
			<< monster.mHP << ","
			<< monster.mMP << std::endl;
	}
	catch (std::exception e)
	{
		std::cerr << "스트림에 쓸 때 오류가 발생했습니다.\n";
	}
	return ostream;
}

bool CreateFromFile(const char* filename, std::vector<Monster>& vector)
{
	std::ifstream ist;

	// 로직적인 예외는 직접 처리하므로, badbit만 처리했습니다.
	ist.exceptions(std::ifstream::badbit);

	try
	{
		ist.open(filename);

		std::string buffer;
		std::vector<std::string> argVector;

		// 헤더를 읽어 옵니다.
		std::getline(ist, buffer);
		while (!ist.eof())
		{
			// 파일의 끝까지 한 줄씩 읽어 옵니다.
			std::getline(ist, buffer);
			// 우리의 양식은 4개의 데이터가 쉼표로 구분되어 있습니다.
			// 이 조건을 검사해서 데이터가 정상인지 확인합니다.
			if (std::count(buffer.begin(), buffer.end(), ',') == 3)
			{
				std::stringstream ss(buffer);
				for (int i = 0; i < 4; ++i)
				{
					std::string token;

					// , 를 만나면 거기까지만 반환합니다.
					std::getline(ss, token, ',');
					// 읽어온 토큰을 벡터에 임시 저장
					argVector.push_back(token);
				}

				vector.push_back(Monster{
					argVector[0],
					std::stoi(argVector[1]),
					std::stoi(argVector[2]),
					std::stoi(argVector[3])
					});

				// 매개변수 벡터 초기화
				argVector.clear();
			}
			else
			{
				if (buffer.length() != 0)
				{
					std::cerr << "몬스터 데이터 양식이 잘못되었습니다.\n";
				}
			}
		}
		ist.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "파일 연산 도중 예외가 발생했습니다.\n" << e.what() << std::endl;
		ist.close();
		return false;
	}
}

bool CreateFromFile1(const char* filename, std::vector<Monster>& vector)
{
	std::ifstream ist;
	ist.exceptions(std::ifstream::badbit);
	try
	{
		ist.open(filename);
		std::string buffer;
		std::vector<std::string> argVector;

		std::getline(ist, buffer);
		while (!ist.eof())
		{
			if (ist.peek() == EOF)
			{
				break;
			}

			Monster monster;
			ist >> monster;
			vector.push_back(monster);
		}
		ist.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "파일 연산 도중 예외가 발생했습니다.\n" << e.what() << std::endl;
		ist.close();
		return false;
	}

	return true;
}

bool WriteToFile(const char* filename, std::vector<Monster>& vector)
{
	std::ofstream ost;
	ost.exceptions(std::ofstream::badbit);
	try
	{
		ost.open(filename);
		// 헤더
		ost << "--- MONSTER DATA ---\n";
		for (auto monster : vector)
		{
			ost << monster;
		}
		ost.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "파일 연산 도중 예외가 발생했습니다.\n" << e.what() << std::endl;
		ost.close();
		return false;
	}

	return true;
}


int main()
{
	// LoadFile("Data/SimpleData.txt");

	std::vector<Monster> monsterList;
	// CreateFromFile("Data/SimpleData.txt", monsterList);
	CreateFromFile1("Data/SimpleData.txt", monsterList);
	WriteToFile("Data/SimpleData.txt", monsterList);


}