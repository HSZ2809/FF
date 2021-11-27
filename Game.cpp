#include "Include.h"
Game game;
Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	
	map.Init();
	inventory.Init();
	battle.Init();
	character.Init();
	tran.Init();

	// �ʱ� �������ͽ� ����
	status[HERO].SetStatus(300, 50, 15, 15, 15, 15, 15, 15, HERO, 0, 100);//�ö�����(���������� ����)
	status[THIEF].SetStatus(300, 100, 20, 20, 15, 10, 10, 10, THIEF, 0, 100);//����Ưȭ/ȸ�� �� �ݰ�/���� 2Ÿ
	status[PRIEST].SetStatus(250, 100, 10, 10, 10, 10, 10, 25, PRIEST, 0, 100);//�ž�Ưȭ
	status[WIZARD].SetStatus(250, 100, 10, 10, 10, 10, 25, 10, WIZARD, 0, 100);//��������Ưȭ

	sound.Init();
	Gmanager.Init();
	// ����Ÿ ���̽�///////////////////
	sql.Init();
}

void Game::Draw()
{
	
	map.DrawMap();
	character.Draw();
	inventory.Draw();
	tran.Draw();
	Gmanager.Draw();
	// ����Ÿ ���̽�///////////////////
	sql.Draw();
}

// Chap, ������ �Լ� ȣ��
void Game::Update(double frame)
{
	static DWORD a = 0;
	
	if (GetTickCount64() - a > frame)
	{
		key.Update();
		character.Update();
		inventory.Update();
		tran.Update();
		// �� ���� �°�
		map.Update();
		Gmanager.Update();
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
		sql.Update(frame+3000);

		a = GetTickCount64();
	}
	

}


void Game::OnMessage( MSG* msg )
{

	
}