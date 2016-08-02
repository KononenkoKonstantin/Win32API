#pragma once

#include "Header.h"
#include "Test_controller.h"
#include "Student.h"
#include "TestName.h"

class Controller
{
	TCHAR lname[512];
	TCHAR fname[512];
	TCHAR group[512];
	std::vector<TestName> tests;
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
	HWND hWnd2;
	
	int index;
	Student *student;
	int testNameCount;
	bool isRegOk;
	
	//Console console;

};