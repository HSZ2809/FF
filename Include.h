#pragma once

/* ---------------------------------------------------
///////////////// ���α׷� ���� //////////////////////

		���̺귯���� �ʿ��� �����Դϴ�.
		����� �ȵſ�~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")
#pragma	comment (lib, "FMODENGIN/lib/fmodex64_vc.lib")

// ����Ÿ ���̽�///////////////////
//#include <my_global.h>
#include <winsock2.h>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

//////////////////////////////////

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>
#include <time.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include "DXUTsound.h"

#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"


/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		���� Ŭ���� ���� �� ����
		��������� �߰��� �ּ���~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "FmodSound.h"
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"

#include "Status.h"
#include "Monster.h"
#include "Transition.h"
#include "Battle.h"
#include "Inventory.h"
#include "Map.h"
#include "Collider.h"
#include "Character.h"

#include "Key.h"
#include "Sound.h"
#include "GameManager.h"


// ����Ÿ ���̽�///////////////////
#include "Mysql.h"

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		Ű �Է� ó�� �Լ��Դϴ�.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); 
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1 ); 
}