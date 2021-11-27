//#include <windows.h>
//#include <mmsystem.h>
#include "Include.h" 
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;
int loops;
float interpolation;
// ���� �߰�
char buffer[128] = {0,0,0,0};
char ch[3] = {0,0,0}; //D  strcat ���� Ʋ�� �ּ� ���� ���� �ֵ��� �������
////////////////////////////////////
LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wc ;
	HWND g_hWnd ;
	wc.hInstance = GetModuleHandle( NULL ) ;
	wc.cbSize = sizeof( wc ) ;
	wc.style = CS_CLASSDC ;
	wc.cbClsExtra = NULL ;
	wc.cbWndExtra = NULL ;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH) ;
	wc.hCursor = LoadCursor( wc.hInstance, IDC_ARROW ) ;
	wc.hIcon = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.hIconSm = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.lpfnWndProc = WndProc ;
	wc.lpszClassName ="Game" ;
	wc.lpszMenuName = NULL ;

	RegisterClassEx( &wc ) ;

	/* ---------------------------------------------------
	/////////////////// ����� ��� ////////////////////

				���α׷��� ������� �����
				����ϰ� �� �ִ� �ڵ��Դϴ�.

	//////////////////////////////////////////////////////
	----------------------��-��-��-��-��-----------------*/
	RECT rt = {0, 0, SCREEN_WITH, SCREEN_HEIGHT};
	int W = rt.right - rt.left;
	int H = rt.bottom - rt.top;
	int X = (GetSystemMetrics(SM_CXSCREEN)/2) - SCREEN_WITH/2;
	int Y = ( (GetSystemMetrics(SM_CYSCREEN)/2) - SCREEN_HEIGHT/2 );
	/*---------------------��-��-��-��-------------------*/

	/*
		int WINAPI GetSystemMetrics(
			int nIndex
		);

		<���ڰ�>
		SM_CXSCREEN : ȭ���� ���̸� ���� �� �ִ�.
		SM_CYSCREEN : ȭ���� ���̸� ���� �� �ִ�.

		���� ȭ���� �ػ󵵸� ���� �� �ִ�. �� �ܿ��� ���ڰ������� �پ��� ���� ���� �� �ִ�.
		�ڼ��� ������ MSDN �� GetSystemMetrics �� �����ϱ� �ٶ�
		��, ���� ����Ϳ��� ���� ���� ��� ���� ����Ϳ� ���ؼ��� ���� ���ϱ⶧���� �� �Լ��� ����ϸ� �ȵȴ�.
		���� ����Ϳ��� ��ü �ػ󵵸� ���ϱ� ���Ұ�� GetMonitorInfo �Լ��� �̿�����
	*/

	// WS_POPUP ���� �������� �����~
	g_hWnd = CreateWindowEx( NULL, wc.lpszClassName, 
		"Game", 
		WS_EX_TOPMOST, 
		X, Y, W, H,
		NULL, NULL, wc.hInstance, NULL ) ;


	dv_font.Create(g_hWnd) ;
	//sound.g_pSoundManager = new CSoundManager();
	//sound.g_pSoundManager->Initialize(g_hWnd, DSSCL_PRIORITY);
	//sound.g_pSoundManager->SetPrimaryBufferFormat(2,22050,16);
	
	//g_SoundManager.Initialize(g_hWnd, DSSCL_PRIORITY);
	//g_SoundManager.SetPrimaryBufferFormat(2,22050,16);

	ShowWindow( g_hWnd, SW_SHOW ) ;
	UpdateWindow( g_hWnd ) ;
	// ���콺 �Ⱥ��̰�~
	//ShowCursor(FALSE);

	///////////////////////////////////////////////////////////////////
	ZeroMemory(&msg, sizeof(MSG));
	//TRACE("REV ====== %s ========= \n\n", buffer);
	/////////// é�� �ʱ�ȭ /////////////////
	g_Mng.chap[LOGO] = new Logo;
	g_Mng.chap[MENU] = new Menu;
	g_Mng.chap[GAME] = new Game;
	g_Mng.chap[OVER] = new Over;
	g_Mng.chap[BATTLE] = new Battle;

	/////////////////////////////////////////

	for(int i=0; i<TOTALCHAP; i++)
		g_Mng.chap[i]->Init();

	while( msg.message != WM_QUIT )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			if(GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			
			static DWORD next_game_tick = GetTickCount();
			//static DWORD next_game_tick1 = GetTickCount();


			
			loops = 0;
		
			//static int aa;
			//bool b = false;

			while( GetTickCount64() > next_game_tick && loops < MAX_FRAMESKIP) 
			{
				interpolation = float(GetTickCount64() + SKIP_TICKS - next_game_tick ) / float( SKIP_TICKS );
				if(Gmanager.m_Pause == false) g_Mng.chap[g_Mng.n_Chap]->Update(interpolation);
				//if(b == false)
				//{
				//	aa = interpolation;
				//	b = true;
				//}
				g_Mng.chap[g_Mng.n_Chap]->OnMessage(&msg);
				next_game_tick += SKIP_TICKS;
				loops++;
			}

			

			dv_font.Device9->BeginScene();
			dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0, 0);


			g_Mng.chap[g_Mng.n_Chap]->Draw();

			dv_font.Device9->EndScene();
			dv_font.Device9->Present(NULL, NULL, NULL, NULL);
			
		}
	}

	return msg.wParam;

}

// Ű �ѹ��� �����Ŵ� ���Ⱑ ����...�ƴϸ� ������.(key.cpp ���� ����Ű �ȸ԰� �ϱ� ���� ������ ��������)
LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{

	case WM_DESTROY:
         PostQuitMessage( 0 );
         return 0;
	case WM_CHAR:
		 ch[0] = wParam;
		 strcat( buffer,ch);
		 // ���ڿ� ��ġ ������...
		 if (strstr(buffer, "p") != NULL)
		 {

			 if (GetTickCount64() - key.KeyTime > 200)
			 {
				 Gmanager.m_Pause = !Gmanager.m_Pause;

				 key.KeyTime = GetTickCount64();
			 }
		 }
		 else if (strstr(buffer, "s") != NULL) 
		 {
			 // ����Ÿ ���̽� ����
			 sql.save();
		 }

        ZeroMemory( &buffer, sizeof(buffer) );
		break;


	//case WM_COMM_RXCHAR:  //�ø��󿡼� �޴� �޼����� ���⸦ 
	//	 ch[0] = wParam;
	//	 strcat( buffer,ch);	
	//     TRACE("REV ====== %s ========= \n\n", buffer);




	}
	return DefWindowProc( g_hWnd, uMsg, wParam, lParam ) ;
}

/*

�Լ����� : char* strstr(char* str1, const char* str2);

0) ������� : C��� : <string.h> / C++ : <cstring>

1) str1���� str2�� ��ġ�ϴ� ���ڿ��� �ִ��� Ȯ���� �ϴ� �Լ�.

2) str1�� str2�� ���ڿ��� ��ġ�ϴ� ���ڿ��� ������ �ش� ��ġ�� ������(char* Ÿ��)�� ��ȯ.

3) �翬�ϰԵ� ��ġ�ϴ� ���ڿ��� ã�� ���ϸ� null pointer�� ��ȯ. (�׷��� ������ ��üũ�� ��! ���־�� ��.)

4) ���ڿ��� ã�Ƽ�, ���ڿ��� �ٲٴ� ��쿡�� ���� ���ڿ� str1�� �迭�� ���̸� �ݵ�� �����ؾ���. �迭�� ������ ������, ū���̴ϱ�.


*/