#ifndef __Logo_H__
#define __Logo_H__


class Logo : public Chap
{
public:
	Logo();
	~Logo();


	HWND hWnd;
	
	Sprite Opening[420];

	int speed;
	int alpha;

	DWORD OpeningTime;
	int m_OpeningCount;

	// ����Ÿ ���̽� �׽�Ʈ
	int count = 0;
	char cnt[256];
	char pw[256];

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	
};

#endif