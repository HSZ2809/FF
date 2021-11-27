#include "Include.h"



Inventory inventory;


Inventory::Inventory()
{
	for (int i = 0; i < 4; i++)
		consumableItem[i] = 1;

	for (int i = 0; i < 8; i++)
		equipItem[i] = 0;

	gold = 100;//초기자금

	InventoryOpen = false;
	Cursormove = true;
	Show_IorE_curser = true;
	Show_IorE = true;
	Show_Select_curser = false;
	IorE[0] = 720;
	IorE[1] = 1000;
	
}

Inventory::~Inventory()
{
}

void Inventory::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/ui/C_window.png");
	C_window.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/C_hpmpback.png");
	C_hpmpback.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/HP_bar.png");
	HP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/MP_bar.png");
	MP_bar.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/C_face.png");
	C_face.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/C_item.png");
	C_item.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/ui/C_equipment.png");
	C_equipment.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/ui/FF_select.png");//손가락 커서UI용
	Inventory_cursor.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

}
void Inventory::Update()
{

	if (GetTickCount() - CursorTime > 50)
	{

		if (Cursormove == true)
		{
			cursormotionX += 1;
			if (cursormotionX == 10)
				Cursormove = false;
		}
		else if (Cursormove == false)
		{
			cursormotionX -= 1;
			if (cursormotionX == 0)
				Cursormove = true;
		}
		CursorTime = GetTickCount();
	}
}

void Inventory::Reset()
{
	for (int i = 0; i < 4; i++)
		consumableItem[i] = 1;

	for (int i = 0; i < 8; i++)
		equipItem[i] = 0;

}

