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

	//�Լ������� ���� �Լ�ȣ�� �����ص� ����
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

