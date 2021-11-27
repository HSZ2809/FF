class g_DeviceFont
{
public:
	IDirect3D9* Direct3D;
	IDirect3DDevice9* Device9;
	D3DPRESENT_PARAMETERS d3dpp ;

	ID3DXSprite* Sprite;
	ID3DXFont* Fonts;
	D3DXFONT_DESC fdesc;

	ID3DXSprite* Num_Sprite;
	ID3DXFont* Num_Fonts;
	D3DXFONT_DESC ndesc;

	ID3DXSprite* S_Sprite;
	ID3DXFont* S_Fonts;
	D3DXFONT_DESC sdesc;

	ID3DXSprite* G_Sprite;
	ID3DXFont* G_Fonts;
	D3DXFONT_DESC gdesc;

public:
	g_DeviceFont(void);
	~g_DeviceFont(void);

	bool Create(HWND g_hWnd);

	bool DrawString(const char* msg, int x, int y, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	bool NumString(const char* msg, int x, int y, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	bool StatString(const char* msg, int x, int y, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	bool GoldString(const char* msg, int x, int y, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
};

extern g_DeviceFont dv_font;