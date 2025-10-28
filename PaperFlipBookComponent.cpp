#include "PaperFlipBookComponent.h"
#include "Vector.h"
#include "Windows.h"
#include "AActor.h"
#include <iostream>
#include "FEngine.h"
#include <SDL3/SDL.h>

UPaperFlipBookComponent::UPaperFlipBookComponent()
{
}

UPaperFlipBookComponent::~UPaperFlipBookComponent()
{
}

void UPaperFlipBookComponent::Tick()
{
}

void UPaperFlipBookComponent::Render()
{
	//COORD Position;
	//Position.X = GetOwner()->GetActorLocation().X;
	//Position.Y = GetOwner()->GetActorLocation().Y;

	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	//std::cout << Shape;
	int SizeX = 30;
	int SizeY = 30;
	
	if (MyTexture)
	{
		SDL_FRect Rect = { float(GetOwner()->GetActorLocation().X * SizeX), float(GetOwner()->GetActorLocation().Y * SizeY), float(SizeX), float(SizeY) };
		SDL_RenderTexture(FEngine::GetInstance()->MyRenderer, MyTexture, nullptr, &Rect);
	}
	else
	{
		SDL_FRect Rect = { float(GetOwner()->GetActorLocation().X * SizeX), float(GetOwner()->GetActorLocation().Y * SizeY), float(SizeX), float(SizeY) };
		SDL_SetRenderDrawColor(FEngine::GetInstance()->MyRenderer, Color.r, Color.g, Color.b, Color.a);
		SDL_RenderFillRect(FEngine::GetInstance()->MyRenderer, &Rect);
	}

}
