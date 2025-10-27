#include <iostream>
#include <random>
#include "Monster.h"
#include "UWorld.h"
#include "FEngine.h"
#include "Vector.h"
#include <vector>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(-1, 1);

AMonster::AMonster()
{
	ZOrder = 3;
	bIsCollision = true;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	int X = dist(gen);
	int Y = dist(gen);
	FVector2D SaveLocation = Location;
	Location.X += X;
	Location.Y += Y;


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