void Inventory::Draw()
{
	TCHAR text[50];
	float bar;
	if (InventoryOpen == true)
	{
		C_window.Render(0, 0, 0, 1, 1);
		C_hpmpback.Render(0, 0, 0, 1, 1);

		bar = 185 * status[HERO].hp[NOW] / status[HERO].hp[MAX];
		HP_bar.Render(215, 165, 0, bar, 1);//용사 체력바
		bar = 185 * status[HERO].mp[NOW] / status[HERO].mp[MAX];
		MP_bar.Render(215, 222, 0, bar, 1);//용사 마력바57
		bar = 185 * status[THIEF].hp[NOW] / status[THIEF].hp[MAX];
		HP_bar.Render(215, 300, 0, bar, 1);//도적 체력바88
		bar = 185 * status[THIEF].mp[NOW] / status[THIEF].mp[MAX];
		MP_bar.Render(215, 357, 0, bar, 1);//도적 마력바
		bar = 185 * status[PRIEST].hp[NOW] / status[PRIEST].hp[MAX];
		HP_bar.Render(215, 438, 0, bar, 1);//성직자 체력바
		bar = 185 * status[PRIEST].mp[NOW] / status[PRIEST].mp[MAX];
		MP_bar.Render(215, 495, 0, bar, 1);//성직자 마력바
		bar = 185 * status[WIZARD].hp[NOW] / status[WIZARD].hp[MAX];
		HP_bar.Render(215, 573, 0, bar, 1);//마법사 체력바
		bar = 185 * status[WIZARD].mp[NOW] / status[WIZARD].mp[MAX];
		MP_bar.Render(215, 629, 0, bar, 1);//마법사 마력바

		C_face.Render(0, 0, 0, 1, 1);


		if (Show_IorE == true)
		{
			C_equipment.Render(0, 0, 0, 1, 1);
			C_item.Render(0, 0, 0, 1, 1);
			dv_font.DrawString("HP 물약", 785, 250);
			sprintf(text, "%d 개", inventory.consumableItem[HP_POTION]);
			dv_font.DrawString(text, 1100, 250);
			dv_font.DrawString("MP 물약", 785, 290);
			sprintf(text, "%d 개", inventory.consumableItem[MP_POTION]);
			dv_font.DrawString(text, 1100, 290);
			dv_font.DrawString("부활초", 785, 330);
			sprintf(text, "%d 개", inventory.consumableItem[RERIVE_POTION]);
			dv_font.DrawString(text, 1100, 330);
			dv_font.DrawString("폭탄", 785, 370);
			sprintf(text, "%d 개", inventory.consumableItem[BOOM]);
			dv_font.DrawString(text, 1100, 370);
		}
		if (Show_IorE == false)
		{
			C_item.Render(0, 0, 0, 1, 1);
			C_equipment.Render(0, 0, 0, 1, 1);
			dv_font.DrawString("아이언 소드", 785, 250);
			dv_font.DrawString("0 개", 1100, 250);
			dv_font.DrawString("아이언 대거", 785, 290);
			dv_font.DrawString("0 개", 1100, 290);
			dv_font.DrawString("홀리 스태프", 785, 330);
			dv_font.DrawString("0 개", 1100, 330);
			dv_font.DrawString("매지컬 완드", 785, 370);
			dv_font.DrawString("0 개", 1100, 370);
			dv_font.DrawString("아이언 아머", 785, 410);
			dv_font.DrawString("0 개", 1100, 410);
			dv_font.DrawString("래더 아머", 785, 450);
			dv_font.DrawString("0 개", 1100, 450);
			dv_font.DrawString("홀리 로브", 785, 490);
			dv_font.DrawString("0 개", 1100, 490);
			dv_font.DrawString("매지컬 케이프", 785, 530);
			dv_font.DrawString("0 개", 1100, 530);
		}


		dv_font.DrawString("용사", 180, 125);//이름 출력
		dv_font.DrawString("도적", 180, 261);//이름 출력
		dv_font.DrawString("성직자", 180, 397);//이름 출력
		dv_font.DrawString("마법사", 180, 533);//이름 출력

		sprintf(text, "%d""/""%d", status[HERO].hp[NOW], status[HERO].hp[MAX]);
		dv_font.NumString(text, 300, 140);//용사 체력
		sprintf(text, "%d""/""%d", status[HERO].mp[NOW], status[HERO].mp[MAX]);
		dv_font.NumString(text, 300, 196);//용사 마력
		sprintf(text, "%d""/""%d", status[THIEF].hp[NOW], status[THIEF].hp[MAX]);
		dv_font.NumString(text, 300, 276);//도적 체력56
		sprintf(text, "%d""/""%d", status[THIEF].mp[NOW], status[THIEF].mp[MAX]);
		dv_font.NumString(text, 300, 332);//도적 마력80
		sprintf(text, "%d""/""%d", status[PRIEST].hp[NOW], status[PRIEST].hp[MAX]);
		dv_font.NumString(text, 300, 412);//성직자 체력
		sprintf(text, "%d""/""%d", status[PRIEST].mp[NOW], status[PRIEST].mp[MAX]);
		dv_font.NumString(text, 300, 468);//성직자 마력
		sprintf(text, "%d""/""%d", status[WIZARD].hp[NOW], status[WIZARD].hp[MAX]);
		dv_font.NumString(text, 300, 548);//마법사 체력
		sprintf(text, "%d""/""%d", status[WIZARD].mp[NOW], status[WIZARD].mp[MAX]);
		dv_font.NumString(text, 300, 604);//마법사 마력

		sprintf(text, "STR     ""%d", status[HERO].stat[STR] + status[HERO].addStat[STR]);
		dv_font.StatString(text, 420, 125);//용사스탯
		sprintf(text, "AGI     ""%d", status[HERO].stat[AGI] + status[HERO].addStat[AGI]);
		dv_font.StatString(text, 520, 125);//용사스탯
		sprintf(text, "VIT     ""%d", status[HERO].stat[VIT] + status[HERO].addStat[VIT]);
		dv_font.StatString(text, 420, 170);//용사스탯
		sprintf(text, "DEX     ""%d", status[HERO].stat[DEX] + status[HERO].addStat[DEX]);
		dv_font.StatString(text, 520, 170);//용사스탯
		sprintf(text, "INT     ""%d", status[HERO].stat[INTELLI] + status[HERO].addStat[INTELLI]);
		dv_font.StatString(text, 420, 215);//용사스탯
		sprintf(text, "FAI     ""%d", status[HERO].stat[FAITH] + status[HERO].addStat[FAITH]);
		dv_font.StatString(text, 520, 215);//용사스탯

		sprintf(text, "STR     ""%d", status[THIEF].stat[STR] + status[THIEF].addStat[STR]);
		dv_font.StatString(text, 420, 261);//도적스탯
		sprintf(text, "AGI     ""%d", status[THIEF].stat[AGI] + status[THIEF].addStat[AGI]);
		dv_font.StatString(text, 520, 261);//도적스탯
		sprintf(text, "VIT     ""%d", status[THIEF].stat[VIT] + status[THIEF].addStat[VIT]);
		dv_font.StatString(text, 420, 306);//도적스탯
		sprintf(text, "DEX     ""%d", status[THIEF].stat[DEX] + status[THIEF].addStat[DEX]);
		dv_font.StatString(text, 520, 306);//도적스탯
		sprintf(text, "INT     ""%d", status[THIEF].stat[INTELLI] + status[THIEF].addStat[INTELLI]);
		dv_font.StatString(text, 420, 351);//도적스탯
		sprintf(text, "FAI     ""%d", status[THIEF].stat[FAITH] + status[THIEF].addStat[FAITH]);
		dv_font.StatString(text, 520, 351);//도적스탯

		sprintf(text, "STR     ""%d", status[PRIEST].stat[STR] + status[PRIEST].addStat[STR]);
		dv_font.StatString(text, 420, 397);//성직자 스탯
		sprintf(text, "AGI     ""%d", status[PRIEST].stat[AGI] + status[PRIEST].addStat[AGI]);
		dv_font.StatString(text, 520, 397);//성직자 스탯
		sprintf(text, "VIT     ""%d", status[PRIEST].stat[VIT] + status[PRIEST].addStat[VIT]);
		dv_font.StatString(text, 420, 442);//성직자 스탯
		sprintf(text, "DEX     ""%d", status[PRIEST].stat[DEX] + status[PRIEST].addStat[DEX]);
		dv_font.StatString(text, 520, 442);//성직자 스탯
		sprintf(text, "INT     ""%d", status[PRIEST].stat[INTELLI] + status[PRIEST].addStat[INTELLI]);
		dv_font.StatString(text, 420, 487);//성직자 스탯
		sprintf(text, "FAI     ""%d", status[PRIEST].stat[FAITH] + status[PRIEST].addStat[FAITH]);
		dv_font.StatString(text, 520, 487);//성직자 스탯

		sprintf(text, "STR     ""%d", status[WIZARD].stat[STR] + status[WIZARD].addStat[STR]);
		dv_font.StatString(text, 420, 533);//마법사 스탯
		sprintf(text, "AGI     ""%d", status[WIZARD].stat[AGI] + status[WIZARD].addStat[AGI]);
		dv_font.StatString(text, 520, 533);//마법사 스탯
		sprintf(text, "VIT     ""%d", status[WIZARD].stat[VIT] + status[WIZARD].addStat[VIT]);
		dv_font.StatString(text, 420, 578);//마법사 스탯
		sprintf(text, "DEX     ""%d", status[WIZARD].stat[DEX] + status[WIZARD].addStat[DEX]);
		dv_font.StatString(text, 520, 578);//마법사 스탯
		sprintf(text, "INT     ""%d", status[WIZARD].stat[INTELLI] + status[WIZARD].addStat[INTELLI]);
		dv_font.StatString(text, 420, 623);//마법사 스탯
		sprintf(text, "FAI     ""%d", status[WIZARD].stat[FAITH] + status[WIZARD].addStat[FAITH]);
		dv_font.StatString(text, 520, 623);//마법사 스탯

		
		sprintf(text, "%d", gold);
		dv_font.GoldString(text, 1050, 120);//소지금 출력1000, 120
		if (Show_IorE_curser == true)
		{
			Inventory_cursor.Render(IorE[IorE_Select] + cursormotionX, 160, 0, 1, 1);//아이템 장비 카테고리 선택 커서
		}
		if (Show_Select_curser == true)
		{
			Inventory_cursor.Render(0 + cursormotionX, 0, 0, 1, 1);
		}
	}
}

