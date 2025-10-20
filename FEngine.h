#pragma once

class UWorld;

class FEngine
{
protected:
	FEngine();

public:
	//생성자를 프라이빗으로 하면 싱글톤 (하나만 생성할 수 있음)
	
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void Term();

	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();
	
	class UWorld* World;

	bool bIsRunning = true;

	int KeyCode = 0;

public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

protected:
	static FEngine* Instance;
};

//extern FEngine* GEngine;

#define GEngine    FEngine::GetInstance();