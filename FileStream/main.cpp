#include <iostream>
#include <fstream>

bool LoadFile(const char* filename)
{
	/*
	std::ifstream ist(filename);
	if (!ist)
	{
		std::cerr << filename << " ������ ã�� �� �����ϴ�." << std::endl;
		return false;
	}

	char ch;
	while (ist >> ch)
	{
		// �ɰ��� ����
		if (!ist.bad())
		{
			std::cerr << "������ �ջ�Ǿ����ϴ�." << std::endl;
			ist.close();
			return false;
		}
		// �� ���� (���� ������ �߸� �Ǿ����� �����ڿ��� �˷��ݽô�.)
		if (!ist.fail())
		{
			std::cerr << "�߸��� ���� �����Դϴ�." << std::endl;
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
		std::cerr << "���� ���� ���� ���ܰ� �߻��߽��ϴ�.\n" << e.what() << std::endl;
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
		std::cerr << "������ ������ �߸� �Ǿ����ϴ�.\n";
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
		std::cerr << "��Ʈ���� �� �� ������ �߻��߽��ϴ�.\n";
	}
	return ostream;
}

bool CreateFromFile(const char* filename, std::vector<Monster>& vector)
{
	std::ifstream ist;

	// �������� ���ܴ� ���� ó���ϹǷ�, badbit�� ó���߽��ϴ�.
	ist.exceptions(std::ifstream::badbit);

	try
	{
		ist.open(filename);

		std::string buffer;
		std::vector<std::string> argVector;

		// ����� �о� �ɴϴ�.
		std::getline(ist, buffer);
		while (!ist.eof())
		{
			// ������ ������ �� �پ� �о� �ɴϴ�.
			std::getline(ist, buffer);
			// �츮�� ����� 4���� �����Ͱ� ��ǥ�� ���еǾ� �ֽ��ϴ�.
			// �� ������ �˻��ؼ� �����Ͱ� �������� Ȯ���մϴ�.
			if (std::count(buffer.begin(), buffer.end(), ',') == 3)
			{
				std::stringstream ss(buffer);
				for (int i = 0; i < 4; ++i)
				{
					std::string token;

					// , �� ������ �ű������ ��ȯ�մϴ�.
					std::getline(ss, token, ',');
					// �о�� ��ū�� ���Ϳ� �ӽ� ����
					argVector.push_back(token);
				}

				vector.push_back(Monster{
					argVector[0],
					std::stoi(argVector[1]),
					std::stoi(argVector[2]),
					std::stoi(argVector[3])
					});

				// �Ű����� ���� �ʱ�ȭ
				argVector.clear();
			}
			else
			{
				if (buffer.length() != 0)
				{
					std::cerr << "���� ������ ����� �߸��Ǿ����ϴ�.\n";
				}
			}
		}
		ist.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "���� ���� ���� ���ܰ� �߻��߽��ϴ�.\n" << e.what() << std::endl;
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
		std::cerr << "���� ���� ���� ���ܰ� �߻��߽��ϴ�.\n" << e.what() << std::endl;
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
		// ���
		ost << "--- MONSTER DATA ---\n";
		for (auto monster : vector)
		{
			ost << monster;
		}
		ost.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "���� ���� ���� ���ܰ� �߻��߽��ϴ�.\n" << e.what() << std::endl;
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