#pragma once
#include "Include.h"

class Status
{

public:
	Status();
	Status(int _MAX_HP, int _MAX_MP, int _STR, int _AGI, int _DEX, int _VIT, int _INT, int _FAITH, int NOW_EXP, int _MAX_EXP);

	bool live;

	// Define.h Âü°í
	int hp[2];
	int mp[2];
	int stat[6];
	int addStat[6];
	int skillSet[4];
	int equipItem[2];
	int exp[2];

	void Init();
	void Update();
	void Draw();

	void SetStatus(int _MAX_HP, int _MAX_MP, int _STR, int _AGI, int _VIT, int _DEX, int _INT, int _FAITH, int _SKILL, int _NOW_EXP, int _MAX_EXP);
};

extern Status status[4];