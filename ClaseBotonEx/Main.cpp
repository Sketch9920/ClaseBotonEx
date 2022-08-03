#include <Windows.h>
#include "ClaseBotonEx.h"

HWND hwndWinMain;
HINSTANCE hInstMain;
char szMain[] = "test";

#define MY_BOTON 1001
ClaseBotonEx Bt;

LRESULT CALLBACK WinMainProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	hInstMain = hInstance;
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC; //CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WinMainProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstMain;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(0, 60, 100));//GetSysColorBrush(COLOR_BTNFACE); //  CreateSolidBrush(RGB(0,0,0));
	wc.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szMain;
	wc.hIconSm = NULL;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Error registrando clase", "Mensage", MB_OK);
		return 0;
	}

	hwndWinMain = CreateWindow(szMain, "Main", WS_OVERLAPPEDWINDOW /*| WS_CLIPCHILDREN*/, 80, 10, 500, 500, NULL, NULL, hInstance, NULL);
	
	Bt.Crear(hwndWinMain, "Boton", 10, 10, 70, 18, (HMENU)MY_BOTON, NULL, NULL);
	Bt.Visible(true);
	
	
	UpdateWindow(hwndWinMain);
	ShowWindow(hwndWinMain, SW_NORMAL);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK WinMainProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{

		}break;
		case WM_COMMAND:
		{
			switch (wParam)
			{
				case MY_BOTON:
					MessageBox(hwnd, "Boton Presionado", "", MB_OK);
					break;
			}

			
		}break;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}	

