#pragma once

class Sound
{
	
public:
	Sound(void);
	~Sound(void);

	
//CSoundManager* g_pSoundManager;



	int Intro;//��Ʈ�� ���� ���
	int BGM_Menu;//�޴� ���ɽ�Ʈ�� ���
	int BGM_Map1;//���� ������ ���
	int BGM_Battle;//�����������

	int Battle_Start;//��Ʋ ���� ȿ����
	int Victory;//�¸�����
	int Move;
	int Select;
	int Cancel;
	int Run;
	int Menu;
	void Init();
	
	
};

extern Sound sound;