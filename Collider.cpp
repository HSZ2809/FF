#include "Include.h"

Collider collider;

Collider::Collider() {};

Collider::~Collider() {};

bool Collider::SquareCollider(int Obj1Left, int  Obj1Top, int Obj1Right, int  Obj1Bottom,
	int Obj2Left, int  Obj2Top, int Obj2Right, int  Obj2Bottom)
{
	if (Obj1Left < Obj2Right && Obj1Right > Obj2Left && Obj1Top < Obj2Bottom && Obj1Bottom > Obj2Top)
		return true;
	else
		return false;
}

bool Collider::CircleCollider(int Obj1X, int  Obj1Y, int Obj1R, int Obj2X, int  Obj2Y, int Obj2R)
{
	float distance = (float)sqrt((Obj1X - Obj2X) * (Obj1X - Obj2X) + (Obj1Y - Obj2Y) * (Obj1Y - Obj2Y));

	if (distance < Obj1R + Obj2R)
		return true;
	else
		return false;
}

bool Collider::CanCircleMove(int Obj1X, int  Obj1Y, int Obj1R, int Obj2X, int  Obj2Y, int Obj2R, int direction)
{
	int dir[4] = { 0 };
	dir[direction] = 5;

	float distance = (float)sqrt((Obj1X - dir[LEFT] + dir[RIGHT] - Obj2X) * (Obj1X - dir[LEFT] + dir[RIGHT] - Obj2X) + (Obj1Y - dir[UP] + dir[DOWN] - Obj2Y) * (Obj1Y - dir[UP] + dir[DOWN] - Obj2Y));

	if (distance > Obj1R + Obj2R)
		return true;
	else
		return false;
}

bool Collider::CanSquareMove(int Obj1Left, int  Obj1Top, int Obj1Right, int  Obj1Bottom,
	int Obj2Left, int  Obj2Top, int Obj2Right, int  Obj2Bottom, int direction)
{
	int dir[4] = { 0 };
	dir[direction] = 5;

	if (Obj1Left - dir[LEFT] < Obj2Right && Obj1Right + dir[RIGHT] > Obj2Left && Obj1Top - dir[UP] < Obj2Bottom && Obj1Bottom + dir[DOWN] > Obj2Top)
		return false;
	else
		return true;
}

bool Collider::CanMove(int dir)
{
	if (map.m_Stage == 1)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage1_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	else if (map.m_Stage == 2)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage2_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	else if (map.m_Stage == 3)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage3_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	else if (map.m_Stage == 4)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage4_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	else if (map.m_Stage == 5)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage5_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	else if (map.m_Stage == 6)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (map.m_Stage6_map[x][y] >= 9)
				{
					bool move;
					move = CanSquareMove(character.location[HERO].m_X, character.location[HERO].m_Y, character.location[HERO].m_X + 32, character.location[HERO].m_Y + 32,
						32 * y, 32 * x, (32 * y + 32), (32 * x + 32), dir);

					if (move == false)
						return false;
				}
			}
		}
	}
	return true;
}