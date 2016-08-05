#pragma once
#include "Header.h"
#include "Question.h"

class Test_constructor_controller
{
public:
	Test_constructor_controller();
	~Test_constructor_controller();

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static Test_constructor_controller *ptr;
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify);
	void Cls_OnClose(HWND hWnd);

	HWND hStatic2;
	HWND hEditName, hEditQuest, hEditWeight, hEditAns1, hEditAns2, hEditAns3, hEditAns4, hEditAns5;
	HWND hButtonNext;
	HWND hRadio1, hRadio2, hRadio3, hRadio4, hRadio5;

	TCHAR name[512];
	TCHAR quest[1024];
	TCHAR weight[16];
	TCHAR buff1[512];
	TCHAR buff2[512];
	TCHAR buff3[512];
	TCHAR buff4[512];
	TCHAR buff5[512];
	TCHAR buffNum[16];
		
	int rightAns;
	int indexRadio;	
	bool isNameWrite;
	std::string path1;
	std::string path2;
	const int maxQuest = 10;
	static int currentQuest;
	int count;
};

