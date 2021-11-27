#include "Include.h"


Map map;

Map::Map()
{
	Gmanager.m_GameMap = true;
	BGM_map = true;
	m_Stage = 1;

	CL.x = 1;
	CL.y = 1;
}

Map::~Map()
{
}

void Map::Init()
{
	
	int i, j;
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/map/BG_Tiles/Outside_A5.png");
	m_BG_Outside_A5.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/map/BG_Tiles/Outside_A2.png");
	m_BG_Outside_A2.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/map/BG_Tiles/Inside_A1.png");
	m_BG_Inside_A1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/map/BG_Tiles/Outside_B.png");
	m_BGO.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Map::Update()
{
	
	if (BGM_map == true)
	{
		if (m_Stage == 1)
		{
			BGPlay(sound.BGM_Map1);
		}
		BGM_map = false;
	}
}

void Map::DrawMap()
{
	// ¸Ê ¹Ù´Ú
	if (m_Stage == 1)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage1_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage1_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage1_map[x][y] == 7)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill2[0], hill2[1], hill2[2], hill2[3], 0, 1, 1);

				if (m_Stage1_map[x][y] == 8)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill1[0], hill1[1], hill1[2], hill1[3], 0, 1, 1);

				if (m_Stage1_map[x][y] == 9)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage1_map[x][y] == 2)
					m_BG_Inside_A1.RenderDraw(0 + y * 32, 0 + x * 32, tampleGround[0], tampleGround[1], tampleGround[2], tampleGround[3], 0, 1, 1);
			}
		}
	}
	else if (m_Stage == 2)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage2_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage2_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage2_map[x][y] == 2)
					m_BG_Outside_A2.RenderDraw(0 + y * 32, 0 + x * 32, road[0], road[1], road[2], road[3], 0, 1, 1);
			}
		}
	}
	else if (m_Stage == 3)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage3_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage3_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage3_map[x][y] == 2)
					m_BG_Outside_A2.RenderDraw(0 + y * 32, 0 + x * 32, road[0], road[1], road[2], road[3], 0, 1, 1);
			}
		}
	}
	else if (m_Stage == 4)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage4_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage4_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage4_map[x][y] == 2)
					m_BG_Outside_A2.RenderDraw(0 + y * 32, 0 + x * 32, road[0], road[1], road[2], road[3], 0, 1, 1);
			}
		}
	}
	else if (m_Stage == 5)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage5_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage5_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage5_map[x][y] == 2)
					m_BG_Outside_A2.RenderDraw(0 + y * 32, 0 + x * 32, road[0], road[1], road[2], road[3], 0, 1, 1);

				if (m_Stage5_map[x][y] == 7)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill2[0], hill2[1], hill2[2], hill2[3], 0, 1, 1);

				if (m_Stage5_map[x][y] == 8)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill1[0], hill1[1], hill1[2], hill1[3], 0, 1, 1);
			}
		}
	}
	else if (m_Stage == 6)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage6_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);

				if (m_Stage6_map[x][y] == 1)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, grass[0], grass[1], grass[2], grass[3], 0, 1, 1);

				if (m_Stage6_map[x][y] == 7)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill2[0], hill2[1], hill2[2], hill2[3], 0, 1, 1);

				if (m_Stage6_map[x][y] == 8)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, hill1[0], hill1[1], hill1[2], hill1[3], 0, 1, 1);
			}
		}
	}
}

void Map::DrawObject()
{
	// ¸Ê ¿ÀºêÁ§Æ®
	if (m_Stage == 1)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage1_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
	if (m_Stage == 2)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage2_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
	if (m_Stage == 3)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage3_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
	if (m_Stage == 4)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage4_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
	if (m_Stage == 5)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage5_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
	if (m_Stage == 6)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 40; y++)
			{
				if (m_Stage6_map[x][y] == 0)
					m_BG_Outside_A5.RenderDraw(0 + y * 32, 0 + x * 32, dark[0], dark[1], dark[2], dark[3], 0, 1, 1);
			}
		}
	}
}

void Map::Keydown(int key)
{
	if (Gmanager.m_GameMap == true)
	{
		switch (key)
		{
		case LEFT:
			character.Move_key = character.MoveLeft;
			if (character.location[HERO].m_X <= 0)
			{
				if (m_Global_Stage[CL.x][CL.y - 1] == true)
				{
					CL.y--;

					m_Stage--;

					for (int i = 0; i < 4; i++)
						character.location[i].m_X = 1280;
				}
			}
			else if (collider.CanMove(LEFT) == false)
				character.location[HERO].m_X = character.location[HERO].m_X;
			else
				character.location[HERO].m_X -= 5;

			break;

		case RIGHT:
			character.Move_key = character.MoveRight;
			if (character.location[HERO].m_X >= 1248)
			{
				if (m_Global_Stage[CL.x][CL.y + 1] == true)
				{
					CL.y++;

					m_Stage++;

					for (int i = 0; i < 4; i++)
						character.location[i].m_X = 0;
				}
			}
			else if (collider.CanMove(RIGHT) == false)
				character.location[HERO].m_X = character.location[HERO].m_X;
			else
				character.location[HERO].m_X += 5;

			break;

		case UP:
			character.Move_key = character.MoveUp;
			if (character.location[HERO].m_Y <= 0)
			{
				if (m_Global_Stage[CL.x - 1][CL.y] == true)
				{
					CL.x--;

					m_Stage--;

					for (int i = 0; i < 4; i++)
						character.location[i].m_Y = 730;
				}
			}
			else if (collider.CanMove(UP) == false)
				character.location[HERO].m_Y = character.location[HERO].m_Y;
			else
				character.location[HERO].m_Y -= 5;

			break;

		case DOWN:
			character.Move_key = character.MoveDown;
			if (character.location[HERO].m_Y >= 730)
			{
				if (m_Global_Stage[CL.x + 1][CL.y] == true)
				{
					CL.x++;

					m_Stage++;

					for (int i = 0; i < 4; i++)
						character.location[i].m_Y = 0;
				}
			}
			else if (collider.CanMove(DOWN) == false)
				character.location[HERO].m_Y = character.location[HERO].m_Y;
			else
				character.location[HERO].m_Y += 5;

			break;
		}
	}


	switch (key)
	{
	case VK_KB_Z:
		if (GetTickCount64() - KeyTime > 300)
		{

		
			KeyTime = GetTickCount64();
		}
	case VK_KB_X:
		if (GetTickCount64() - KeyTime > 300)
		{


		}
	case VK_KB_C:
		if (GetTickCount64() - KeyTime > 300)
		{
			
			//if (inventory.InventoryOpen == false)
			//{
			//	Gmanager.m_GameMap = false;
			//	inventory.InventoryOpen = true;
			//}
			//else if (inventory.InventoryOpen == true)
			//{
			//	Gmanager.m_GameMap = true;
			//	inventory.InventoryOpen = false;
			//}
			//KeyTime = GetTickCount64();
		}

		break;
	}
}
