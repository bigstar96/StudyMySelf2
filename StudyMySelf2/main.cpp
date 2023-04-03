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
// 함수
void MyFunction(const int arg1){}
// 구조체 () 연산자 오버로딩
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
	// 스마트포인터 전용 코드
	std::unique_ptr<MyClass> p{ std::make_unique<MyClass>() };

	std::unique_ptr<MySong> spSong = std::make_unique<MySong>(1, "BattleBGM");
	// 포인터 접근
	std::cout << spSong->mTackNo << " : " << spSong->mName << std::endl;
	// unique_ptr 멤버함수 접근
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

	// 함수
	std::function<void(const int)> functor1 = MyFunction;
	// 구조체 연산자
	std::function<void()> functor2 = MyStruct();
	// 람다식
	std::function<void()> functor3 = []() {};

	// 매개변수 2개를 받을 수 있도록 바인딩을 합니다.
	auto functor4 = std::bind(F, _1, _2);
	functor4(1, 'a');
	// 첫번째는 값을 2로 고정하고 추가 인자를 하나 받습니다.
	auto functor5 = std::bind(F, 2, _1);
	functor5('b');
	// 두개 인자를 받는 대신, 순서가 바뀌어 있습니다.
	auto functor6 = std::bind(F, _2, _1);
	functor6('c', 3);



}