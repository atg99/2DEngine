#include <iostream>
#include <random>
#include "Monster.h"
#include "UWorld.h"
#include "FEngine.h"
#include "Vector.h"
#include <vector>
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0, 3);

AMonster::AMonster()
{
	FlipComp->SetZOrder(3);
	FlipComp->SetColor({ 0,100,255,0 });

	SDL_Surface* surface = SDL_LoadBMP("Monster1.bmp");
	if (surface)
	{
		SDL_Log("load BMP: %s", SDL_GetError());
		FlipComp->MyTexture = SDL_CreateTextureFromSurface(FEngine::GetInstance()->MyRenderer, surface);
		SDL_DestroySurface(surface);
	}

	CollisionComp->SetOverlap(true);
	CollisionComp->SetCollision(true);

}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += float(FEngine::GetInstance()->GetWorldDeltaSeconds());
	if (TotalTime < 0.5f)
	{
		return;
	}
	TotalTime = 0;
	int dir = dist(gen);
	FVector2D SaveLocation = Location;
	
	switch (dir)
	{
	case 0:
		Location.X++;
		break;
	case 1:
		Location.X--;
		break;
	case 2:
		Location.Y++;
		break;
	case 3:
		Location.Y--;
		break;
	default:
		break;
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
		if (CollisionComp->CheckCollsion(OtherActor))
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
