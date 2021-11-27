#include "Include.h"

Monster monster[3];

Monster::Monster(void)
{
	STR = SLIME_STR;
	MAX_HP = SLIME_HP;
	NOW_HP = SLIME_HP;

	monsterID = slime;

	MosterShow = 0;
}

Monster::~Monster(void) {}

void Monster::Init()
{
	Live = true;

	alpha = 0;

	char FileName[256];

	sprintf_s(FileName, "./resource/Img/Monster/slime.png");
	monSprite[slime].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Monster/slime.png");
	monSprite[gobline].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Monster/dragon.png");
	monSprite[dragon].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Monster::Reset()
{
	monsterID = rand() % 3;

	if (monsterID == slime)
	{
		STR = SLIME_STR;
		MAX_HP = SLIME_HP;
		NOW_HP = SLIME_HP;
	}
	else if (monsterID == gobline)
	{
		STR = GOBLINE_STR;
		MAX_HP = GOBLINE_HP;
		NOW_HP = GOBLINE_HP;
	}
	else
	{
		STR = DRAGON_STR;
		MAX_HP = DRAGON_HP;
		NOW_HP = DRAGON_HP;
	}

	Live = true;
}

void Monster::Update(int i)
{
	if (Live == true)
	{
		if (GetTickCount64() - MosterShow > 30)
		{
			if (alpha >= 255)
				alpha = 255;
			else
				monster[i].alpha += 5;

			MosterShow = GetTickCount64();
		}
	}
}

void Monster::Draw(int roc)
{
	if (Live == true)
	{
		monSprite[monsterID].SetColor(255, 255, 255, alpha);  // 투명도 변경
		monSprite[monsterID].Draw(roc, 100);
	}
	else
	{
		monSprite[monsterID].SetColor(100, 100, 100, alpha);
		monSprite[monsterID].Draw(roc, 100);
	}
}