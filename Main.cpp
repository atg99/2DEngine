#include <iostream>
#include "AActor.h"
#include "APlayer.h"
#include <vector>
#include "FEngine.h"
#include <fstream>
#include <string>
#include "Wall.h"

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

int main(int argc, char* argv[])
{
	FEngine::GetInstance()->Init();
	FEngine::GetInstance()->Run();
	FEngine::GetInstance()->Term();

	delete FEngine::GetInstance();
	//MyEngine = nullptr;

	return 0;
}