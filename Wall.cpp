#include "Wall.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"
#include "FEngine.h"

AWall::AWall()
{
	FlipComp->SetZOrder(1);
	FlipComp->SetColor({ 255,100,0,0 });

	SDL_Surface* surface = SDL_LoadBMP("Wall.bmp");
	if (surface)
	{
		SDL_Log("load BMP: %s", SDL_GetError());
		FlipComp->MyTexture = SDL_CreateTextureFromSurface(FEngine::GetInstance()->MyRenderer, surface);
		SDL_DestroySurface(surface);
	}

	CollisionComp->SetCollision(true);
}

AWall::~AWall()
{
}
