#include "CollisionComponent.h"
#include "AActor.h"

UCollisionComponent::UCollisionComponent()
{
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::Tick()
{
}

bool UCollisionComponent::CheckCollsion(const AActor* Other)
{
	if (Other->GetCollisionComp()->GetOverlap())
	{
		return false;
	}
	if (Other->GetCollisionComp()->GetCollision() && bIsCollision && Other->GetActorLocation() == GetOwner()->GetActorLocation())
	{
		return true;
	}
	return false;
}