#pragma once
#include "Header.h"
#include "Student.h"
#include "Test.h"
#include "Result_controller.h"

class Test_controller
{
public:
	Test_controller();	
	Test_controller(Student &student, std::string path);
	~Test_controller();

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static Test_controller *ptr; 
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify);
	void Cls_OnTimer(HWND hWnd, UINT id);
	void Cls_OnClose(HWND hWnd);
	
	HWND hEdit1, hEdit2, hEdit3, hEdit4, hEdit5, hEdit6;
	HWND hStatic2, hStatic6, hStatic8;
	HWND hProgress1;
	HWND hRadio1, hRadio2, hRadio3, hRadio4, hRadio5;
	HWND hButton1;
	HWND hWnd3;
	
	int count, min, sec, numOfAnswers, rightAnsCount;
	TCHAR buff[512];
	TCHAR buff1[8];
	std::string path;
	Test *test;
	Student student;
	Question question;
	Result_controller rc;
	static int currentQuest;
	static float position;	
};

