#include "Include.h"

Key key;

Key::Key(void)
{

	
}

Key::~Key(void)
{
}


void Key::Update()
{
	// 시스템에 따라...GetTickCount/GetTickCount64
	if (KeyDown('1'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			g_Mng.n_Chap = BATTLE;
			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('2'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
		
		}

	}

	if (KeyDown('3'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

		}

	}

	if (KeyDown('4'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('5'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('6'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}

	if (KeyDown('7'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('8'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

		}

	}

	if (KeyDown('9'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown('0'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F1))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F2))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F3))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F4))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F5))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F6))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F7))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F8))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F9))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F10))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F11))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_F12))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_SPACE))
	{

		if (GetTickCount64() - KeyTime2 > 200)
		{
	
			KeyTime2 = GetTickCount64();
		}

	}


	if (KeyDown(VK_LEFT))
	{
		if (Gmanager.m_GameMap == true)
		{
			map.Keydown(LEFT);
		}
		inventory.Keydown(LEFT);
	}

	if (KeyDown(VK_RIGHT))
	{
		if (Gmanager.m_GameMap == true)
		{
			map.Keydown(RIGHT);
		}
		inventory.Keydown(RIGHT);
	}


	if (KeyDown(VK_UP))
	{
		if (Gmanager.m_GameMap == true)
		{
			map.Keydown(UP);
		}
		inventory.Keydown(UP);
	}

	if (KeyDown(VK_DOWN))
	{
		if (Gmanager.m_GameMap == true)
		{
			map.Keydown(DOWN);
		}
		inventory.Keydown(DOWN);
	}

	if (KeyDown('Z'))
	{
		inventory.Keydown(VK_KB_Z);
	}
	if (KeyDown('X'))
	{
		inventory.Keydown(VK_KB_X);
	}
	if (KeyDown('C'))
	{
		inventory.Keydown(VK_KB_C);
	}
	if (KeyDown('N'))
	{

		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	}
	if (KeyDown('A'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	}
	if (KeyDown('W'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}

	}
	if (KeyDown('E'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}
	if (KeyDown('R'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}
	if (KeyDown('S'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}
	if (KeyDown('D'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}
	if (KeyDown(VK_RETURN))
	{

		if (GetTickCount64() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount64();
		}

	}


}