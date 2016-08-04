#pragma once

#include "Header.h"
#include "Test_controller.h"
#include "Student.h"
#include "TestName.h"

class Controller
{
	
public:
	Controller();
	~Controller();
	
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static Controller *ptr;
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify);
	void Cls_OnClose(HWND hWnd);	

	HWND hEdit1, hEdit2, hEdit3;
	HWND hButtonRegistr, hButtonStart, hButtonRedactor;	
	HWND hPicture;
	HWND hCombo1;
	HWND hList;
	HBITMAP hBitmap;
	
	
	int index;
	Student *student;
	int testNameCount;
	bool isRegOk;
	TCHAR lname[128];
	TCHAR fname[128];
	TCHAR group[32];
	TCHAR buff2[256];
	
	std::vector<TestName> tests;	
};