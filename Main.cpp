#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>

#include "AActor.h"
#include "APlayer.h"
#include "FEngine.h"
#include "Wall.h"
#include "DynamicArray.h"
#include "Vector.h"
#include <SDL3/SDL_main.h>
#include <random>


using namespace std;

// 싱글톤 패턴 인스턴스를 하나만 만들게 문법적으로 강제한다
class Singleton
{
protected:
	Singleton()
	{

	}

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}
		return Instance;
	}

protected:
	static Singleton* Instance;

	////정적 함수 아무데서나 호출 가능
	//static void StaticFunc();

	////static 선언시 global data 영역에 생성 선언하지 않아도 빌드하면 메모리 영역에 생김
	//static int InstanceCount;
};

void A()
{
	cout << 'A' << endl;
}

int Sum(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

void Print(int a, int b, int (*FP)(int, int))
{
	cout << FP(a, b) << endl;
}

void Sort(bool (*Compare)(int, int))
{
	int Numbers[10] = {10, 6, 5, 2, 9, 7, 4, 3, 1, 8};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (Compare(Numbers[i], Numbers[j]))
			{
				int Temp = Numbers[i];
				Numbers[i] = Numbers[j];
				Numbers[j] = Temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << Numbers[i];
	}
}

bool Greater(int a, int b)
{
	return a > b;
}

bool Less(int a, int b)
{
	return a < b;
}
//콜백 작업이 끝나면 지정한 함수 호출
void OnReceive(int (*Callback)())
{
	bool bEnd = false;
	while (!bEnd)
	{

	}
	
	Callback();
}

//c스타일
void Print(void* Numbers, int _SizeOfElement,int _NumberOfElement)
{
	for (int i = 0; i < _NumberOfElement; ++i)
	{
		cout << (float*)((char*)Numbers+(i * _SizeOfElement));
	}
}

template<typename T>
void Print(T* Numbers, int _NumberOfElement)
{
	for (int i = 0; i < _NumberOfElement; ++i)
	{
		cout << Numbers[i];
	}
}

template<typename T, typename Y>
class TemplateClass
{
public:
	T Data;
	Y Data2;
};
//C++ 하려면 필수
//class 설계
//자료구조(STL) 사용 잘하나

int SDL_main(int argc, char* argv[])
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distpos(0, 480);
	uniform_int_distribution<> distsize(0, 100);
	uniform_int_distribution<> distRGB(0, 255);
	uniform_int_distribution<> distNum(1000, 10000);

	FEngine::GetInstance()->Init();
	FEngine::GetInstance()->Run();
	FEngine::GetInstance()->Term();

	delete FEngine::GetInstance();

	void (*FunctionPointer)();

	FunctionPointer = A;

	FunctionPointer();

	Sort(Greater);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << endl;
	}

	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	for (auto li : l)
	{
		cout << li << endl;
	}


	//MyEngine = nullptr;

	//
	// Singleton::GetInstance();
	//Singleton::Instance;

	return 0;
}