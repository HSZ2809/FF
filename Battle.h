#ifndef __Battle_H__
#define __Battle_H__
#include "Include.h"

enum action { ATTACK, SKILL, ITEM, RUN };

struct decision
{
	bool actionSelect;
	bool skillSelect;
	bool itemSelect;
	bool friendlyTargetSelect;
	bool enemyTargetSelect;

	unsigned short action;
	unsigned short skill;
	unsigned short item;
	unsigned short enemyTarget;
	unsigned short friendlyTarget;
};

class Battle : public Chap
{
private:
	int actionLocation[4][2];
	int skillLocation[4][2];
	int itemLocation[4][2];
	int friendlyTargetLocation[4][2];
	int enemyTargetLocation[3][2];

	bool turn;
	int crewTurn;
	int enemyTurn;

	Sprite windowUI;
	Sprite subwindowUI;
	Sprite battleBG;
	Sprite hpmpframe, hpmpframe_back;
	Sprite HP_bar, MP_bar;
	Sprite cursor;//UIĿ����
	Sprite hero_face, thief_face, priest_face, wizard_face;//�ʻ�ȭ
public:
	Battle();
	~Battle();

	bool BGM_battle;
	decision d;

	DWORD BGTime; // ����
	DWORD CursorTime; //UIĿ����

	DWORD KeyTime;
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;

	//float speed;
	//int m_TgCount1;
	//int m_UiCount1;

	int uiX;
	int uiY;
	int bgX = 0;
	int bgY = 0;

	void Reset(decision* d);
	void Init();
	void Update(double frame);
	void Draw();

	virtual void OnMessage(MSG* msg);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	// ���� �ൿ

	void enemyAction();

	///////////////////////////////////////////////////////////////////////////////////////////////////

	// ������ �ʿ��� �Լ���. ������ �Ϸ�Ǹ� ����ȴ�.

	// ���ΰ� ������ ����
	void Attack(Status& userStat, Monster* m);
	// ���ΰ� ������ �ǰ�
	void Hit(int damage, Status* targetStat);
	// ���ΰ� ������ ��
	bool Hill(Status& userStat, Status* targetStat);
	// ���ΰ� ������ ��ų
	bool Skill(Status& userStat, Monster* monster);
	// ���ΰ� ������ ������ ��� (�Ʊ�����)
	bool UseItem(int itemIndex, Status* targetStat);
	// ���ΰ� ������ ������ ��� (��������)
	bool UseItem(int itemIndex, Monster* monster);
	// ���ΰ� ������ ����
	void Run();

	void CrewTurnCheck();

	// ������ ����
	void Attack(Monster& m, Status* charStat);
	// ������ �ǰ�
	void Hit(int damage, Monster* m);
};

extern Battle battle;
#endif