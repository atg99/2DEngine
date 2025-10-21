#pragma once
#include <vector>

using namespace std;
//포언터변수는 전방선언
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

