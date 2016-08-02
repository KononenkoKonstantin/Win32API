#include "Controller.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	Controller c;

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Controller::DlgProc);
}