#include "FEngine.h"
#include <fstream>
#include <string>
#include <conio.h>
#include "Wall.h"
#include "UWorld.h"
#include <iostream>
#include "Floor.h"
#include "AActor.h"
#include "APlayer.h"
#include "Monster.h"
#include "Goal.h"
#include <algorithm>
#include "GameMode.h"
#include "Timer.h"
#include "Input.h"
#include "PaperFlipBookComponent.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#pragma comment(lib, "SDL3")

using namespace std;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine():
	World(nullptr)
{
	Timer = new UTimer();
	MyEvent = SDL_Event();
	InputDevice = new UInput();
}

FEngine::~FEngine()
{
	if (World)
	{
		delete World;
	}
	if (Timer)
	{
		delete Timer;
	}
	if (InputDevice)
	{
		delete InputDevice;
	}
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Timer->Tick();
		if (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_EVENT_QUIT:
				bIsRunning = false;
				break;
			default:
				break;
			}
		}
		Input();
		Tick();
		Render();		
	}
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
}

void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}

void FEngine::GameEnd()
{
	bIsRunning = false;
}

void FEngine::Input()
{
	InputDevice->Tick();
}

void FEngine::Tick()
{
			////command queue
			//SDL_SetRenderDrawColor(MyRenderer, 0, 0, 100, 255); // 그릴거 지정
			//SDL_RenderClear(MyRenderer); //화면 업데이트


			////사각형 100개 랜덤
			//for (int i = 0; i < 2; ++i)
			//{
			//	SDL_SetRenderDrawColor(MyRenderer, distRGB(gen), distRGB(gen), distRGB(gen), 255);
			//	//SDL_Texture* MyTexture;
			//	//MyTexture = SDL_CreateTexture(MyRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 300, 300);
			//	SDL_FRect Rect = { float(SDL_rand(479)), float(SDL_rand(479)), float(SDL_rand(479)) + 1.f, float(SDL_rand(479)) + 1 };
			//	//SDL_RenderTexture(MyRenderer, MyTexture, &Rect, &Rect);
			//	SDL_RenderFillRect(MyRenderer, &Rect);
			//	SDL_RenderRect(MyRenderer, &Rect);

			//	SDL_SetRenderDrawColor(MyRenderer, 150, 0, 0, 255);
			//	int CenterX = 240 + SDL_rand(30);
			//	int CenterY = 240 + SDL_rand(30);
			//	int Radius = 100;
			//	for (int Degree = 10; Degree <= 360; Degree += 10)
			//	{
			//		int OldX = SDL_cos(float((Degree - 10) * SDL_PI_F / 180.0f)) * Radius + CenterX;
			//		int OldY = SDL_sin(float((Degree - 10) * SDL_PI_F / 180.0f)) * Radius + CenterY;

			//		int X = SDL_cos(float(Degree * SDL_PI_F / 180.0f)) * Radius + CenterX;
			//		int Y = SDL_sin(float(Degree * SDL_PI_F / 180.0f)) * Radius + CenterY;

			//		SDL_RenderLine(MyRenderer, OldX, OldY, X, Y);
			//	}

			//	//DrawCircle(MyRenderer, 100, 100, 50);
			//	SDL_RenderPresent(MyRenderer); //화면 제공
			//}

	GetWorld()->Tick();
}

void FEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 100, 100, 100, 100);
	SDL_RenderClear(MyRenderer);
	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}

void FEngine::OpenLevel()
{
	World = new UWorld();

	std::ifstream Mapfile;
	Mapfile.open("Map.map");

	if (Mapfile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		string Line;
		while (Mapfile.getline(Buffer, 80))
		{
			Line = Buffer;
			//cout << Line << endl;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetFlipComp()->SetShape(Line[X]);
					
					World->SpawnActor(NewActor);

				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetFlipComp()->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetFlipComp()->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetFlipComp()->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				AActor* NewActor = new AFloor();
				NewActor->SetActorLocation(FVector2D(X, Y));
				NewActor->GetFlipComp()->SetShape(Line[X]);
				World->SpawnActor(NewActor);
			}
			Y++;
		}
	}
	Mapfile.close();
	World->SortActor();

	World->SpawnActor(new AGameMode());
}

double FEngine::GetWorldDeltaSeconds() const
{
	return Timer->DeltaSeconds;
}
