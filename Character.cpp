#include "Include.h"



Character character;


Character::Character()
{
	for (int i = HERO; i <= WIZARD; i++)
	{
		location[i].m_X = 600;
		location[i].m_Y = 300;
	}

	Move_key = 1;
}

Character::~Character()
{
}

void Character::Init()
{
	char FileName[256];

#pragma region ���
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/hero/hero_%04d.png", sel_vert + 3);
		HeroSprite[UP][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/hero/hero_%04d.png", sel_vert + 6);
		HeroSprite[RIGHT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/hero/hero_%04d.png", sel_vert + 9);
		HeroSprite[LEFT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/hero/hero_%04d.png", sel_vert + 12);
		HeroSprite[DOWN][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
#pragma endregion

#pragma region ����
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/thief/thief_%04d.png", sel_vert + 3);
		ThiefSprite[UP][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/thief/thief_%04d.png", sel_vert + 6);
		ThiefSprite[RIGHT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/thief/thief_%04d.png", sel_vert + 9);
		ThiefSprite[LEFT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/thief/thief_%04d.png", sel_vert + 12);
		ThiefSprite[DOWN][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/character/thief/thief_%04d.png", 0);
	ThiefDead.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
#pragma endregion

#pragma region ������
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/priest/priest_%04d.png", sel_vert + 3);
		PriestSprite[UP][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/priest/priest_%04d.png", sel_vert + 6);
		PriestSprite[RIGHT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/priest/priest_%04d.png", sel_vert + 9);
		PriestSprite[LEFT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/priest/priest_%04d.png", sel_vert + 12);
		PriestSprite[DOWN][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/character/priest/priest_%04d.png", 0);
	PriestDead.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
#pragma endregion

#pragma region ������
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/wizard/wizard_%04d.png", sel_vert + 3);
		WizardSprite[UP][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/wizard/wizard_%04d.png", sel_vert + 6);
		WizardSprite[RIGHT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/wizard/wizard_%04d.png", sel_vert + 9);
		WizardSprite[LEFT][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int sel_vert = 0; sel_vert < 3; sel_vert++)
	{
		sprintf_s(FileName, "./resource/Img/character/wizard/wizard_%04d.png", sel_vert + 12);
		WizardSprite[DOWN][sel_vert].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/character/wizard/wizard_%04d.png", 0);
	WizardDead.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
#pragma endregion
}

void Character::Update()
{
	Chasing();

	if (GetTickCount() - AniTime1 > 1000)
	{
		m_TgCount1++;
		if (m_TgCount1 > 1) m_TgCount1 = 0;
		AniTime1 = GetTickCount();

	}


	if (GetTickCount() - AniTime2 > 100)
	{
		character.m_TgCount2++;
		if (character.m_TgCount2 > 3) { character.m_TgCount2 = 0; character.m_Life = false; }


		AniTime2 = GetTickCount();

	}

}

void Character::Draw()
{
	switch (Move_key)
	{
	case MoveDown:
	{
		WizardSprite[DOWN][m_TgCount1].Render(location[WIZARD].m_X, location[WIZARD].m_Y, 0, 1, 1);
		PriestSprite[DOWN][m_TgCount1].Render(location[PRIEST].m_X, location[PRIEST].m_Y, 0, 1, 1);
		ThiefSprite[DOWN][m_TgCount1].Render(location[THIEF].m_X, location[THIEF].m_Y, 0, 1, 1);
		HeroSprite[DOWN][m_TgCount1].Render(location[HERO].m_X, location[HERO].m_Y, 0, 1, 1);
		break;
	}
	case MoveUp:
	{
		WizardSprite[UP][m_TgCount1].Render(location[WIZARD].m_X, location[WIZARD].m_Y, 0, 1, 1);
		PriestSprite[UP][m_TgCount1].Render(location[PRIEST].m_X, location[PRIEST].m_Y, 0, 1, 1);
		ThiefSprite[UP][m_TgCount1].Render(location[THIEF].m_X, location[THIEF].m_Y, 0, 1, 1);
		HeroSprite[UP][m_TgCount1].Render(location[HERO].m_X, location[HERO].m_Y, 0, 1, 1);
		break;
	}
	case MoveLeft:
	{
		WizardSprite[LEFT][m_TgCount1].Render(location[WIZARD].m_X, location[WIZARD].m_Y, 0, 1, 1);
		PriestSprite[LEFT][m_TgCount1].Render(location[PRIEST].m_X, location[PRIEST].m_Y, 0, 1, 1);
		ThiefSprite[LEFT][m_TgCount1].Render(location[THIEF].m_X, location[THIEF].m_Y, 0, 1, 1);
		HeroSprite[LEFT][m_TgCount1].Render(location[HERO].m_X, location[HERO].m_Y, 0, 1, 1);
		break;
	}
	case MoveRight:
	{
		WizardSprite[RIGHT][m_TgCount1].Render(location[WIZARD].m_X, location[WIZARD].m_Y, 0, 1, 1);
		PriestSprite[RIGHT][m_TgCount1].Render(location[PRIEST].m_X, location[PRIEST].m_Y, 0, 1, 1);
		ThiefSprite[RIGHT][m_TgCount1].Render(location[THIEF].m_X, location[THIEF].m_Y, 0, 1, 1);
		HeroSprite[RIGHT][m_TgCount1].Render(location[HERO].m_X, location[HERO].m_Y, 0, 1, 1);
		break;
	}
	}
}


void Character::Reset()
{
	

}
/*

	�⺻ �浿ó��

	= �簢�� �⵿ ���� ó��
	�÷��̾���� �浹 ���� ��ǥ�� (ML, MT) ~ (MR, MB), ź�� �浹 ���� ��ǥ�� (BL, BT) ~ (BR, BB)��� �غ���.
	(ML, MT), (BL, BT)�� ������ �簢���� ���� �� ��ǥ�̰� (MR. MB), (BR, BB)�� �簢���� ������ �Ʒ� ��ǥ�̴�.
	�� ���, �÷��̾�⿡ ź�� �浹 ������ ������ ����.
	* ML < BR && BL < MR && MT < BB && BT < MB

	= ���� �̿��� �浹 ���� ó��
	���� �̿��� �浹 ���� ó���� ������ ����.
	�÷��̾���� �߽���ǥ�� (MX, MY), ź�� �߽���ǥ�� (BX, BY)��� �ϰ�, �÷��̾���� �浹 ���� �ݰ��� MR,
	ź�� �浹 ���� �ݰ��� BR�̶�� ����. �̶� �÷��̾��� ź�� �浹 ������ �Ʒ��� ����.
	* (MX-BX)*(MX-BX) + (MY-BY)*(MY-BY) < (MR+BR)*(MR+BR)

*/
void Character::Chasing()
{
	double dis[3];

	dis[0] = sqrt(((location[HERO].m_X - location[THIEF].m_X) * (location[HERO].m_X - location[THIEF].m_X)) + pow((location[HERO].m_Y - location[THIEF].m_Y), 2));
	dis[1] = sqrt(((location[THIEF].m_X - location[PRIEST].m_X) * (location[THIEF].m_X - location[PRIEST].m_X)) + pow((location[THIEF].m_Y - location[PRIEST].m_Y), 2));
	dis[2] = sqrt(((location[PRIEST].m_X - location[WIZARD].m_X) * (location[PRIEST].m_X - location[WIZARD].m_X)) + pow((location[PRIEST].m_Y - location[WIZARD].m_Y), 2));

	if (dis[0] > 60)
	{
		if (location[HERO].m_X < location[THIEF].m_X && location[THIEF].m_X - location[HERO].m_X < 30)
			location[THIEF].m_X -= 1;
		else if (location[HERO].m_X < location[THIEF].m_X)
			location[THIEF].m_X -= 8;
		else if (location[HERO].m_X > location[THIEF].m_X && location[HERO].m_X - location[THIEF].m_X < 30)
			location[THIEF].m_X += 1;
		else if (location[HERO].m_X > location[THIEF].m_X)
			location[THIEF].m_X += 8;

		if (location[HERO].m_Y < location[THIEF].m_Y && location[THIEF].m_Y - location[HERO].m_Y < 30)
			location[THIEF].m_Y -= 1;
		else if (location[HERO].m_Y < location[THIEF].m_Y)
			location[THIEF].m_Y -= 8;
		else if (location[HERO].m_Y > location[THIEF].m_Y && location[HERO].m_Y - location[THIEF].m_Y < 30)
			location[THIEF].m_Y -= 1;
		else if (location[HERO].m_Y > location[THIEF].m_Y)
			location[THIEF].m_Y += 8;
	}
	else if (dis[0] > 40)
	{
		if (location[HERO].m_X < location[THIEF].m_X && location[THIEF].m_X - location[HERO].m_X < 3)
			location[THIEF].m_X -= 1;
		else if (location[HERO].m_X < location[THIEF].m_X)
			location[THIEF].m_X -= 4;
		else if (location[HERO].m_X > location[THIEF].m_X && location[HERO].m_X - location[THIEF].m_X < 3)
			location[THIEF].m_X += 1;
		else if (location[HERO].m_X > location[THIEF].m_X)
			location[THIEF].m_X += 4;

		if (location[HERO].m_Y < location[THIEF].m_Y && location[THIEF].m_Y - location[HERO].m_Y < 3)
			location[THIEF].m_Y -= 1;
		else if (location[HERO].m_Y < location[THIEF].m_Y)
			location[THIEF].m_Y -= 4;
		else if (location[HERO].m_Y > location[THIEF].m_Y && location[HERO].m_Y - location[THIEF].m_Y < 3)
			location[THIEF].m_Y -= 1;
		else if (location[HERO].m_Y > location[THIEF].m_Y)
			location[THIEF].m_Y += 4;
	}
	else if (dis[0] > 30)
	{
		if (location[HERO].m_X < location[THIEF].m_X)
			location[THIEF].m_X -= 1;
		else if (location[HERO].m_X > location[THIEF].m_X)
			location[THIEF].m_X += 1;

		if (location[HERO].m_Y < location[THIEF].m_Y)
			location[THIEF].m_Y -= 1;
		else if (location[HERO].m_Y > location[THIEF].m_Y)
			location[THIEF].m_Y += 1;
	}

	if (dis[1] > 60)
	{
		if (location[THIEF].m_X < location[PRIEST].m_X && location[PRIEST].m_X - location[THIEF].m_X < 30)
			location[PRIEST].m_X -= 1;
		else if (location[THIEF].m_X < location[PRIEST].m_X)
			location[PRIEST].m_X -= 8;
		else if (location[THIEF].m_X > location[PRIEST].m_X && location[THIEF].m_X - location[PRIEST].m_X < 30)
			location[PRIEST].m_X += 1;
		else if (location[THIEF].m_X > location[PRIEST].m_X)
			location[PRIEST].m_X += 8;

		if (location[THIEF].m_Y < location[PRIEST].m_Y && location[PRIEST].m_Y - location[THIEF].m_Y < 30)
			location[PRIEST].m_Y -= 1;
		else if (location[THIEF].m_Y < location[PRIEST].m_Y)
			location[PRIEST].m_Y -= 8;
		else if (location[THIEF].m_Y > location[PRIEST].m_Y && location[THIEF].m_Y - location[PRIEST].m_Y < 30)
			location[PRIEST].m_Y -= 1;
		else if (location[THIEF].m_Y > location[PRIEST].m_Y)
			location[PRIEST].m_Y += 8;
	}
	else if (dis[1] > 40)
	{
		if (location[THIEF].m_X < location[PRIEST].m_X && location[PRIEST].m_X - location[THIEF].m_X < 3)
			location[PRIEST].m_X -= 1;
		else if (location[THIEF].m_X < location[PRIEST].m_X)
			location[PRIEST].m_X -= 4;
		else if (location[THIEF].m_X > location[PRIEST].m_X && location[THIEF].m_X - location[PRIEST].m_X < 3)
			location[PRIEST].m_X += 1;
		else if (location[THIEF].m_X > location[PRIEST].m_X)
			location[PRIEST].m_X += 4;

		if (location[THIEF].m_Y < location[PRIEST].m_Y && location[THIEF].m_Y - location[PRIEST].m_Y < 3)
			location[PRIEST].m_Y -= 1;
		else if (location[THIEF].m_Y < location[PRIEST].m_Y)
			location[PRIEST].m_Y -= 4;
		else if (location[THIEF].m_Y > location[PRIEST].m_Y && location[THIEF].m_Y - location[PRIEST].m_Y < 3)
			location[PRIEST].m_Y -= 1;
		else if (location[THIEF].m_Y > location[PRIEST].m_Y)
			location[PRIEST].m_Y += 4;
	}
	else if (dis[1] > 30)
	{
		if (location[THIEF].m_X < location[PRIEST].m_X)
			location[PRIEST].m_X -= 1;
		else if (location[THIEF].m_X > location[PRIEST].m_X)
			location[PRIEST].m_X += 1;

		if (location[THIEF].m_Y < location[PRIEST].m_Y)
			location[PRIEST].m_Y -= 1;
		else if (location[THIEF].m_Y > location[PRIEST].m_Y)
			location[PRIEST].m_Y += 1;
	}

	if (dis[2] > 60)
	{
		if (location[PRIEST].m_X < location[WIZARD].m_X && location[WIZARD].m_X - location[PRIEST].m_X < 30)
			location[WIZARD].m_X -= 1;
		else if (location[PRIEST].m_X < location[WIZARD].m_X)
			location[WIZARD].m_X -= 8;
		else if (location[PRIEST].m_X > location[WIZARD].m_X && location[PRIEST].m_X - location[WIZARD].m_X < 30)
			location[WIZARD].m_X += 1;
		else if (location[PRIEST].m_X > location[WIZARD].m_X)
			location[WIZARD].m_X += 8;

		if (location[PRIEST].m_Y < location[WIZARD].m_Y && location[WIZARD].m_Y - location[PRIEST].m_Y < 30)
			location[WIZARD].m_Y -= 1;
		else if (location[PRIEST].m_Y < location[WIZARD].m_Y)
			location[WIZARD].m_Y -= 8;
		else if (location[PRIEST].m_Y > location[WIZARD].m_Y && location[PRIEST].m_Y - location[WIZARD].m_Y < 30)
			location[WIZARD].m_Y -= 1;
		else if (location[PRIEST].m_Y > location[WIZARD].m_Y)
			location[WIZARD].m_Y += 8;
	}
	else if (dis[2] > 40)
	{
		if (location[PRIEST].m_X < location[WIZARD].m_X && location[WIZARD].m_X - location[PRIEST].m_X < 3)
			location[WIZARD].m_X -= 1;
		else if (location[PRIEST].m_X < location[WIZARD].m_X)
			location[WIZARD].m_X -= 4;
		else if (location[PRIEST].m_X > location[WIZARD].m_X && location[PRIEST].m_X - location[WIZARD].m_X < 3)
			location[WIZARD].m_X += 1;
		else if (location[PRIEST].m_X > location[WIZARD].m_X)
			location[WIZARD].m_X += 4;

		if (location[PRIEST].m_Y < location[WIZARD].m_Y && location[WIZARD].m_Y - location[PRIEST].m_Y < 3)
			location[WIZARD].m_Y -= 1;
		else if (location[PRIEST].m_Y < location[WIZARD].m_Y)
			location[WIZARD].m_Y -= 4;
		else if (location[PRIEST].m_Y > location[WIZARD].m_Y && location[PRIEST].m_Y - location[WIZARD].m_Y < 3)
			location[WIZARD].m_Y -= 1;
		else if (location[PRIEST].m_Y > location[WIZARD].m_Y)
			location[WIZARD].m_Y += 4;
	}
	else if (dis[2] > 30)
	{
		if (location[PRIEST].m_X < location[WIZARD].m_X)
			location[WIZARD].m_X -= 1;
		else if (location[PRIEST].m_X > location[WIZARD].m_X)
			location[WIZARD].m_X += 1;

		if (location[PRIEST].m_Y < location[WIZARD].m_Y)
			location[WIZARD].m_Y -= 1;
		else if (location[PRIEST].m_Y > location[WIZARD].m_Y)
			location[WIZARD].m_Y += 1;
	}
}




