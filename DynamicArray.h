#pragma once

//템플릿은 컴파일시에 코드생성
template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{
		Data = new T[Capacity];
	}

	TDynamicArray(T Capacity) : Capacity(Capacity)
	{
		Data = new T[Capacity];
	}

	TDynamicArray(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS->Size;
		this->Capacity = RHS->Capacity;
		this->Index = RHS->Index;

		for (size_t i = 0; i < Size; ++i)
		{
			Data[i] = RHS.Data[i];
		}
	}

	virtual ~TDynamicArray()
	{
		if (Data)
		{
			delete[] Data;
		}
	}
protected:

	size_t Size = 0;

	size_t Capacity = 1;

	T* Data;

	int Index = 0;

public:

	size_t GetSize()
	{
		return Size;
	}

	size_t GetCapacity()
	{
		return Capacity;
	}

	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (Size < Capacity)
		{
			Data[Index] = Value;
			Index++;
			Size++;
		}
		else
		{
			int NewCapacity = Capacity * 2;
			T* NewData = new T[NewCapacity];
			for (int i = 0; i < Size; ++i)
			{
				NewData[i] = Data[i];
			}
			//memcpy();
			//memmove();
			NewData[Size] = Value;

			if (Data)
			{
				delete[] Data;
			}

			Data = NewData;
			Capacity = NewCapacity;
			Index++;
			Size++;
		}
	}

	
};

