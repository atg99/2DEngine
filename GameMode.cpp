#include "GameMode.h"
#include "Vector.h"
#include "FEngine.h"
#include "UWorld.h"
#include "APlayer.h"

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	//AActor* Player = nullptr;
	//vector<AActor*> AllActors;
	//FEngine::GetInstance()->GetWorld()->GetAllActors(AllActors);
	//for (auto Actor : AllActors)
	//{
	//	if (dynamic_cast<APlayer*>(Actor))
	//	{
	//		Player = Actor;
	//	}
	//}
}

void AGameMode::Render()
{
}
