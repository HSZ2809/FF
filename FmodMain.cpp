#include <iostream>
using namespace std;

#include "FmodSound.h"

void main(void)
{
	/*
		.mp3, .MID, .wav �� ��
	*/
	// ��ũ���� �޾� ��
	int FmodBGSound = AddSoundFile("./Sound/007������.mp3", true);
	int FmodEffectSound = AddSoundFile("./Sound/BOOMSHAK.wav");

	bool	IsPlaying	= true;
	int		Input		= 0;

	// ....
	while(IsPlaying)
	{
		cout << "1. ������� ON"	<<endl;
		cout << "2. ������� OFF"	<<endl;
		cout << "3. ȿ������"		<<endl;
		cout << "4. ���� ��"        << endl;
		cout << "5. ���� �ٿ�"      << endl;
		cout << "6. ������"		    << endl;
		cout << "�Է� : ";
		cin >>Input;

		switch( Input )
		{
			case 1:		BGPlay(FmodBGSound);			break;
			case 2:		BGStop();					    break;
			case 3:		EffectPlay(FmodEffectSound);	break;
			case 4:		VolumUp();						break;
			case 5:		VolumDown();					break;
			case 6:		IsPlaying = false;			    break;
		}
	}
}