void Inventory::EarnGold(int _gold)
{
	gold += _gold;
}

bool Inventory::ConsumeItem(int itemIndex, Status* stat)
{
	if (consumableItem[itemIndex] <= 0)
		return false;

	switch (itemIndex)
	{
	case HP_POTION:
		consumableItem[itemIndex] -= 1;
		if (stat->hp[NOW] + HP_POTION_RECOVERY_AMOUNT > stat->hp[MAX])
			stat->hp[NOW] = stat->hp[MAX];
		else
			stat->hp[NOW] += HP_POTION_RECOVERY_AMOUNT;
		break;

	case MP_POTION:
		consumableItem[itemIndex] -= 1;
		if (stat->mp[NOW] + MP_POTION_RECOVERY_AMOUNT > stat->mp[MAX])
			stat->mp[NOW] = stat->mp[MAX];
		else
			stat->mp[NOW] += MP_POTION_RECOVERY_AMOUNT;
		break;

	case RERIVE_POTION:
		if (stat->live == false)
			consumableItem[itemIndex] -= 1;
		stat->live = true;
		break;

	default:
		// 디버그용 코드
		MessageBox(NULL, "알 수 없는 인덱스의 아이템이 사용됨", "에러", 0);
		break;
	}

	return true;
}

bool Inventory::ConsumeItem(int itemIndex, Monster* mon)
{
	if (consumableItem[itemIndex] <= 0)
		return false;

	switch (itemIndex)
	{
	case BOOM:
		consumableItem[itemIndex] -= 1;
		battle.Hit(BOOM_DAMEGE, mon);
		break;

	default:
		// 디버그용 코드
		MessageBox(NULL, "알 수 없는 인덱스의 아이템이 사용됨", "에러", 0);
		break;
	}

	return true;
}

