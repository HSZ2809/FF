#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;
	Sprite menustart;

public:
	Menu();
	~Menu();
	
	DWORD MainTime;

	BOOL START_Tans = true;
	float speed;
	float alphaLogo, alphaEnter;
	int count;


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif