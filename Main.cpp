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

int main(int argc, char* argv[])
{
	FEngine::GetInstance()->Init();
	FEngine::GetInstance()->Run();
	FEngine::GetInstance()->Term();

	delete FEngine::GetInstance();
	//MyEngine = nullptr;

	return 0;
}