bool Inventory::BuyItem(int itemIndex, int _gold)
{
	if (gold < _gold)
		return false;

	gold -= _gold;
	consumableItem[itemIndex] += 1;

	return true;
}

bool Inventory::EquipItem(int itemIndex, Status* stat)
{
	if (equipItem[itemIndex] <= 0)
		return false;

	// 1. 기존에 있던 장비를 제거하고 인벤토리에 추가하고 장비가 주는 추가 능력치를 제거한다.
	// 2. 인벤토리에 선택된 장비를 제거하고 스텟에 장비를 추가하고 주는 능력치를 추가한다.
	// 3. 참을 반환
}

bool Inventory::UnEquipItem(int itemIndex, Status* stat)
{
	return true;
}

bool Inventory::BuyEquipItem(int itemIndex, int _gold)
{
	if (gold < _gold)
		return false;

	gold -= _gold;
	equipItem[itemIndex] += 1;

	return true;
}

void Inventory::Keydown(int key)
{

	switch (key)
	{
	case LEFT:
		if (GetTickCount64() - KeyTime > 300)
		{
			if (IorE_Select == 1)
			{
				IorE_Select = 0;
			}
			else if (IorE_Select == 0)
			{
				IorE_Select = 1;
			}
			KeyTime = GetTickCount64();
		}
		break;

	case RIGHT:
		if (GetTickCount64() - KeyTime > 300)
		{
			if (IorE_Select == 0)
			{
				IorE_Select = 1;
			}
			else if (IorE_Select == 1)
			{
				IorE_Select = 0;
			}
			KeyTime = GetTickCount64();
		}
		break;

	case UP:
		if (GetTickCount64() - KeyTime > 300)
		{

			KeyTime = GetTickCount64();
		}
		break;

	case DOWN:
		if (GetTickCount64() - KeyTime > 300)
		{

			KeyTime = GetTickCount64();
		}

		break;
	


	case VK_KB_Z:
		if (GetTickCount64() - KeyTime1 > 300)
		{
			if (IorE_Select == 0)
			{
				Show_IorE = true;
				Show_IorE_curser = false;
				Show_Select_curser = true;
			}
			else if (IorE_Select == 1)
			{
				Show_IorE = false;
				Show_IorE_curser = false;
				Show_Select_curser = true;
			}

			KeyTime1 = GetTickCount64();
		}
	case VK_KB_X:
		if (GetTickCount64() - KeyTime1 > 300)
		{

			KeyTime1 = GetTickCount64();
		}
	case VK_KB_C:
		if (GetTickCount64() - KeyTime1 > 300)
		{

			if (inventory.InventoryOpen == false)
			{
				EffectPlay(sound.Menu);
				Gmanager.m_GameMap = false;
				inventory.InventoryOpen = true;
			}
			else if (inventory.InventoryOpen == true)
			{
				EffectPlay(sound.Menu);
				Gmanager.m_GameMap = true;
				inventory.InventoryOpen = false;
			}
			KeyTime1 = GetTickCount64();
		}
		break;
	}
}