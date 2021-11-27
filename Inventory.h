#pragma once


#include "Include.h"

// Define.h에 추가할 것들(여기다 둬도 된다);
#define HP_POTION_RECOVERY_AMOUNT 100
#define MP_POTION_RECOVERY_AMOUNT 100
#define BOOM_DAMEGE 100

#pragma region 장비 능력치
//#define DEFALT_ADD_STR
//
//#define IRON_SWORD
//#define IRON_ARMOR
//
//#define IRON_DAGGER
//#define LEATHER_ARMOR
//
//#define SAINT_STAFF
//#define SAINT_ROBE
//
//#define MAGIC_WAND
//#define MAGIC_CLOA
#pragma endregion

// 소모 아이템 인덱스
enum consumableItemIndex
{
	HP_POTION,
	MP_POTION,
	RERIVE_POTION,
	BOOM
};
// 장비 아이템 인덱스
enum equipItemIndex
{
	DEFALT,

	IRON_SWORD,
	IRON_ARMOR,

	IRON_DAGGER,
	LEATHER_ARMOR,

	SAINT_STAFF,
	SAINT_ROBE,

	MAGIC_WAND,
	MAGIC_CLOAK
};

class Inventory
{



public:
	Inventory();
	~Inventory();


	Sprite C_window, C_hpmpback, HP_bar, MP_bar, C_face, C_item, C_equipment;
	Sprite Inventory_cursor;

	int consumableItem[4];
	int equipItem[9];
	int gold;
	int cursormotionX;
	int IorE[2], IorE_Select;

	DWORD KeyTime, KeyTime1, CursorTime;

	BOOL InventoryOpen;
	BOOL Cursormove;
	BOOL Show_IorE_curser;
	BOOL Show_IorE;
	BOOL Show_Select_curser;

	bool ConsumeItem(int itemIndex, Status* stat);
	bool ConsumeItem(int itemIndex, Monster* mon);
	bool BuyItem(int itemIndex, int _gold);

	// 장비와 소모품의 메소드를 나누려면
	bool EquipItem(int itemIndex, Status* stat);
	bool UnEquipItem(int itemIndex, Status* stat);
	bool BuyEquipItem(int itemIndex, int _gold);

	void EarnGold(int _gold);


	void Init();
	void Update();
	void Reset();
	void Draw();
	void Keydown(int key);

};

extern Inventory inventory;