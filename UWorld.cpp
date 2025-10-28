#include "UWorld.h"
#include "AActor.h"
#include <iostream>
#include <vector>
#include "SceneComponent.h"
#include "PaperFlipBookComponent.h"
#include <algorithm>

using namespace std;

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::GetAllActors(vector<AActor*>& AllActors) const
{
	AllActors = Actors;
	return;
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
		for (auto Comp : Actor->GetComponents())
		{
			if (USceneComponent* SceneComp = dynamic_cast<USceneComponent*>(Comp))
			{
				SceneComp->Render();
			}
		}
	}
}

void UWorld::SetActors(vector<AActor*> NewActors)
{
	Actors = NewActors;
}

void UWorld::SortActor()
{
	std::sort(Actors.begin(), Actors.end(), [&](AActor* A, AActor* B)
		{
			return A->GetFlipComp()->GetZOrder() < B->GetFlipComp()->GetZOrder();
		});
	//n^2
	//for (int i = 0; i < Actors.size() - 1; ++i)
	//{
	//	int MinIndex = i;
	//	for (int j = i + 1; j < Actors.size(); ++j)
	//	{
	//		if (Actors[j]->GetFlipComp()->GetZOrder() < Actors[MinIndex]->GetFlipComp()->GetZOrder())
	//		{
	//			MinIndex = j;
	//		}
	//	}
	//	swap(Actors[i], Actors[MinIndex]);
	//}
}

void UWorld::SimulatePhysics()
{
}
