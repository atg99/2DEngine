#include "APlayer.h"
#include <iostream>
#include "FEngine.h"
#include <vector>
#include "UWorld.h"

using namespace std;

APlayer::APlayer()
{
	ZOrder = 4;
	bIsCollision = true;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	AActor::Tick();
	//cout << "Player Tick" << endl;
	int KeyCode = FEngine::GetInstance()->GetKeyCode();
	FVector2D SaveLocation = Location;

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}

	bool bFlag = false;
	vector<AActor*> AllActors;
	FEngine::GetInstance()->GetWorld()->GetAllActors(AllActors);
	for (auto OtherActor : AllActors)
	{
		if (OtherActor == this)
		{
			continue;
		}
		if (CheckCollsion(OtherActor))
		{
			bFlag = true;
			break;
		}
	}
	
	if (bFlag)
	{
		Location = SaveLocation;
	}
}
