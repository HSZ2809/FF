#pragma once
#include "Include.h"

class Key
{

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// ���� Ű ������ ����
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	DWORD KeyTime4;
	


	void Update();
};

extern Key key;