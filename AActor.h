#pragma once
#include "Vector.h"

class AActor
{
public:
	AActor();

	virtual ~AActor();

	virtual void Tick();

	//�Լ������� ���� �Լ�ȣ�� �����ص� ����
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	__forceinline char GetShape() 
	{
		return Shape;
	}

	__forceinline void SetShape(char MyShape) {
		Shape = MyShape;
	}

	__forceinline int GetZOrder()
	{
		return ZOrder;
	}

	void Render();

protected:
	FVector2D Location;

	char Shape;

	int ZOrder = 0;
};

