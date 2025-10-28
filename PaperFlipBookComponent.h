#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"

class UPaperFlipBookComponent : public USceneComponent
{
public:

	UPaperFlipBookComponent();
	virtual ~UPaperFlipBookComponent();

	virtual void Tick() override;

	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}

	__forceinline void SetShape(char MyShape) {
		Shape = MyShape;
		return;
	}

	__forceinline int GetZOrder()
	{
		return ZOrder;
	}

	__forceinline void SetZOrder(int InZOrder)
	{
		ZOrder = InZOrder;
		return;
	}

	__forceinline void SetColor(SDL_Color InColor)
	{
		Color = InColor;
		return;
	}

protected:

	char Shape;

	int ZOrder = 0;

	SDL_Color Color = { 255,255,255,255 };

public:
	SDL_Texture* MyTexture = nullptr;
};

