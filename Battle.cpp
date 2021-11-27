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

	sprintf_s(FileName, "./resource/Img/Battlebacks/001-Grassland01.jpg");//���
	battleBG.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/character/hero/hero_face.png");//����� ��
	hero_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/thief/thief_face.png");//���� ��
	thief_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/priest/priest_face.png");//������ ��
	priest_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/character/wizard/wizard_face.png");//������ ��
	wizard_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/HPMP_Back.png");//ü�� ���� ������ ���
	hpmpframe_back.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/HPMP.png");//ü�� ���� ������
	hpmpframe.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/HP_bar.png");//ü�¹�
	HP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/MP_bar.png");//���¹�
	MP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/FF_select.png");//�հ��� Ŀ��UI��
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
	dv_font.NumString(text, 560, 535);//��� ü��
	sprintf(text, "%d / %d", status[HERO].mp[NOW], status[HERO].mp[MAX]);
	dv_font.NumString(text, 560, 590);//��� ����
	sprintf(text, "%d / %d", status[THIEF].hp[NOW], status[THIEF].hp[MAX]);
	dv_font.NumString(text, 1000, 535);//���� ü��
	sprintf(text, "%d / %d", status[THIEF].mp[NOW], status[THIEF].mp[MAX]);
	dv_font.NumString(text, 1000, 590);//���� ����
	sprintf(text, "%d / %d", status[PRIEST].hp[NOW], status[PRIEST].hp[MAX]);
	dv_font.NumString(text, 560, 645);//������ ü��
	sprintf(text, "%d / %d", status[PRIEST].mp[NOW], status[PRIEST].mp[MAX]);
	dv_font.NumString(text, 560, 700);//������ ����
	sprintf(text, "%d / %d", status[WIZARD].hp[NOW], status[WIZARD].hp[MAX]);
	dv_font.NumString(text, 1000, 645);//������ ü��
	sprintf(text, "%d / %d", status[WIZARD].mp[NOW], status[WIZARD].mp[MAX]);
	dv_font.NumString(text, 1000, 700);//������ ����

	hpmpframe_back.Render(0, 535, 0, 1, 1);

	bar = 185 * status[HERO].hp[NOW] / status[HERO].hp[MAX];
	HP_bar.Render(525, 560, 0, bar, 1);//��� ü�¹�
	bar = 185 * status[HERO].mp[NOW] / status[HERO].mp[MAX];
	MP_bar.Render(525, 617, 0, bar, 1);//��� ���¹�
	bar = 185 * status[THIEF].hp[NOW] / status[THIEF].hp[MAX];
	HP_bar.Render(965, 560, 0, bar, 1);//���� ü�¹�
	bar = 185 * status[THIEF].mp[NOW] / status[THIEF].mp[MAX];
	MP_bar.Render(965, 617, 0, bar, 1);//���� ���¹�
	bar = 185 * status[PRIEST].hp[NOW] / status[PRIEST].hp[MAX];
	HP_bar.Render(525, 674, 0, bar, 1);//������ ü�¹�
	bar = 185 * status[PRIEST].mp[NOW] / status[PRIEST].mp[MAX];
	MP_bar.Render(525, 730, 0, bar, 1);//������ ���¹�
	bar = 185 * status[WIZARD].hp[NOW] / status[WIZARD].hp[MAX];
	HP_bar.Render(965, 674, 0, bar, 1);//������ ü�¹�
	bar = 185 * status[WIZARD].mp[NOW] / status[WIZARD].mp[MAX];
	MP_bar.Render(965, 730, 0, bar, 1);//������ ���¹�

	hpmpframe.Render(0, 535, 0, 1, 1);

	dv_font.DrawString("��    ��", 150, 560);
	dv_font.DrawString("��    ų", 150, 610);
	dv_font.DrawString("�� �� ��", 150, 660);
	dv_font.DrawString("��    ��", 150, 710);

	for (int i = 0; i < 3; i++)
		monster[i].Draw(200 + i * 350);//roc

	if (d.skillSelect == true)
	{
		subwindowUI.Render(320, 528, 0, 1, 1);
		dv_font.DrawString("���� ������", 400, 560);
		dv_font.DrawString("���̾", 400, 610);
		dv_font.DrawString("���ڵ�", 400, 660);
		dv_font.DrawString("��", 400, 710);

		dv_font.DrawString("MP 10", 600, 560);
		dv_font.DrawString("MP 10", 600, 610);
		dv_font.DrawString("MP 20", 600, 660);
		dv_font.DrawString("MP 10", 600, 710);
	}
	if (d.itemSelect == true)
	{
		subwindowUI.Render(320, 528, 0, 1, 1);
		dv_font.DrawString("HP ȸ����", 400, 560);
		dv_font.DrawString("MP ȸ����", 400, 610);
		dv_font.DrawString("��Ȱ��", 400, 660);
		dv_font.DrawString("��ź", 400, 710);

		sprintf(text, "%d ��", inventory.consumableItem[HP_POTION]);
		dv_font.DrawString(text, 600, 560);
		sprintf(text, "%d ��", inventory.consumableItem[MP_POTION]);
		dv_font.DrawString(text, 600, 610);
		sprintf(text, "%d ��", inventory.consumableItem[RERIVE_POTION]);
		dv_font.DrawString(text, 600, 660);
		sprintf(text, "%d ��", inventory.consumableItem[BOOM]);
		dv_font.DrawString(text, 600, 710);
	}

	if (d.actionSelect == true)//�⺻ ���� ����
	{
		cursor.Render(actionLocation[d.action][WIDTH], actionLocation[d.action][HEIGHT], 0, 1, 1);
	}
	if (d.skillSelect == true)//��ų ����
	{
		cursor.Render(skillLocation[d.skill][WIDTH], skillLocation[d.skill][HEIGHT], 0, 1, 1);
	}
	if (d.itemSelect == true)//������ ������
	{
		cursor.Render(itemLocation[d.item][WIDTH], itemLocation[d.item][HEIGHT], 0, 1, 1);
	}
	if (d.friendlyTargetSelect == true)//ȸ���� ���� �Ʊ����� ������
	{
		cursor.Render(friendlyTargetLocation[d.friendlyTarget][WIDTH], friendlyTargetLocation[d.friendlyTarget][HEIGHT], 0, 1, 1);
	}
	if (d.enemyTargetSelect == true)//���ݿ� ���� ������
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

			else if (d.action == RUN)//����
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

	// ����׿� �ڵ�
	TCHAR text[100];
	sprintf(text, "���� HP(0:H, 4:T, 8:P, 12:W) %d : %d", targetStat->skillSet[0], targetStat->hp[NOW]);
	MessageBox(NULL, text, "Ȯ��â", 0);

	if (targetStat->hp[NOW] <= 0)
	{
		// ��� �� �ʿ��� ���� �߰�
		targetStat->live = false;
		// ����׿� �ڵ�
		MessageBox(NULL, "ĳ���� ���", "Ȯ��â", 0);
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
		MessageBox(NULL, "�� �� ���� �ε����� ��ų�� ����", "����", 0);
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
	//������ �����ؼ� ��Ʋ����� �� Ȱ��ȭ
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
	sprintf(text, "%d���� %d ������, ���� ü�� : %d", d.enemyTarget, damage, m->NOW_HP);
	MessageBox(NULL, text, "Ȯ��â", 0);

	if (m->NOW_HP <= 0)
	{
		// ��� �� �ʿ��� ���� �߰�
		m->Live = false;
	}

}
