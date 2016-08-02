#include "Result_controller.h"

Result_controller *Result_controller::ptr = nullptr;

Result_controller::Result_controller()
{
	ptr = this;
}


Result_controller::~Result_controller()
{	
}

Result_controller::Result_controller(Student &student)
{
	ptr = this;
	this->student = student;	
	this->path = "Data/Resulsts/" + std::to_string(student.getFname()) + "_" + std::to_string(student.getGroup())
		+ "_" + student.getDate() + ".txt";
	this->SaveData();
}

void Result_controller::SaveData()
{
	USES_CONVERSION;
	char lname[64];
	char fname[64];
	char group[32];	
		
	strcpy_s(lname, T2A(&student.getLname()));
	strcpy_s(fname, T2A(&student.getFname()));
	strcpy_s(group, T2A(&student.getGroup()));	

	std::ofstream fout;
	fout.open(this->path.c_str(), std::ios_base::out);
	if (!fout.is_open())
	{
		fout.close();
	}
	else
	{
		fout
			<< "Фамилия: " << this->student.getLname() << "\n"
			<< "Имя    : " << this->student.getFname() << "\n"
			<< "Группа : " << this->student.getGroup() << "\n"
			<< "Баллы  : " << this->student.getGrade() << "\n"
			<< "Верно  : " << this->student.getRight() << "\n"
			<< "Ошибки : " << this->student.getWrong() << "\n"
			<< "Дата  : " << this->student.getDate() << std::endl;
	}
	fout.close();
}

void Result_controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}

void Result_controller::setStudent(Student &student)
{
	this->student = student;
}
BOOL Result_controller::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{
	USES_CONVERSION;

	hList1 = GetDlgItem(hWnd, IDC_LIST1);
	hButton1 = GetDlgItem(hWnd, IDC_BUTTON1);
	hButton2 = GetDlgItem(hWnd, IDC_BUTTON2);

	wsprintf(this->buff1, L"Фамилия: ");
	lstrcat(this->buff1, &this->student.getLname());

	wsprintf(this->buff2, L"Имя         : ");
	lstrcat(this->buff2, &this->student.getFname());

	wsprintf(this->buff3, L"Группа   : ");
	lstrcat(this->buff3, &this->student.getGroup());

	TCHAR grade[16];
	wsprintf(this->buff4, L"Баллы    : ");
	swprintf_s(grade, L"%d", this->student.getGrade());
	lstrcat(this->buff4, grade);
		
	TCHAR right[16];
	wsprintf(this->buff5, L"Правильных ответов   : ");
	swprintf_s(right, L"%d", this->student.getRight());
	lstrcat(this->buff5, right);

	TCHAR wrong[16];
	wsprintf(this->buff6, L"Неправильных ответов : ");
	swprintf_s(wrong, L"%d", this->student.getWrong());
	lstrcat(this->buff6, wrong);
	wsprintf(this->buff7, L"Дата теста : ");
	lstrcat(this->buff7, A2T(this->student.getDate().c_str()));
	console.write(A2T(this->student.getDate().c_str()));

	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff1);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff2);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff3);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)L"---------------------------------");
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff4);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)L"---------------------------------");
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff5);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff6);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)L"---------------------------------");
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff7);
	return TRUE;
}

void Result_controller::Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDC_BUTTON1:
		EndDialog(hWnd, 0);
		break;
	case IDC_BUTTON2:

		break;
	}
}

BOOL CALLBACK Result_controller::DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}