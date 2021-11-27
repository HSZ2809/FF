#include "Include.h"

Sound sound;



Sound::Sound(void)
{
	//g_pSoundManager = NULL; 사용 안했다
}

Sound::~Sound(void)
{
}

void Sound::Init()
{

	Intro = AddSoundFile("./resource/Sound/opening.mp3", false);//인트로 영상 브금
	BGM_Menu = AddSoundFile("./resource/Sound/menu.mp3", true);//메뉴 오케스트라 브금
	BGM_Map1 = AddSoundFile("./resource/Sound/map1.mp3", true);//시작 보석방 브금
	BGM_Battle = AddSoundFile("./resource/Sound/battle.mp3", true);//전투배경음악

	Battle_Start = AddSoundFile("./resource/Sound/battle_start.mp3", false);//전투배경음악
	Victory = AddSoundFile("./resource/Sound/victory.mp3", false);//승리음악
	Move = AddSoundFile("./resource/Sound/move.mp3", false);
	Select = AddSoundFile("./resource/Sound/select.mp3", false);
	Cancel = AddSoundFile("./resource/Sound/cancel.mp3", false);
	Run = AddSoundFile("./resource/Sound/run.ogg", false);

	Menu = AddSoundFile("./resource/Sound/inventory.ogg", false);

}
