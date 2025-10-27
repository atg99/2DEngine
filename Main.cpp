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

#include <SDL3/SDL.h>

#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

#include <random>


#pragma comment(lib, "SDL3")


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
void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);
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

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); //SDL video initalize

	SDL_Window* MyWindow = SDL_CreateWindow("Game", 480, 480, SDL_WindowFlags SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	SDL_Event MyEvent;
	
	bool bIsRunning = true;
	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
		}
		else
		{
			//command queue
			SDL_SetRenderDrawColor(MyRenderer, 0, 0, 100, 255); // 그릴거 지정
			SDL_RenderClear(MyRenderer); //화면 업데이트

			
			//사각형 100개 랜덤
			for (int i = 0; i < 2; ++i)
			{
				SDL_SetRenderDrawColor(MyRenderer, distRGB(gen), distRGB(gen), distRGB(gen), 255);
				//SDL_Texture* MyTexture;
				//MyTexture = SDL_CreateTexture(MyRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 300, 300);
				SDL_FRect Rect = {float(SDL_rand(479)), float(SDL_rand(479)), float(SDL_rand(479)) + 1.f, float(SDL_rand(479)) + 1};
				//SDL_RenderTexture(MyRenderer, MyTexture, &Rect, &Rect);
				SDL_RenderFillRect(MyRenderer, &Rect);
				SDL_RenderRect(MyRenderer, &Rect);

				SDL_SetRenderDrawColor(MyRenderer, 150, 0, 0, 255);
				int CenterX = 240 + SDL_rand(30);
				int CenterY = 240 + SDL_rand(30);
				int Radius = 100;
				for (int Degree = 10; Degree <= 360; Degree += 10)
				{
					int OldX = SDL_cos(float((Degree - 10) * SDL_PI_F / 180.0f)) * Radius + CenterX;
					int OldY = SDL_sin(float((Degree - 10) * SDL_PI_F / 180.0f)) * Radius + CenterY;

					int X = SDL_cos(float(Degree * SDL_PI_F / 180.0f)) * Radius + CenterX;
					int Y = SDL_sin(float(Degree * SDL_PI_F / 180.0f)) * Radius + CenterY;

					SDL_RenderLine(MyRenderer, OldX, OldY, X, Y);
				}

				//DrawCircle(MyRenderer, 100, 100, 50);
				SDL_RenderPresent(MyRenderer); //화면 제공
			}
			
	
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	//TDynamicArray<int>* MyDyArray = new TDynamicArray<int>();
	//for (int i = 0; i < 8; ++i)
	//{
	//	MyDyArray->PushBack(i);
	//}

	//for (int i = 0; i < 25; ++i)
	//{
	//	MyDyArray[i];
	//}	

	//int IntNumbers[10] = { 10, 6, 5, 2, 9, 7, 4, 3, 1, 8 };
	//int FloatNumbers[10] = { 10.f, 6.f, 5.f, 2.f, 9, 7, 4, 3, 1, 8 };
	//Print<int>(IntNumbers, 10);


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

void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderPoint(renderer, centreX + x, centreY - y);
		SDL_RenderPoint(renderer, centreX + x, centreY + y);
		SDL_RenderPoint(renderer, centreX - x, centreY - y);
		SDL_RenderPoint(renderer, centreX - x, centreY + y);
		SDL_RenderPoint(renderer, centreX + y, centreY - x);
		SDL_RenderPoint(renderer, centreX + y, centreY + x);
		SDL_RenderPoint(renderer, centreX - y, centreY - x);
		SDL_RenderPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}