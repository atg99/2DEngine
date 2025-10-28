#include "Goal.h"
#include "PaperFlipBookComponent.h"

AGoal::AGoal()
{
	FlipComp->SetZOrder(2);
	FlipComp->SetColor({ 255,255,0,0 });
}

AGoal::~AGoal()
{
}
