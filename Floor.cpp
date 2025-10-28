#include "Floor.h"
#include "PaperFlipBookComponent.h"
#include "FEngine.h"

AFloor::AFloor()
{
	FlipComp->SetZOrder(0);
	FlipComp->SetColor({ 100,150,100,0 });

	SDL_Surface* surface = SDL_LoadBMP("Floor.bmp");
	if (surface)
	{
		SDL_Log("load BMP: %s", SDL_GetError());
		FlipComp->MyTexture = SDL_CreateTextureFromSurface(FEngine::GetInstance()->MyRenderer, surface);
		SDL_DestroySurface(surface);
	}
}

AFloor::~AFloor()
{
}
