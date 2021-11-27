#include "Include.h"

g_DeviceFont dv_font;

g_DeviceFont::g_DeviceFont(void)
{
	// ��Ʈ ���ҽ� �߰�
	AddFontResourceEx("./Typo_SsangmunDongB.ttf", FR_PRIVATE, 0);
	AddFontResourceEx("./basis33.ttf", FR_PRIVATE, 0);
	AddFontResourceEx("./PF��Ÿ����Ʈ_Bold.ttf", FR_PRIVATE, 0);
}

g_DeviceFont::~g_DeviceFont(void)
{
}

bool g_DeviceFont::Create( HWND g_hWnd )
{

	Direct3D = Direct3DCreate9( D3D_SDK_VERSION );




	ZeroMemory( &d3dpp, sizeof( d3dpp ) );
	d3dpp.Windowed = TRUE;												// ��ü ȭ�� ���� ����
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;							// ���� ȿ������ SWAP ȿ��
	d3dpp.hDeviceWindow = g_hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;				            // ���� ����ȭ�� ��忡 ���� �ĸ� ���۸� ����
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE ;
	d3dpp.BackBufferWidth = SCREEN_WITH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	Direct3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &Device9 );


	// ��������Ʈ/��Ʈ �׸��� ���� ����.
	D3DXCreateSprite( Device9 , &Sprite ) ;

	ZeroMemory(&fdesc, sizeof(fdesc));
	fdesc.Height = 30 ;
	fdesc.Width = 12 ;
	fdesc.Weight = 500 ;
	fdesc.Italic = FALSE ;
	fdesc.CharSet = DEFAULT_CHARSET ;
	//fdesc.FaceName[LF_FACESIZE];
	//strcpy( fdesc.FaceName , "����" ) ;
	strcpy( fdesc.FaceName, "Ÿ����_�ֹ��� B" ) ;

	D3DXCreateFontIndirect(Device9, &fdesc, &Fonts);

	// ��������Ʈ/��Ʈ �׸��� ���� ����.
	D3DXCreateSprite(Device9, &Num_Sprite);

	ZeroMemory(&ndesc, sizeof(ndesc));
	ndesc.Height = 30;
	ndesc.Width = 14;
	ndesc.Weight = 500;
	ndesc.Italic = FALSE;
	ndesc.CharSet = DEFAULT_CHARSET;
	//fdesc.FaceName[LF_FACESIZE];
	//strcpy( fdesc.FaceName , "����" ) ;
	strcpy(ndesc.FaceName, "basis33");

	D3DXCreateFontIndirect(Device9, &ndesc, &Num_Fonts);

	// ��������Ʈ/��Ʈ �׸��� ���� ����.
	D3DXCreateSprite(Device9, &S_Sprite);

	ZeroMemory(&sdesc, sizeof(sdesc));
	sdesc.Height = 30;
	sdesc.Width = 14;
	sdesc.Weight = 500;
	sdesc.Italic = FALSE;
	sdesc.CharSet = DEFAULT_CHARSET;
	//fdesc.FaceName[LF_FACESIZE];
	//strcpy( fdesc.FaceName , "����" ) ;
	strcpy(sdesc.FaceName, "PF��Ÿ����Ʈ Bold");

	D3DXCreateFontIndirect(Device9, &sdesc, &S_Fonts);

	// ��������Ʈ/��Ʈ �׸��� ���� ����.
	D3DXCreateSprite(Device9, &G_Sprite);

	ZeroMemory(&gdesc, sizeof(gdesc));
	gdesc.Height = 30;
	gdesc.Width = 14;
	gdesc.Weight = 500;
	gdesc.Italic = FALSE;
	gdesc.CharSet = DEFAULT_CHARSET;
	//fdesc.FaceName[LF_FACESIZE];
	//strcpy( fdesc.FaceName , "����" ) ;
	strcpy(gdesc.FaceName, "Ÿ����_�ֹ��� B");

	D3DXCreateFontIndirect(Device9, &gdesc, &G_Fonts);

	return true;

}




bool g_DeviceFont::DrawString( const char* msg , int x , int y , D3DCOLOR color)
{
	RECT rect = { x , y , fdesc.Width*strlen(msg) , fdesc.Height } ;

	Sprite->Begin( D3DXSPRITE_ALPHABLEND ) ;
	//Fonts->DrawText(Sprite, msg, strlen(msg), &rect, DT_NOCLIP, color(���ϴ� Į�� ���� ��));
	Fonts->DrawText( Sprite , msg , strlen( msg ) , &rect , DT_NOCLIP , D3DCOLOR_XRGB(255,255,255) ) ;
	Sprite->End() ;
	
	return true;
}

bool g_DeviceFont::NumString(const char* msg, int x, int y, D3DCOLOR color)
{
	RECT rect = { x , y , ndesc.Width * strlen(msg) , ndesc.Height };

	Num_Sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//Fonts->DrawText(Sprite, msg, strlen(msg), &rect, DT_NOCLIP, color(���ϴ� Į�� ���� ��));
	Num_Fonts->DrawText(Num_Sprite, msg, strlen(msg), &rect, DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	Num_Sprite->End();

	return true;
}

bool g_DeviceFont::StatString(const char* msg, int x, int y, D3DCOLOR color)
{
	RECT rect = { x , y , sdesc.Width * strlen(msg) , sdesc.Height };

	S_Sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//Fonts->DrawText(Sprite, msg, strlen(msg), &rect, DT_NOCLIP, color(���ϴ� Į�� ���� ��));
	S_Fonts->DrawText(S_Sprite, msg, strlen(msg), &rect, DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	S_Sprite->End();

	return true;
}

bool g_DeviceFont::GoldString(const char* msg, int x, int y, D3DCOLOR color)
{
	RECT rect = { x , y , gdesc.Width * strlen(msg) , gdesc.Height };

	G_Sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//Fonts->DrawText(Sprite, msg, strlen(msg), &rect, DT_NOCLIP, color(���ϴ� Į�� ���� ��));
	G_Fonts->DrawText(G_Sprite, msg, strlen(msg), &rect, DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	G_Sprite->End();

	return true;
}