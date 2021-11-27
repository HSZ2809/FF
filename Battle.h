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
	Sprite cursor;//UI커서용
	Sprite hero_face, thief_face, priest_face, wizard_face;//초상화
public:
	Battle();
	~Battle();

	bool BGM_battle;
	decision d;

	DWORD BGTime; // 배경용
	DWORD CursorTime; //UI커서용

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
	// 적의 행동

	void enemyAction();

	///////////////////////////////////////////////////////////////////////////////////////////////////

	// 전투에 필요한 함수들. 선택이 완료되면 실행된다.

	// 주인공 일행의 공격
	void Attack(Status& userStat, Monster* m);
	// 주인공 일행의 피격
	void Hit(int damage, Status* targetStat);
	// 주인공 일행의 힐
	bool Hill(Status& userStat, Status* targetStat);
	// 주인공 일행의 스킬
	bool Skill(Status& userStat, Monster* monster);
	// 주인공 일행의 아이템 사용 (아군에게)
	bool UseItem(int itemIndex, Status* targetStat);
	// 주인공 일행의 아이템 사용 (적군에게)
	bool UseItem(int itemIndex, Monster* monster);
	// 주인공 일행의 도망
	void Run();

	void CrewTurnCheck();

	// 몬스터의 공격
	void Attack(Monster& m, Status* charStat);
	// 몬스터의 피격
	void Hit(int damage, Monster* m);
};

extern Battle battle;
#endif