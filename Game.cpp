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

	// 초기 스테이터스 설정
	status[HERO].SetStatus(300, 50, 15, 15, 15, 15, 15, 15, HERO, 0, 100);//올라운드형(만능이지만 서브)
	status[THIEF].SetStatus(300, 100, 20, 20, 15, 10, 10, 10, THIEF, 0, 100);//공격특화/회피 후 반격/공격 2타
	status[PRIEST].SetStatus(250, 100, 10, 10, 10, 10, 10, 25, PRIEST, 0, 100);//신앙특화
	status[WIZARD].SetStatus(250, 100, 10, 10, 10, 10, 25, 10, WIZARD, 0, 100);//마법공격특화

	sound.Init();
	Gmanager.Init();
	// 데이타 베이스///////////////////
	sql.Init();
}

void Game::Draw()
{
	
	map.DrawMap();
	character.Draw();
	inventory.Draw();
	tran.Draw();
	Gmanager.Draw();
	// 데이타 베이스///////////////////
	sql.Draw();
}

// Chap, 재정의 함수 호출
void Game::Update(double frame)
{
	static DWORD a = 0;
	
	if (GetTickCount64() - a > frame)
	{
		key.Update();
		character.Update();
		inventory.Update();
		tran.Update();
		// 입 맛에 맞게
		map.Update();
		Gmanager.Update();
		// 데이타 베이스///////////////////
		// 입 맛에 맞게 (여기선 안쓰임..프레임 값이 필요 할때만.. 그냥 방법만...)
		sql.Update(frame+3000);

		a = GetTickCount64();
	}
	

}


void Game::OnMessage( MSG* msg )
{

	
}