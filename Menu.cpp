#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	count = 0;
	alphaEnter = 0;
	alphaLogo = 255;
	menuimg.Create("./resource/Img/lobby/Lobby.png", false, D3DCOLOR_XRGB(0, 0, 0));
	menustart.Create("./resource/Img/lobby/start.png", false, D3DCOLOR_XRGB(0, 0, 0));
	
}

// Chap, 재정의 함수 호출
void Menu::Update(double frame)
{
	

	if (GetTickCount() - MainTime > 500)
	{
		if (alphaLogo > 255)
		{
			alphaLogo++;
			MainTime = GetTickCount();
		}
		else if (alphaLogo == 255)
			alphaLogo = 255;
	}

	if (alphaLogo == 255)
	{
		alphaEnter += speed * frame / 10;
		if (START_Tans == true)
		{
			alphaEnter -= 5;
			if (alphaEnter == 50)
				START_Tans = false;
		}
		if (START_Tans == false)
		{
			alphaEnter += 5;
			if (alphaEnter == 255)
				START_Tans = true;

		}

	}
	
	



	//key.Update();

	//if (xx.xxx > 100 * xxx.xxx)
	//{
	//	if (GetTickCount() - CoinTime > 100)
	//	{
	//		count++;
	//		CoinTime = GetTickCount();
	//	}
	//	if (count > 1) count = 0;
	//}


}

void Menu::Draw()
{
	menuimg.SetColor(255, 255, 255, alphaLogo);
	menuimg.Draw(0, 0); //이미지출력

	menustart.SetColor(255, 255, 255, alphaEnter);  // 색상 변경
	menustart.Draw(0, 0);
	


}

void Menu::OnMessage(MSG* msg)
{


	
	if (KeyDown(VK_RETURN))
	{

			g_Mng.n_Chap = GAME;
			BGStop();
			
	}


}