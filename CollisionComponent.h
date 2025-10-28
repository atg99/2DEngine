#pragma once
#include "ActorComponent.h"

class AActor;

class UCollisionComponent : public UActorComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;

	__forceinline bool GetCollision() const { return bIsCollision; }

	__forceinline bool GetOverlap() const { return bIsOverlap; }

	__forceinline void SetCollision(bool Collsiion) { bIsCollision = Collsiion; return; }

	__forceinline void SetOverlap(bool Overlap) { bIsOverlap = Overlap; return; }

	virtual bool CheckCollsion(const AActor* Other);

protected:

	bool bIsCollision = false;

	bool bIsOverlap = false;
};

