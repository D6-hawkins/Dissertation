#include "Application.h"
#include "../Game/Game.h"
#include <stdio.h>

//=================================================================
// Main functions to link to the windows OS
//=================================================================


//--------------------------------------------------------------------------------------
// Creates the window and opens the game code
//--------------------------------------------------------------------------------------
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	Application App;
	Game* myGame = nullptr;

	if (FAILED(App.InitWindow(hInstance, nCmdShow)))
		return 0;

	if (FAILED(App.InitDevice()))
	{
		App.CleanupDevice();
		return 0;
	}

	// Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

			if (App.Update()) //update next tick
			{
				App.Render();
			}
			else
			{
				break; //exits if exit message is recieved
			}
		}
	}

	App.CleanupDevice();

	return (int)msg.wParam;
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		// Note that this tutorial does not handle resizing (WM_SIZE) requests,
		// so we created the window without the resize border.

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
