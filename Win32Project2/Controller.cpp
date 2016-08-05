#include "Controller.h"


Controller *Controller::ptr = nullptr;

Controller::Controller()
{
	ptr = this;
	this->index = 0;
	this->student = new Student();
	this->testNameCount = 0;
	this->isRegOk = false;
}

Controller::~Controller() {}

void Controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}

BOOL Controller::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{		
	hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);
	hEdit2 = GetDlgItem(hWnd, IDC_EDIT2);
	hEdit3 = GetDlgItem(hWnd, IDC_EDIT3);
	hButtonRegistr = GetDlgItem(hWnd, IDC_BUTTON1);
	hButtonStart = GetDlgItem(hWnd, IDC_BUTTON2);
	hButtonRedactor = GetDlgItem(hWnd, IDC_BUTTON3);
	hPicture = GetDlgItem(hWnd, IDC_STATIC6);
	hCombo1 = GetDlgItem(hWnd, IDC_COMBO1);
	hList = GetDlgItem(hWnd, IDC_LIST2);

	hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));
	SendMessage(hPicture, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBitmap));	
	
	std::string path = "Data/TestsList.txt";	
	
	std::ifstream fin;
	fin.open(path.c_str(), std::ios_base::in);
	if (!fin.is_open())
	{
		MessageBox(hWnd, L"Can not open file TestsList.txt", L"", MB_OK);
		EndDialog(hWnd, 0);
	}
	else
	{
		int pos1;
		std::string buff;
		std::string delim = "-";
		std::string num;
		std::string text;
		
		while (!fin.eof())
		{	
			std::getline(fin, buff);
			pos1 = buff.find(delim);
			num = buff.substr(0, pos1);
			text = buff.substr(pos1 + 2, (buff.size() - pos1));

			wsprintf(buff2, L"%S", text.c_str());
			
			EnableWindow(hButtonStart, FALSE);
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)(buff2));
			SendMessage(hCombo1, CB_SETCURSEL, 0, 0);				
			
			int id = testNameCount + 1;
			std::string ids;
			(id < 10)? (ids = "0" + std::to_string(id)) : (ids = std::to_string(id));
			std::string path1 = "Data/";
			std::string path2 = ".txt";
			std::string path3 = path1 + ids + path2;			
			
			TestName testName(id, text, path3);
			tests.push_back(testName);			
			this->testNameCount++;			
		}
	}	
	return TRUE;
}

void Controller::Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify)
{	
	USES_CONVERSION;
	switch (id)
	{
	case IDC_BUTTON1:
	{		
		GetWindowText(hEdit1, lname, 512);		
		GetWindowText(hEdit2, fname, 512);		
		GetWindowText(hEdit3, group, 512);
		this->student->setLname(*lname);
		this->student->setFname(*fname);
		this->student->setGroup(*group);
				
		if (lstrlen(lname) == 0 || lstrlen(fname) == 0 || lstrlen(group) == 0)
		{
			MessageBox(hWnd, L"Вы заполнили не все поля", L"", MB_OK);
		}
		else
		{
			isRegOk = true;
			EnableWindow(hButtonRegistr, FALSE);
		}
		break;
	}
	case IDC_BUTTON2:
	{
		if (!isRegOk)
		{
			MessageBox(hWnd, L"Вы не зарегистрировались", L"", MB_OK);
		}
		else
		{			
			
			this->student->setTestName(tests[index].name);			
			Test_controller tc(*student, tests[index].path);				
			DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Test_controller::DlgProc);			
		}
		break;
	}
	case IDC_BUTTON3:
	{
		Test_constructor_controller tcc;
		DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG4), hWnd, Test_constructor_controller::DlgProc);
		break;
	}
	case IDC_COMBO1:
	{
		index = SendMessage(hCombo1, CB_GETCURSEL, 0, 0);
		EnableWindow(hButtonStart, TRUE);		
		break;
	}
	}
}


BOOL CALLBACK Controller::DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);		
	}
	return FALSE;
}