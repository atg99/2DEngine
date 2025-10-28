#include "Input.h"
#include "FEngine.h"

UInput::UInput()
{
}

UInput::~UInput()
{
}

void UInput::Tick()
{
	if (FEngine::GetInstance()->MyEvent.key.down)
	{
		KeyCode = FEngine::GetInstance()->MyEvent.key.key;
	}
	else
	{
		KeyCode = 0;
	}
	
}
