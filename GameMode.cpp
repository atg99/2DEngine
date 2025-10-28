#include "GameMode.h"
#include "Vector.h"
#include "FEngine.h"
#include "UWorld.h"
#include "APlayer.h"
#include "Goal.h"
#include "Monster.h"

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor* Player = nullptr;
	vector<AActor*> AllActors;
	FEngine::GetInstance()->GetWorld()->GetAllActors(AllActors);
	for (auto Actor : AllActors)
	{
		if (dynamic_cast<APlayer*>(Actor))
		{
			Player = Actor;
		}
	}

	AActor* Goal = nullptr;
	for (auto Actor : AllActors)
	{
		if (dynamic_cast<AGoal*>(Actor))
		{
			Goal = Actor;
		}
	}

	AActor* Monster = nullptr;
	for (auto Actor : AllActors)
	{
		if (dynamic_cast<AMonster*>(Actor))
		{
			Monster = Actor;
		}
	}

	if (Player && Goal)
	{
		if (Player->GetActorLocation() == Goal->GetActorLocation())
		{
			//GEngine->GameEnd();
		}
	}
	
	if (Player && Monster)
	{
		if (Player->GetActorLocation() == Monster->GetActorLocation())
		{
			//GEngine->GameEnd();
		}
	}


	SDL_Log("deltaSeconds : %f", GEngine->GetWorldDeltaSeconds());
}

