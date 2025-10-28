#pragma once

class AActor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0; //순수가상함수 추상화클래스 자식이 재정의해야함 -> interface?

	AActor* GetOwner() const;
	void SetOwner(AActor* NewOwner);

protected:
	AActor* Owner = nullptr;
};

