#pragma once

class Sound
{
	
public:
	Sound(void);
	~Sound(void);

	
//CSoundManager* g_pSoundManager;



	int Intro;//인트로 영상 브금
	int BGM_Menu;//메뉴 오케스트라 브금
	int BGM_Map1;//시작 보석방 브금
	int BGM_Battle;//전투배경음악

	int Battle_Start;//배틀 시작 효과음
	int Victory;//승리음악
	int Move;
	int Select;
	int Cancel;
	int Run;
	int Menu;
	void Init();
	
	
};

extern Sound sound;