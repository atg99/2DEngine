#include "Component.h"

UComponent::UComponent()
{
}

UComponent::~UComponent()
{
}

void UComponent::Tick()
{
	return;
}


AActor* UComponent::GetOwner() const
{
	return Owner;
}

void UComponent::SetOwner(AActor* NewOwner)
{
	Owner = NewOwner;
}
