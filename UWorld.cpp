#include "UWorld.h"
#include "AActor.h"
#include <iostream>
#include <vector>

using namespace std;

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SetActors(vector<AActor*> NewActors)
{
	Actors = NewActors;
}

void UWorld::SortActor()
{
	//n^2
	for (int i = 0; i < Actors.size() - 1; ++i)
	{
		int MinIndex = i;
		for (int j = i + 1; j < Actors.size(); ++j)
		{
			if (Actors[j]->GetZOrder() < Actors[MinIndex]->GetZOrder())
			{
				MinIndex = j;
			}
		}
		swap(Actors[i], Actors[MinIndex]);
	}

}
