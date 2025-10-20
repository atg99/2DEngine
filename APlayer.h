#pragma once
#include "AActor.h"
class APlayer : public AActor
{
public:
	APlayer();

	virtual ~APlayer();

	virtual void Tick() override;

	//overloading
	//name mangling
	void Jump();

	void Jump(int a);

	void Jump(float b);

};

