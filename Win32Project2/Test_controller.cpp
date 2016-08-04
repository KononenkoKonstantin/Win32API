#include "Test_controller.h"

Test_controller *Test_controller::ptr = nullptr;

int Test_controller::currentQuest = 0;
float Test_controller::position = 0.0;

Test_controller::Test_controller()
{
	ptr = this;
	this->test = new Test();
	this->count = 0;
	this->min = 0;
	this->sec = 0;	
	this->rightAnsCount = 0;
	this->numOfAnswers = 5;
}

Test_controller::Test_controller(Student &student, std::string path)
{
	ptr = this;
	this->test = new Test(student, path);
	this->count = 10;
	this->min = 5;
	this->sec = 0;
	this->path = path;
	this->student = student;	
	this->rightAnsCount = 0;
	this->numOfAnswers = 5;	
}

Test_controller::~Test_controller()
{
}

void Test_controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}

BOOL Test_controller::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{	
	hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);
	hEdit2 = GetDlgItem(hWnd, IDC_EDIT2);
	hEdit3 = GetDlgItem(hWnd, IDC_EDIT3);
	hEdit4 = GetDlgItem(hWnd, IDC_EDIT4);
	hEdit5 = GetDlgItem(hWnd, IDC_EDIT5);
	hEdit6 = GetDlgItem(hWnd, IDC_EDIT6);

	hStatic2 = GetDlgItem(hWnd, IDC_STATIC2);
	hStatic6 = GetDlgItem(hWnd, IDC_STATIC6);
	hStatic8 = GetDlgItem(hWnd, IDC_STATIC8);

	hProgress1 = GetDlgItem(hWnd, IDC_PROGRESS1);
	hRadio1 = GetDlgItem(hWnd, IDC_RADIO1);
	hRadio2 = GetDlgItem(hWnd, IDC_RADIO2);
	hRadio3 = GetDlgItem(hWnd, IDC_RADIO3);
	hRadio4 = GetDlgItem(hWnd, IDC_RADIO4);
	hRadio5 = GetDlgItem(hWnd, IDC_RADIO5);

	SendMessage(hProgress1, PBM_SETPOS, 0, 0);
		
	SetTimer(hWnd, 1, 1000, NULL);

	(min<10) ? swprintf_s(buff, TEXT("0%d"), min) : swprintf_s(buff, TEXT("%d"), min);
	SetWindowText(hStatic6, buff);
	(sec<10) ? swprintf_s(buff, TEXT("0%d"), sec) : swprintf_s(buff, TEXT("%d"), sec);
	SetWindowText(hStatic8, buff);

	question = test->getQuestion(currentQuest);		
	SetWindowText(hEdit6, &question.getText());
	
	swprintf_s(buff1, L"%d", this->currentQuest + 1);
	SetWindowText(hStatic2, buff1);

	SetWindowText(hEdit1, &question.getAnswerByIndex(0).getText());
	SetWindowText(hEdit2, &question.getAnswerByIndex(1).getText());
	SetWindowText(hEdit3, &question.getAnswerByIndex(2).getText());
	SetWindowText(hEdit4, &question.getAnswerByIndex(3).getText());
	SetWindowText(hEdit5, &question.getAnswerByIndex(4).getText());
	
	SendMessage(hRadio1, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio2, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio3, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio4, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio5, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);	

	return TRUE;
}

void Test_controller::Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify)
{	
	bool isRight = false;
	std::vector<Answer> ans(question.getAnswers());	

	int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
	r1 = SendMessage(hRadio1, BM_GETCHECK, 0, 0);
	r2 = SendMessage(hRadio2, BM_GETCHECK, 0, 0);
	r3 = SendMessage(hRadio3, BM_GETCHECK, 0, 0);
	r4 = SendMessage(hRadio4, BM_GETCHECK, 0, 0);
	r5 = SendMessage(hRadio5, BM_GETCHECK, 0, 0);

	position = (float)currentQuest / (float)this->count * 100;
	SendMessage(hProgress1, PBM_SETPOS, (WPARAM)position, 0);

	if (id == IDC_BUTTON1)
	{
		if (r1)
		{			
			if (question.getRightAnswerNum() == ans[0].getId())
			{				
				isRight = true;
			}			
		}
		if (r2)
		{
			if (question.getRightAnswerNum() == ans[1].getId())
			{				
				isRight = true;
			}
		}
		if (r3)
		{
			if (question.getRightAnswerNum() == ans[2].getId())
			{				
				isRight = true;
			}
		}
		if (r4)
		{
			if (question.getRightAnswerNum() == ans[3].getId())
			{				
				isRight = true;
			}
		}
		if (r5)
		{
			if (question.getRightAnswerNum() == ans[4].getId())
			{				
				isRight = true;
			}
		}
		if (isRight)
		{
			student.setGrade(question.getWeight());
			student.setRight(1);
		}
		else
		{
			student.setWrong(1);
		}
		
		if ((this->currentQuest+1) < count)
		{
			++this->currentQuest;
			SendMessage(hWnd, WM_INITDIALOG, 0, 0);
		}
		else
		{		
			KillTimer(hWnd, 1);
			EndDialog(hWnd, 0);
			min = 5;
			SendMessage(hProgress1, PBM_SETPOS, 0, 0);
			rc.setStudent(student);
			DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, Result_controller::DlgProc);			
		}
		

	}
}

void Test_controller::Cls_OnTimer(HWND hWnd, UINT id)
{		
	
	if (sec > 0)
	{
		sec--;
	}
	else
	{
		if (min > 0)
		{
			min--;
			sec = 59;
		}
		else
		{
			KillTimer(hWnd, 1);
			MessageBox(hWnd, L"Время истекло", L"", MB_OK);
			position = 0;
			EndDialog(hWnd, 0);
			rc.setStudent(student);
			DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, Result_controller::DlgProc);
		}		
	}
	(min<10) ? swprintf_s(buff, TEXT("0%d"), min) : swprintf_s(buff, TEXT("%d"), min);
	SetWindowText(hStatic6, buff);
	(sec<10) ? swprintf_s(buff, TEXT("0%d"), sec) : swprintf_s(buff, TEXT("%d"), sec);
	SetWindowText(hStatic8, buff);
}

BOOL CALLBACK Test_controller::DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_TIMER, ptr->Cls_OnTimer);
	}
	return FALSE;
}