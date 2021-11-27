#include <iostream>
using namespace std;

#include "FmodSound.h"

void main(void)
{
	/*
		.mp3, .MID, .wav ´Ù µÊ
	*/
	// µð½ºÅ©¸³ÅÍ ¹Þ¾Æ ¿È
	int FmodBGSound = AddSoundFile("./Sound/007¿ÀÇÁ´×.mp3", true);
	int FmodEffectSound = AddSoundFile("./Sound/BOOMSHAK.wav");

	bool	IsPlaying	= true;
	int		Input		= 0;

	// ....
	while(IsPlaying)
	{
		cout << "1. ¹è°æÀ½¾Ç ON"	<<endl;
		cout << "2. ¹è°æÀ½¾Ç OFF"	<<endl;
		cout << "3. È¿°úÀ½¾Ç"		<<endl;
		cout << "4. º¼·ý ¾÷"        << endl;
		cout << "5. º¼·ý ´Ù¿î"      << endl;
		cout << "6. ³ª°¡±â"		    << endl;
		cout << "ÀÔ·Â : ";
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