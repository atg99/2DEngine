#include "AActor.h"
#include <iostream>
#include "Vector.h"
#include "Windows.h"
#include "FEngine.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

using namespace std;

AActor::AActor()
{
	FlipComp = new UPaperFlipBookComponent();
	FlipComp->SetOwner(this);
	AddComponent(FlipComp);

	CollisionComp = new UCollisionComponent();
	CollisionComp->SetOwner(this);
	AddComponent(CollisionComp);
}

AActor::~AActor()
{
	for (auto Comp : Components)
	{
		delete Comp;
	}
}

void AActor::Tick()
{

}

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}

std::vector<UComponent*> AActor::GetComponents()
{
	return Components;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}
