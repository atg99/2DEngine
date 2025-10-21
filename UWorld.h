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

	std::vector<AActor*> GetAllActors() const;

	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();

	virtual void Render();

	void SetActors(vector<AActor*> NewActors);

	void SortActor();

protected:
	std::vector<AActor*> Actors;
};

