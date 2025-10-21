#pragma once
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int Size = 10;

	int* Data = new int[Size];

	int Index = 0;

	void PushBack(int Value);
};

