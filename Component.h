#pragma once

class AActor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0; //���������Լ� �߻�ȭŬ���� �ڽ��� �������ؾ��� -> interface?

	AActor* GetOwner() const;
	void SetOwner(AActor* NewOwner);

protected:
	AActor* Owner = nullptr;
};

