#include "APlayer.h"
#include <iostream>
#include "FEngine.h"

using namespace std;

APlayer::APlayer()
{
	ZOrder = 4;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	AActor::Tick();
	//cout << "Player Tick" << endl;
	int KeyCode = FEngine::GetInstance()->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}
}
