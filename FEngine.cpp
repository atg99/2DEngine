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

using namespace std;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine():
	World(nullptr)
{
}

FEngine::~FEngine()
{
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Init()
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
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);

				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else
				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}

	vector<AActor*> Actors = World->GetAllActors();

	for (int i = 0; i < Actors.size()-1; ++i)
	{
		int MinIndex = i;
		for (int j = i + 1; j < Actors.size(); ++j)
		{
			if (Actors[j]->ZOrder < Actors[MinIndex]->ZOrder)
			{
				MinIndex = j;
			}
		}
		swap(Actors[i], Actors[MinIndex]);
	}

	World->SetActors(Actors);

	Mapfile.close();
}

void FEngine::Term()
{
}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	//system("cls");
	GetWorld()->Render();
}
