#pragma once
#include "Include.h"

class Monster
{
	enum mon { slime = 0, gobline, dragon };

	typedef struct Mon
	{

	};

public:
	Monster(void);
	~Monster(void);

	int monsterID;

	Sprite monSprite[3];

	DWORD MosterShow;

	int alpha;

	int STR;
	int MAX_HP;
	int NOW_HP;

	bool Live;

	void Init();
	void Update(int i);
	void Draw(int roc);
	void Reset();
};

extern Monster monster[3];

