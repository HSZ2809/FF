#include "Include.h"



Battle battle;

//enum MapID
//{
//	ground = 0, forest, rock
//};


Battle::Battle()
{
	d.actionSelect = true;
	d.skillSelect = false;
	d.itemSelect = false;
	d.friendlyTargetSelect = false;
	d.enemyTargetSelect = false;
	BGM_battle = true;

	d.action = 0;
	d.skill = 0;
	d.item = 0;
	d.enemyTarget = 0;
	d.friendlyTarget = 0;

	turn = true;
	crewTurn = HERO;
	enemyTurn = FIRST;

	for (int i = 0; i < 4; i++)
	{
		actionLocation[i][WIDTH] = 50;
		actionLocation[i][HEIGHT] = 550 + 50 * i;
	}

	for (int i = 0; i < 4; i++)
	{
		skillLocation[i][WIDTH] = 330;
		skillLocation[i][HEIGHT] = 550 + 50 * i;
	}

	for (int i = 0; i < 4; i++)
	{
		itemLocation[i][WIDTH] = 330;
		itemLocation[i][HEIGHT] = 550 + 50 * i;
	}

	for (int i = 0, k = 0; i < 4; i++)
	{
		friendlyTargetLocation[i][WIDTH] = (i % 2 == 0) ? 340 : 780;
		friendlyTargetLocation[i][HEIGHT] = (k == 0) ? 570 : 670;

		if (i == 1)
			k = 1;
	}

	for (int i = 0; i < 3; i++)
	{
		enemyTargetLocation[i][WIDTH] = 100 + 426 * i;
		enemyTargetLocation[i][HEIGHT] = 400;
	}
}
Battle::~Battle(){}


void Battle::Init()
{
	
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/ui/subcommandui.png");//WindowUI
	subwindowUI.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/commandui.png");//WindowUI
	windowUI.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Battlebacks/001-Grassland01.jpg");//배경
	battleBG.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/character/hero/hero_face.png");//히어로 얼굴
	hero_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/thief/thief_face.png");//도적 얼굴
	thief_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/priest/priest_face.png");//성직자 얼굴
	priest_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/wizard/wizard_face.png");//마법사 얼굴
	wizard_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/HPMP_Back.png");//체력 마력 프레임 배경
	hpmpframe_back.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/HPMP.png");//체력 마력 프레임
	hpmpframe.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/HP_bar.png");//체력바
	HP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/MP_bar.png");//마력바
	MP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/FF_select.png");//손가락 커서UI용
	cursor.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i < 3; i++)
		monster[i].Init();
}

void Battle::Update(double frame)
{
	if (BGM_battle == true)
	{
		BGPlay(sound.BGM_Battle);
	}
	BGM_battle = false;

	for (int i = 0; i < 3; i++)
		monster[i].Update(i);

	if (turn == ENEMY)
		enemyAction();
}

void Battle::Reset(decision* d)
{
	
	d->actionSelect = true;
	d->skillSelect = false;
	d->itemSelect = false;
	d->friendlyTargetSelect = false;
	d->enemyTargetSelect = false;

	d->action = 0;
	d->skill = 0;
	d->item = 0;
	d->enemyTarget = 0;
	d->friendlyTarget = 0;
}

