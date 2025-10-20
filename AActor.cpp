#include "AActor.h"
#include <iostream>
#include "Vector.h"
#include "Windows.h"

using namespace std;

AActor::AActor()
{

}

AActor::~AActor()
{
	
}

void AActor::Tick()
{

}


void AActor::Render()
{
	COORD Position;
	Position.X = Location.X;
	Position.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;
}
