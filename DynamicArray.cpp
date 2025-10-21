#include "DynamicArray.h"

TDynamicArray::TDynamicArray()
{
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Index < Size)
	{
		Data[Index] = Value;
		Index++;
	}
	else
	{
		int NewSize = Size + 1;
		int* NewData = new int[NewSize];
		for (int i = 0; i < NewSize; ++i)
		{
			if (i == NewSize - 1)
			{
				NewData[i] = Value;
				continue;
			}
			NewData[i] = Data[i];
		}
		delete[] Data;
		Data = NewData;
		Size = NewSize;
		Index++;
	}
}
