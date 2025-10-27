#pragma once
#include <vector>

using namespace std;
//�����ͺ����� ���漱��
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void GetAllActors(vector<AActor*>& AllActors) const;

	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();

	virtual void Render();

	void SetActors(vector<AActor*> NewActors);

	void SortActor();

	virtual void SimulatePhysics();

protected:
	std::vector<AActor*> Actors;
};

