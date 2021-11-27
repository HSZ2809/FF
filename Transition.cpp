#include "Include.h"


Transition tran;

Transition::Transition(){}
Transition::~Transition(){}

void Transition::Init()
{
	srand(time(NULL));

	Shield_Y = 272 - 120;
	L_Sword = 482 - 100;
	LT_Sword = 275 - 100;
	C_Sword = 272 - 200;
	R_Sword = 742 + 100;
	RT_Sword = 220 - 100;
	White_Alpha = 0;
	Incounter = 0;

	char FileName[256];

	sprintf_s(FileName, "./resource/Img/ui/Shield.png");
	Shield.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/Sword.png");
	Sword.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/white_screen.png");
	White_Screen.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Transition::Update()
{
	//X = character.location[HERO].m_X / 10;
	//Y = character.location[HERO].m_Y / 10;
	//
	//if (X == rand() % 1280)
	//{
	//	Incounter++;
	//}
	//if (Y == rand() % 768)
	//{
	//	Incounter++;
	//}

	if (Incounter >= 1)
	{
		Gmanager.m_GameMap = false;
		if (battle_E == true && C_Sword == 100)
		{
			EffectPlay(sound.Battle_Start);
			battle_E = false;
		}
		if (GetTickCount() - Tran_Ani > 10)
		{
			if (C_Sword <= 180)
			{
				Shield_Y++;
				L_Sword++;
				LT_Sword++;
				C_Sword++;
				R_Sword--;
				RT_Sword++;
			}

			if (C_Sword == 250)
			{
				Shield_Y++;
				L_Sword++;
				LT_Sword++;
				C_Sword++;
				R_Sword--;
				RT_Sword++;
			}
			if (Shield_Y >= 250)
			{
				if (White_Alpha >= 0)
				{
					Shield_Y = 250;
					White_Alpha += 5;
				}
			}
			Tran_Ani = GetTickCount();
		}

		if (White_Alpha >= 255)
		{
			Shield_Y = 272 - 120;
			L_Sword = 482 - 100;
			LT_Sword = 275 - 100;
			C_Sword = 272 - 200;
			R_Sword = 742 + 100;
			RT_Sword = 220 - 100;
			White_Alpha = 0;
			Incounter = 0;

			BGStop();
			battle.BGM_battle = true;
			map.BGM_map = false;
			
			
			battle_E = true;
			BGPlay(sound.BGM_Battle);
			g_Mng.n_Chap = BATTLE;
		
		}
	}
}

void Transition::Draw()
{
	
	if (Incounter >= 1)
	{
		White_Screen.SetColor(255, 255, 255, White_Alpha);
		White_Screen.Draw(0, 0, 0, 0, 1280, 768, 0, 0);

		Shield.Render(552, Shield_Y, 0, 1, 1);

		Sword.Render(L_Sword, LT_Sword, -0.8, 1, 1);//482, 275//ÁÂ»ó
		Sword.Render(R_Sword, RT_Sword, 0.8, 1, 1);//742, 220//¿ì»ó
		Sword.Render(602, C_Sword, 0, 1, 1);//602, 272//Áß¾Ó
	}
	
}