void Battle::Draw()
{
	TCHAR text[10];
	float bar;

	battleBG.Render(bgX, bgY, 0, 2.4, 2.4);
	windowUI.Render(uiX = 0, uiY = 528, 0, 1, 1);

	hero_face.Render(380, 540, 0, 0.8, 0.8);
	thief_face.Render(820, 540, 0, 0.8, 0.8); 
	priest_face.Render(380, 650, 0, 0.8, 0.8);
	wizard_face.Render(820, 650, 0, 0.8, 0.8);

	sprintf(text, "%d / %d", status[HERO].hp[NOW], status[HERO].hp[MAX]);
	dv_font.NumString(text, 560, 535);//용사 체력
	sprintf(text, "%d / %d", status[HERO].mp[NOW], status[HERO].mp[MAX]);
	dv_font.NumString(text, 560, 590);//용사 마력
	sprintf(text, "%d / %d", status[THIEF].hp[NOW], status[THIEF].hp[MAX]);
	dv_font.NumString(text, 1000, 535);//도적 체력
	sprintf(text, "%d / %d", status[THIEF].mp[NOW], status[THIEF].mp[MAX]);
	dv_font.NumString(text, 1000, 590);//도적 마력
	sprintf(text, "%d / %d", status[PRIEST].hp[NOW], status[PRIEST].hp[MAX]);
	dv_font.NumString(text, 560, 645);//성직자 체력
	sprintf(text, "%d / %d", status[PRIEST].mp[NOW], status[PRIEST].mp[MAX]);
	dv_font.NumString(text, 560, 700);//성직자 마력
	sprintf(text, "%d / %d", status[WIZARD].hp[NOW], status[WIZARD].hp[MAX]);
	dv_font.NumString(text, 1000, 645);//마법사 체력
	sprintf(text, "%d / %d", status[WIZARD].mp[NOW], status[WIZARD].mp[MAX]);
	dv_font.NumString(text, 1000, 700);//마법사 마력

	hpmpframe_back.Render(0, 535, 0, 1, 1);

	bar = 185 * status[HERO].hp[NOW] / status[HERO].hp[MAX];
	HP_bar.Render(525, 560, 0, bar, 1);//용사 체력바
	bar = 185 * status[HERO].mp[NOW] / status[HERO].mp[MAX];
	MP_bar.Render(525, 617, 0, bar, 1);//용사 마력바
	bar = 185 * status[THIEF].hp[NOW] / status[THIEF].hp[MAX];
	HP_bar.Render(965, 560, 0, bar, 1);//도적 체력바
	bar = 185 * status[THIEF].mp[NOW] / status[THIEF].mp[MAX];
	MP_bar.Render(965, 617, 0, bar, 1);//도적 마력바
	bar = 185 * status[PRIEST].hp[NOW] / status[PRIEST].hp[MAX];
	HP_bar.Render(525, 674, 0, bar, 1);//성직자 체력바
	bar = 185 * status[PRIEST].mp[NOW] / status[PRIEST].mp[MAX];
	MP_bar.Render(525, 730, 0, bar, 1);//성직자 마력바
	bar = 185 * status[WIZARD].hp[NOW] / status[WIZARD].hp[MAX];
	HP_bar.Render(965, 674, 0, bar, 1);//마법사 체력바
	bar = 185 * status[WIZARD].mp[NOW] / status[WIZARD].mp[MAX];
	MP_bar.Render(965, 730, 0, bar, 1);//마법사 마력바

	hpmpframe.Render(0, 535, 0, 1, 1);

	dv_font.DrawString("공    격", 150, 560);
	dv_font.DrawString("스    킬", 150, 610);
	dv_font.DrawString("아 이 템", 150, 660);
	dv_font.DrawString("도    망", 150, 710);

	for (int i = 0; i < 3; i++)
		monster[i].Draw(200 + i * 350);//roc

	if (d.skillSelect == true)
	{
		subwindowUI.Render(320, 528, 0, 1, 1);
		dv_font.DrawString("더블 슬래쉬", 400, 560);
		dv_font.DrawString("파이어볼", 400, 610);
		dv_font.DrawString("블리자드", 400, 660);
		dv_font.DrawString("힐", 400, 710);

		dv_font.DrawString("MP 10", 600, 560);
		dv_font.DrawString("MP 10", 600, 610);
		dv_font.DrawString("MP 20", 600, 660);
		dv_font.DrawString("MP 10", 600, 710);
	}
	if (d.itemSelect == true)
	{
		subwindowUI.Render(320, 528, 0, 1, 1);
		dv_font.DrawString("HP 회복약", 400, 560);
		dv_font.DrawString("MP 회복약", 400, 610);
		dv_font.DrawString("부활초", 400, 660);
		dv_font.DrawString("폭탄", 400, 710);

		sprintf(text, "%d 개", inventory.consumableItem[HP_POTION]);
		dv_font.DrawString(text, 600, 560);
		sprintf(text, "%d 개", inventory.consumableItem[MP_POTION]);
		dv_font.DrawString(text, 600, 610);
		sprintf(text, "%d 개", inventory.consumableItem[RERIVE_POTION]);
		dv_font.DrawString(text, 600, 660);
		sprintf(text, "%d 개", inventory.consumableItem[BOOM]);
		dv_font.DrawString(text, 600, 710);
	}

	if (d.actionSelect == true)//기본 엑션 선택
	{
		cursor.Render(actionLocation[d.action][WIDTH], actionLocation[d.action][HEIGHT], 0, 1, 1);
	}
	if (d.skillSelect == true)//스킬 선택
	{
		cursor.Render(skillLocation[d.skill][WIDTH], skillLocation[d.skill][HEIGHT], 0, 1, 1);
	}
	if (d.itemSelect == true)//아이템 선택지
	{
		cursor.Render(itemLocation[d.item][WIDTH], itemLocation[d.item][HEIGHT], 0, 1, 1);
	}
	if (d.friendlyTargetSelect == true)//회복및 버프 아군선택 선택지
	{
		cursor.Render(friendlyTargetLocation[d.friendlyTarget][WIDTH], friendlyTargetLocation[d.friendlyTarget][HEIGHT], 0, 1, 1);
	}
	if (d.enemyTargetSelect == true)//공격용 몬스터 선택지
	{
		cursor.Render(enemyTargetLocation[d.enemyTarget][WIDTH], enemyTargetLocation[d.enemyTarget][HEIGHT], 0, 1, 1);
	}
}




