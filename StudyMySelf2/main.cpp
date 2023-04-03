#include <iostream>

class MyClass
{

};

class MySong
{
public:
	int mTackNo;
	std::string mName;
	MySong(int no, std::string name) : mTackNo{ no }, mName{ name } {}
};

class Image
{};

class Demon
{
	std::shared_ptr<Image> mspImage;
public:
	Demon(std::shared_ptr<Image> image) : mspImage{ image } {}
};


#include <tuple>

#include <functional>
// �Լ�
void MyFunction(const int arg1){}
// ����ü () ������ �����ε�
struct MyStruct
{
	void operator()(){}
};

void F(int arg1, char arg2)
{
	std::cout << arg1 << ", " << arg2 << std::endl;
}
using namespace std::placeholders;

#include<regex>

int main()
{
	// ����Ʈ������ ���� �ڵ�
	std::unique_ptr<MyClass> p{ std::make_unique<MyClass>() };

	std::unique_ptr<MySong> spSong = std::make_unique<MySong>(1, "BattleBGM");
	// ������ ����
	std::cout << spSong->mTackNo << " : " << spSong->mName << std::endl;
	// unique_ptr ����Լ� ����
	spSong.release();

	std::shared_ptr<Image> spImage = std::make_shared<Image>();
	{
		std::unique_ptr<Demon> demon1 = std::make_unique<Demon>(spImage);
		{
			std::unique_ptr<Demon> demon2 = std::make_unique<Demon>(spImage);
			{
				std::unique_ptr<Demon> demon3 = std::make_unique<Demon>(spImage);
			}
		}
	}

	std::tuple<int, std::string, std::string> song;
	song = std::make_tuple(1, "helloween", "Dr.Stein");
	std::cout << "TrackNo : " << std::get<0>(song) << std::endl;
	std::cout << "Artist : " << std::get<1>(song) << std::endl;
	std::cout << "Title : " << std::get<2>(song) << std::endl;

	// �Լ�
	std::function<void(const int)> functor1 = MyFunction;
	// ����ü ������
	std::function<void()> functor2 = MyStruct();
	// ���ٽ�
	std::function<void()> functor3 = []() {};

	// �Ű����� 2���� ���� �� �ֵ��� ���ε��� �մϴ�.
	auto functor4 = std::bind(F, _1, _2);
	functor4(1, 'a');
	// ù��°�� ���� 2�� �����ϰ� �߰� ���ڸ� �ϳ� �޽��ϴ�.
	auto functor5 = std::bind(F, 2, _1);
	functor5('b');
	// �ΰ� ���ڸ� �޴� ���, ������ �ٲ�� �ֽ��ϴ�.
	auto functor6 = std::bind(F, _2, _1);
	functor6('c', 3);



}