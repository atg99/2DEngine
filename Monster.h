#pragma once
#include "AActor.h"
class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;
};

