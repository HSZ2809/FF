#pragma once
#include "Include.h"

class Transition
{

public:
	Transition();
	~Transition();

	Sprite Shield, Sword;
	Sprite White_Screen;
	DWORD Tran_Ani;

	int Shield_Y, L_Sword, LT_Sword, C_Sword, R_Sword, RT_Sword;
	int Shield_alpha, L_Sword_alpha, C_Sword_alpha, R_Sword_alpha;
	int White_Alpha;

	int X, Y;//임시 케릭터 위치 XY값
	int Incounter;

	BOOL battle_E = true;

	void Init();
	void Update();
	void Draw();
};

extern Transition tran;