#pragma once
#include "Header.h"
#include "Student.h"
#include "Test.h"


class Result_controller
{
	void SaveData();
public:
	Result_controller();		
	Result_controller(Student &student);
	~Result_controller();

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static Result_controller *ptr;
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify);
	void Cls_OnClose(HWND hWnd);

	HWND hList1;
	HWND hButton1, hButton2;

	void setStudent(Student &student);
	Student student;
	TCHAR buff[512];
	TCHAR buff1[256];
	TCHAR buff2[256];
	TCHAR buff3[256];
	TCHAR buff4[256];
	TCHAR buff5[256];
	TCHAR buff6[256];
	TCHAR buff7[256];
	TCHAR buff8[256];
	TCHAR buff9[256];
	TCHAR buff10[256];
	TCHAR grade[16];
	TCHAR right[16];
	TCHAR wrong[16];
	
	char testname[256];
	char lname[64];
	char fname[64];
	char group[32];
	std::string path;	
	Console console;
};

