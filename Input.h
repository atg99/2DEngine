#pragma once
class UInput
{
public:
	UInput();
	virtual ~UInput();

	void Tick();

	inline static int KeyCode = 0;
};

