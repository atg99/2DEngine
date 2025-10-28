#pragma once
#include <SDL3/SDL.h>
#include "Input.h"

class UWorld;
class UTimer;


class FEngine
{
protected:
	FEngine();

public:
	//�����ڸ� �����̺����� �ϸ� �̱��� (�ϳ��� ������ �� ����)
	
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
		return InputDevice->KeyCode;
	}

	void GameEnd();

protected:
	void Input();
	void Tick();
	void Render();
	
	class UWorld* World;

	bool bIsRunning = true;

public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

	void OpenLevel();

protected:
	static FEngine* Instance;
public:
	SDL_Window* MyWindow;

	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	double GetWorldDeltaSeconds() const;

protected:
	UTimer* Timer;

	UInput* InputDevice;
};

//extern FEngine* GEngine;

#define GEngine    FEngine::GetInstance()