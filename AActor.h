#pragma once
#include "Vector.h"

#include <vector>

class UComponent;
class UPaperFlipBookComponent;
class UCollisionComponent;
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

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	void AddComponent(UComponent* InComponent);

	std::vector<UComponent*> GetComponents();

	__forceinline UPaperFlipBookComponent* GetFlipComp() const
	{
		return FlipComp;
	}

	__forceinline UCollisionComponent* GetCollisionComp() const
	{
		return CollisionComp;
	} 

protected:
	FVector2D Location;

	UPaperFlipBookComponent* FlipComp;

	UCollisionComponent* CollisionComp;

	std::vector<UComponent*> Components;

public:



protected:
	
	virtual void ActorBeginOverlap();
	virtual void Hit();
};

