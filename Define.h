#define SCREEN_WITH 1280	// 화면 가로 픽셀크기
#define SCREEN_HEIGHT 768	// 화면 세로 픽셀크기

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define VK_KB_Z 0X5A
#define VK_KB_X 0X58
#define VK_KB_C 0X43


// 데이타 베이스 3
//#define DB_HOST "127.0.0.1"
//#define DB_USER "root"
//#define DB_PASS "2809"
//#define DB_NAME "test"
//#define CHOP(x) x[strlen(x) - 1] = ' ' // 쓸려다가 안씀...

// 각 엑션의 계수
#define ATTACKFACTOR 2
#define HILLFACTOR 3

// 각 스킬의 ID
#define DOUBLE_SLASH 0
#define FIREBALL 1
#define BILZZARD 2

// 각 스킬의 계수
#define DOUBLE_SLASH_FACTOR 2
#define FIREBALL_FACTOR 3
#define BILZZARD_FACTOR 5

// 턴 확인용 변수의 값
#define PLAYER true
#define ENEMY false

// 몬스터 초기값
#define DRAGON_HP 300
#define DRAGON_STR 30
#define SLIME_HP 100
#define SLIME_STR 10
#define GOBLINE_HP 200
#define GOBLINE_STR 20

// 파티 멤버들의 ID
#define HERO 0
#define THIEF 1
#define PRIEST 2
#define WIZARD 3

// 파티 멤버들의 스테이터스 ID
enum statMenber
{
	STR,
	AGI,
	VIT,
	DEX,
	INTELLI,
	FAITH
};

// 파티 멤버들의 장비 스테이터스 ID
enum statAddMenber
{
	ADD_STR,
	ADD_AGI,
	ADD_VIT,
	ADD_INT,
	ADD_DEX,
	ADD_FAITH
};

// 파티 멤버들의 HP, MP, 경험치 ID
enum statHPMPEXP
{
	NOW,
	MAX
};


// 파티 멤버들의 장비 타입
#define WEAPON 0
#define ARMOR 1

// 서수 영어 정의
#define FIRST 0
#define SECOND 1
#define THIRD 2

// 높이와 너비
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

