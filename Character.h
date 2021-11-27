#pragma once

#include "Include.h"


struct Cha_location
{
	double m_X;
	double m_Y;
};

class Character
{



public:
	Sprite HeroSprite[4][3];
	Sprite ThiefSprite[4][3];
	Sprite ThiefDead;
	Sprite PriestSprite[4][3];
	Sprite PriestDead;
	Sprite WizardSprite[4][3];
	Sprite WizardDead;

	Character();
	~Character();

	DWORD AniTime1;
	DWORD AniTime2;

	bool m_Life;
	int m_TgCount1;
	int m_TgCount2;

	Cha_location location[4];

	enum Move { MoveDown = 1, MoveUp, MoveLeft, MoveRight };
	int Move_key;

	void Init();
	void Update();
	void Draw();
	void Reset();
	void Chasing();
};

extern Character character;