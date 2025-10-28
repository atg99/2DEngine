#include "APlayer.h"
#include <iostream>
#include "FEngine.h"
#include <vector>
#include "UWorld.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"
#include <SDL3/SDL.h>

using namespace std;

APlayer::APlayer()
{
	FlipComp->SetZOrder(4);
	FlipComp->SetColor({ 0,255,0,0 });

	SDL_Surface* surface = SDL_LoadBMP("Cat.bmp");
	if (surface)
	{
		SDL_Log("load BMP: %s", SDL_GetError());
		FlipComp->MyTexture = SDL_CreateTextureFromSurface(FEngine::GetInstance()->MyRenderer, surface);
		SDL_DestroySurface(surface);
	}

	CollisionComp->SetCollision(true);
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
