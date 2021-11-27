#include "Include.h"

Sound sound;



Sound::Sound(void)
{
	//g_pSoundManager = NULL; ��� ���ߴ�
}

Sound::~Sound(void)
{
}

void Sound::Init()
{

	Intro = AddSoundFile("./resource/Sound/opening.mp3", false);//��Ʈ�� ���� ���
	BGM_Menu = AddSoundFile("./resource/Sound/menu.mp3", true);//�޴� ���ɽ�Ʈ�� ���
	BGM_Map1 = AddSoundFile("./resource/Sound/map1.mp3", true);//���� ������ ���
	BGM_Battle = AddSoundFile("./resource/Sound/battle.mp3", true);//�����������

	Battle_Start = AddSoundFile("./resource/Sound/battle_start.mp3", false);//�����������
	Victory = AddSoundFile("./resource/Sound/victory.mp3", false);//�¸�����
	Move = AddSoundFile("./resource/Sound/move.mp3", false);
	Select = AddSoundFile("./resource/Sound/select.mp3", false);
	Cancel = AddSoundFile("./resource/Sound/cancel.mp3", false);
	Run = AddSoundFile("./resource/Sound/run.ogg", false);

	Menu = AddSoundFile("./resource/Sound/inventory.ogg", false);

}
