#include "Include.h"

Status status[4];

Status::Status()
{
	live = true;

	for (int i = 0; i < 2; i++)
		hp[i] = 0;

	for (int i = 0; i < 2; i++)
		mp[i] = 0;

	for (int i = 0; i < 6; i++)
	{
		stat[i] = 0;
		addStat[i] = 0;
	}

	for (int i = 0; i < 4; i++)
		skillSet[i] = 0;

	for (int i = 0; i < 2; i++)
		equipItem[i] = 0;

	for (int i = 0; i < 2; i++)
		exp[i] = 0;
}

Status::Status(int _MAX_HP, int _MAX_MP, int _STR, int _AGI, int _VIT, int _DEX, int _INT, int _FAITH, int _NOW_EXP, int _MAX_EXP)
{
	live = true;

	hp[MAX] = _MAX_HP;
	hp[NOW] = _MAX_HP;

	mp[MAX] = _MAX_MP;
	mp[NOW] = _MAX_MP;

	stat[STR] = _STR;
	stat[AGI] = _AGI;
	stat[VIT] = _VIT;
	stat[DEX] = _DEX;
	stat[INTELLI] = _INT;
	stat[FAITH] = _FAITH;

	addStat[STR] = 0;
	addStat[AGI] = 0;
	addStat[VIT] = 0;
	addStat[DEX] = 0;
	addStat[INTELLI] = 0;
	addStat[FAITH] = 0;

	equipItem[WEAPON] = 0;
	equipItem[ARMOR] = 0;

	exp[MAX] = _MAX_EXP;
	exp[NOW] = _NOW_EXP;
}

void Status::Init()
{

}

void Status::Update()
{

}

void Status::Draw()
{

}

void Status::SetStatus(int _MAX_HP, int _MAX_MP, int _STR, int _AGI, int _VIT, int _DEX, int _INT, int _FAITH, int _SKILL, int _NOW_EXP, int _MAX_EXP)
{
	hp[MAX] = _MAX_HP;
	hp[NOW] = _MAX_HP;

	mp[MAX] = _MAX_MP;
	mp[NOW] = _MAX_MP;

	stat[STR] = _STR;
	stat[AGI] = _AGI;
	stat[VIT] = _VIT;
	stat[DEX] = _DEX;
	stat[INTELLI] = _INT;
	stat[FAITH] = _FAITH;

	addStat[STR] = 0;
	addStat[AGI] = 0;
	addStat[VIT] = 0;
	addStat[DEX] = 0;
	addStat[INTELLI] = 0;
	addStat[FAITH] = 0;

	equipItem[WEAPON] = 0;
	equipItem[ARMOR] = 0;

	exp[MAX] = _MAX_EXP;
	exp[NOW] = _NOW_EXP;

	if (_SKILL == HERO)
		for (int i = 0; i < 4; i++)
			skillSet[i] = i;
	else if (_SKILL == THIEF)
		for (int i = 4; i < 8; i++)
			skillSet[i - 4] = i;
	else if (_SKILL == PRIEST)
		for (int i = 8; i < 12; i++)
			skillSet[i - 8] = i;
	else
		for (int i = 12; i < 16; i++)
			skillSet[i - 12] = i;
}