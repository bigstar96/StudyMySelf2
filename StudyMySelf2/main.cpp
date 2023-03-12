#include <iostream>

// STL : Standard Library
// Container - �ڷ� ������ ���� ���ø� Ŭ����, Stack, Queue, List ��� ���� ���Ҹ� �����ϴ� ���հ� ���� ����
// �ٸ� ���δ� �÷���(Collection)�̶�� ��.
// �� �����̳� ���� ������� �����Ƿ� Ư¡�� �� �����ϰ� ������ ���� ������ ������.

// Iterator - �����̳��� ���ҵ��� ��ȸ�ϱ� ���� �Ϲ�ȭ�� ����� �ݺ���(Iterator) ��� ��
// �ݺ��ڴ� �����̳� ���������� �ʱ� ������ �������� �и�/�����Ͽ� ����� ����.
// ������ ���� : ���Ҹ� ����Ŵ
// ���� ��ȸ : ++, !=, == ���� ������ ����
// ����, �� ���� : begin(), end()

// Algorithm - ���� ������ �� �ִ� ����, �˻�, ���� ���� �����ϱ� ����� ��ɱ��� ���� �ְ��� ���α׷��ӵ���
// �̸� �غ��ص� �˰��� ����. �����̳ʸ� �ٷ� �� �ִ� ���� ���ø� �Լ����� �������� �Ǿ��ְ�,
// �����̳ʿ� �и� �Ǿ� �־ ��� �����̳ʿ��� ������ �� �ִ� ������ ����.

void TestPrint(std::string& str)
{
	std::cout << str.length() << " : " << str << std::endl;
}


#include <string>
#include <sstream>


int main()
{
	std::string empty;
	TestPrint(empty);
	std::string sized(10, '\0');
	TestPrint(sized);
	std::string s1("test");
	std::cout << s1[0] << s1[1] << s1[2] << s1[3] << std::endl;
	std::string s2(s1);
	std::string s3 = s1 + s2;
	TestPrint(s3);
	s3 += s3;
	s3[0] = 'T';
	TestPrint(s3);
	empty = s3;
	TestPrint(empty);
	empty = empty;
	TestPrint(empty);


	int number1{ 123 };
	std::string str1{ "" };
	str1 = std::to_string(number1);
	number1 = stoi(str1);
	std::cout << str1 << "<->" << number1 << std::endl;

	wchar_t c1 = L'A';
	std::wstring String = L"Ȯ�� ���ڿ�";
	
	int number2{ 1 };
	char name[]{ "Doggy" };
	float average{ 90.1f };
	char output[128]{};

	sprintf_s(output, sizeof(output),
		"%d�� �л� %s�� ��� %.1f �Դϴ�.",
		number2, name, average
		);
	std::string str2{ output };
	std::cout << str2 << std::endl;

	std::cout << snprintf(output, sizeof(output), "%d�� �л� %s�� ��� %.1f �Դϴ�.", number2, name, average);

	std::ostringstream oss;
	oss << number2 << "�� �л� " << name << "�� ��� " << average << "�Դϴ�." << std::endl;

	std::string buffer = oss.str();
	std::cout << buffer << std::endl;
}