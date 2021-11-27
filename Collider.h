#pragma once
#include "Include.h"

class Collider
{
private:

public:
	Collider();
	~Collider();

	bool SquareCollider(int Obj1Left, int  Obj1Top, int Obj1Right, int  Obj1Bottom,
		int Obj2Left, int  Obj2Top, int Obj2Right, int  Obj2Bottom);

	bool CircleCollider(int Obj1X, int  Obj1Y, int Obj1R, int Obj2X, int  Obj2Y, int Obj2R);

	bool CanCircleMove(int Obj1X, int  Obj1Y, int Obj1R, int Obj2X, int  Obj2Y, int Obj2R, int direction);

	bool CanSquareMove(int Obj1Left, int  Obj1Top, int Obj1Right, int  Obj1Bottom,
		int Obj2Left, int  Obj2Top, int Obj2Right, int  Obj2Bottom, int direction);

	bool CanMove(int dir);
};

extern Collider collider;