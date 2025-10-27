#pragma once
#include "Vector.h"

class AActor
{
public:
	AActor();

	virtual ~AActor();

	virtual void Tick();

	//함수본문을 복붙 함수호출 오버해드 감소
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	__forceinline bool GetbIsCollision() const
	{
		return bIsCollision;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	__forceinline char GetShape() 
	{
		return Shape;
	}

	__forceinline void SetShape(char MyShape) {
		Shape = MyShape;
	}

	__forceinline int GetZOrder()
	{
		return ZOrder;
	}

	virtual void Render();

protected:
	FVector2D Location;

	char Shape;

	int ZOrder = 0;

	bool bIsCollision = false;

	bool bIsOverlap = false;

public:

protected:
	virtual bool CheckCollsion(const AActor* Other);
	virtual void ActorBeginOverlap();
	virtual void Hit();
};

