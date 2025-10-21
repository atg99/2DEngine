#include <iostream>
#include "AActor.h"
#include "APlayer.h"
#include <vector>
#include "FEngine.h"
#include <fstream>
#include <string>
#include "Wall.h"

using namespace std;

// �̱��� ���� �ν��Ͻ��� �ϳ��� ����� ���������� �����Ѵ�
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

	////���� �Լ� �ƹ������� ȣ�� ����
	//static void StaticFunc();

	////static ����� global data ������ ���� �������� �ʾƵ� �����ϸ� �޸� ������ ����
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
//�ݹ� �۾��� ������ ������ �Լ� ȣ��
void OnReceive(int (*Callback)())
{
	bool bEnd = false;
	while (!bEnd)
	{

	}
	
	Callback();
}

//c��Ÿ��
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
		cout << Numbers[i]);
	}
}

template<typename T, typename Y>
class TemplateClass
{
public:
	T Data;
	Y Data2;
};


int main(int argc, char* argv[])
{
	int IntNumbers[10] = { 10, 6, 5, 2, 9, 7, 4, 3, 1, 8 };
	int FloatNumbers[10] = { 10.f, 6.f, 5.f, 2.f, 9, 7, 4, 3, 1, 8 };
	Print<int>(IntNumbers, 10);
	//FEngine::GetInstance()->Init();
	//FEngine::GetInstance()->Run();
	//FEngine::GetInstance()->Term();

	//delete FEngine::GetInstance();

	void (*FunctionPointer)();

	FunctionPointer = A;

	FunctionPointer();

	Sort(Greater);

	//MyEngine = nullptr;

	//
	// Singleton::GetInstance();
	//Singleton::Instance;

	return 0;
}