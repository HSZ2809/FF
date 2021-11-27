#define SCREEN_WITH 1280	// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define VK_KB_Z 0X5A
#define VK_KB_X 0X58
#define VK_KB_C 0X43

// ����Ÿ ���̽�
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "2809"
#define DB_NAME "test"
#define CHOP(x) x[strlen(x) - 1] = ' ' // �����ٰ� �Ⱦ�...

// �� ������ ���
#define ATTACKFACTOR 2
#define HILLFACTOR 3

// �� ��ų�� ID
#define DOUBLE_SLASH 0
#define FIREBALL 1
#define BILZZARD 2

// �� ��ų�� ���
#define DOUBLE_SLASH_FACTOR 2
#define FIREBALL_FACTOR 3
#define BILZZARD_FACTOR 5

// �� Ȯ�ο� ������ ��
#define PLAYER true
#define ENEMY false

// ���� �ʱⰪ
#define DRAGON_HP 300
#define DRAGON_STR 30
#define SLIME_HP 100
#define SLIME_STR 10
#define GOBLINE_HP 200
#define GOBLINE_STR 20

// ��Ƽ ������� ID
#define HERO 0
#define THIEF 1
#define PRIEST 2
#define WIZARD 3

// ��Ƽ ������� �������ͽ� ID
enum statMenber
{
	STR,
	AGI,
	VIT,
	DEX,
	INTELLI,
	FAITH
};

// ��Ƽ ������� ��� �������ͽ� ID
enum statAddMenber
{
	ADD_STR,
	ADD_AGI,
	ADD_VIT,
	ADD_INT,
	ADD_DEX,
	ADD_FAITH
};

// ��Ƽ ������� HP, MP, ����ġ ID
enum statHPMPEXP
{
	NOW,
	MAX
};


// ��Ƽ ������� ��� Ÿ��
#define WEAPON 0
#define ARMOR 1

// ���� ���� ����
#define FIRST 0
#define SECOND 1
#define THIRD 2

// ���̿� �ʺ�
#define WIDTH 0
#define HEIGHT 1

enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	OVER = 3,
	BATTLE = 4,
	TOTALCHAP
};