void Battle::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (LOWORD(msg->wParam))
		{
		case VK_LEFT:
			if (GetTickCount64() - KeyTime3 > 200)
			{
				if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.friendlyTarget <= 0)
						d.friendlyTarget = 3;
					else
						d.friendlyTarget--;
				}

				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.enemyTarget <= 0)
						d.enemyTarget = 2;
					else
						d.enemyTarget--;
				}

				KeyTime3 = GetTickCount64();
			}
			break;

		case VK_RIGHT:
			if (GetTickCount64() - KeyTime3 > 200)
			{
				if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.friendlyTarget >= 3)
						d.friendlyTarget = 0;
					else
						d.friendlyTarget++;
				}

				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.enemyTarget >= 2)
						d.enemyTarget = 0;
					else
						d.enemyTarget++;
				}
				KeyTime3 = GetTickCount64();
			}
			break;

		case VK_UP:
			if (GetTickCount64() - KeyTime3 > 200)
			{
				if (d.actionSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.action <= 0)
						d.action = 3;
					else
						d.action--;
				}
				if (d.skillSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.skill <= 0)
						d.skill = 3;
					else
						d.skill--;
				}
				if (d.itemSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.item <= 0)
						d.item = 3;
					else
						d.item--;
				}
				if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.friendlyTarget <= 0)
						d.friendlyTarget = 3;
					else
						d.friendlyTarget--;
				}
				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.enemyTarget <= 0)
						d.enemyTarget = 2;
					else
						d.enemyTarget--;
				}
				KeyTime3 = GetTickCount64();
			}
			break;

		case VK_DOWN:
			if (GetTickCount64() - KeyTime3 > 200)
			{
				if (d.actionSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.action >= 3)
						d.action = 0;
					else
						d.action++;
				}
				if (d.skillSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.skill >= 3)
						d.skill = 0;
					else
						d.skill++;
				}
				if (d.itemSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.item >= 3)
						d.item = 0;
					else
						d.item++;
				}
				if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.friendlyTarget >= 3)
						d.friendlyTarget = 0;
					else
						d.friendlyTarget++;
				}
				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Move);
					if (d.enemyTarget >= 2)
						d.enemyTarget = 0;
					else
						d.enemyTarget++;
				}
				KeyTime3 = GetTickCount64();
			}
			break;
		}
	}

	if (KeyDown('Z'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{
			d.actionSelect = false;

			if (d.action == ATTACK)
			{
				EffectPlay(sound.Select);
				if (d.enemyTargetSelect == true)
				{
					Attack(status[crewTurn], &monster[d.enemyTarget]);
					CrewTurnCheck();
				}
				else
				{
					EffectPlay(sound.Select);
					d.enemyTargetSelect = true;
				}
			}

			else if (d.action == SKILL)
			{
				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Select);
					if (Skill(status[crewTurn], &monster[d.enemyTarget]))
						CrewTurnCheck();
					else
						battle.Reset(&d);
				}
				else if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Select);
					if (Hill(status[crewTurn], &status[d.friendlyTarget]))
						CrewTurnCheck();
					else
						battle.Reset(&d);
				}
				else if (d.skillSelect == true)
				{
					EffectPlay(sound.Select);
					d.skillSelect = false;

					if (d.skill < 3)
						d.enemyTargetSelect = true;
					else
						d.friendlyTargetSelect = true;
				}
				else
				{
					EffectPlay(sound.Select);
					d.skillSelect = true;
				}
			}

			else if (d.action == ITEM)
			{
				if (d.enemyTargetSelect == true)
				{
					EffectPlay(sound.Select);
					if (UseItem(d.item, &monster[d.enemyTarget]))
						CrewTurnCheck();
					else
						battle.Reset(&d);
				}
				else if (d.friendlyTargetSelect == true)
				{
					EffectPlay(sound.Select);
					if (UseItem(d.item, &status[d.friendlyTarget]))
						CrewTurnCheck();
					else
						battle.Reset(&d);
				}
				else if (d.itemSelect == true)
				{
					EffectPlay(sound.Select);
					d.itemSelect = false;

					if (d.item == BOOM)
						d.enemyTargetSelect = true;
					else
						d.friendlyTargetSelect = true;
				}
				else
				{
					EffectPlay(sound.Select);
					d.itemSelect = true;
				}
			}

			else if (d.action == RUN)//도망
			{
				EffectPlay(sound.Run);
				Reset(&d);
				Run();
			}

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('X'))
	{
		if (GetTickCount64() - KeyTime > 300)
		{
			EffectPlay(sound.Cancel);
			Reset(&d);

			KeyTime = GetTickCount64();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////

void Battle::enemyAction()
{
	for (int i = 0; i < 3; i++)
	{
		int target = rand() % 4;

		if (monster[i].Live == false)
			i++;

		Attack(monster[i], &status[target]);
	}

	turn = PLAYER;
}

///////////////////////////////////////////////////////////////////////////////////////

void Battle::Attack(Status& userStat, Monster* m)
{
	int damage = 0;

	damage = ATTACKFACTOR * (userStat.stat[STR] + userStat.addStat[STR]);

	Hit(damage, m);
}

void Battle::Hit(int damage, Status* targetStat)
{
	if ((targetStat->hp[NOW] - damage) > 0)
		targetStat->hp[NOW] -= damage;
	else
		targetStat->hp[NOW] = 0;

	// 디버그용 코드
	TCHAR text[100];
	sprintf(text, "현재 HP(0:H, 4:T, 8:P, 12:W) %d : %d", targetStat->skillSet[0], targetStat->hp[NOW]);
	MessageBox(NULL, text, "확인창", 0);

	if (targetStat->hp[NOW] <= 0)
	{
		// 사망 시 필요한 동작 추가
		targetStat->live = false;
		// 디버그용 코드
		MessageBox(NULL, "캐릭터 사망", "확인창", 0);
	}
}

bool Battle::Hill(Status& userStat, Status* targetStat)
{
	if (userStat.mp[NOW] < 10)
		return false;

	int hill = 0;

	hill = HILLFACTOR * (userStat.stat[FAITH] + userStat.addStat[FAITH]);

	userStat.mp[NOW] -= 10;
	if (targetStat->hp[MAX] - targetStat->hp[NOW] < hill)
		targetStat->hp[NOW] = targetStat->hp[MAX];
	else
		targetStat->hp[NOW] += hill;

	return true;
}

bool Battle::Skill(Status& userStat, Monster* m)
{
	int damage = 0;

	if (d.skill == DOUBLE_SLASH)
	{
		if (userStat.mp[NOW] < 10)
			return false;
		userStat.mp[NOW] -= 10;
		damage = DOUBLE_SLASH_FACTOR * (userStat.stat[STR] + userStat.addStat[STR]);
		Hit(damage / 2, m);
		Hit(damage, m);
	}
	else if (d.skill == FIREBALL)
	{
		if (userStat.mp[NOW] < 10)
			return false;
		userStat.mp[NOW] -= 10;
		damage = FIREBALL_FACTOR * (userStat.stat[INTELLI] + userStat.addStat[INTELLI]);
		Hit(damage, m);
	}
	else if (d.skill == BILZZARD)
	{
		if (userStat.mp[NOW] < 20)
			return false;
		userStat.mp[NOW] -= 20;
		damage = BILZZARD_FACTOR * (userStat.stat[INTELLI] + userStat.addStat[INTELLI]);
		Hit(damage, m);
	}
	else
	{
		MessageBox(NULL, "알 수 없는 인덱스의 스킬이 사용됨", "에러", 0);
		return false;
	}

	return true;
}

bool Battle::UseItem(int itemIndex, Status* targetStat)
{
	bool check;

	check = inventory.ConsumeItem(itemIndex, targetStat);

	return check;
}

bool Battle::UseItem(int itemIndex, Monster* monster)
{
	bool check;

	check = inventory.ConsumeItem(itemIndex, monster);

	return check;
}

void Battle::Run()
{
	//도망에 성공해서 배틀종료및 맵 활성화
	BGM_battle = false;
	BGStop();
	map.BGM_map = true;
	Gmanager.m_GameMap = true;
	g_Mng.n_Chap = GAME;
}

void Battle::CrewTurnCheck()
{
	crewTurn++;
	if (crewTurn >= 4)
	{
		crewTurn = 0;
		turn = ENEMY;
	}
	Reset(&d);
}

void Battle::Attack(Monster& m, Status* charStat)
{
	int damage = 0;

	damage = ATTACKFACTOR * (m.STR);

	Hit(damage, charStat);
}

void Battle::Hit(int damage, Monster* m)
{
	if ((m->NOW_HP - damage) > 0)
		m->NOW_HP -= damage;
	else
		m->NOW_HP = 0;

	TCHAR text[100];
	sprintf(text, "%d에게 %d 데미지, 현재 체력 : %d", d.enemyTarget, damage, m->NOW_HP);
	MessageBox(NULL, text, "확인창", 0);

	if (m->NOW_HP <= 0)
	{
		// 사망 시 필요한 동작 추가
		m->Live = false;
	}

}
