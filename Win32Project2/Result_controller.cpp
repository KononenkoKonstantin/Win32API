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
	USES_CONVERSION;
	ptr = this;
	this->student = student;
	char *lname = T2A(&student.getLname());
	char *group = T2A(&student.getGroup());
	
	
	
	this->path = "Data/Resulsts/" + std::to_string(*lname) + "_" + std::to_string(*group)
		+ "_" + student.getDate() + ".txt";
	//wsprintf(buff, L"%S", path.c_str());
	console.write(*T2A(&student.getFname()));
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
		fout << "�������: " << this->student.getLname() << "\n"
			<< "���    : " << this->student.getFname() << "\n"
			<< "������ : " << this->student.getGroup() << "\n"
			<< "�����  : " << this->student.getGrade() << "\n"
			<< "���������� �������   : " << this->student.getRight() << "\n"
			<< "������������ ������� : " << this->student.getWrong() << "\n"
			<< "���� : " << this->student.getDate() << std::endl;
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
	hList1 = GetDlgItem(hWnd, IDC_LIST1);
	hButton1 = GetDlgItem(hWnd, IDC_BUTTON1);
	hButton2 = GetDlgItem(hWnd, IDC_BUTTON2);

	wsprintf(this->buff1, L"�������: ");
	lstrcat(this->buff1, &this->student.getLname());

	wsprintf(this->buff2, L"���         : ");
	lstrcat(this->buff2, &this->student.getFname());

	wsprintf(this->buff3, L"������   : ");
	lstrcat(this->buff3, &this->student.getGroup());
	
	wsprintf(this->buff4, L"�����    : ");
	swprintf_s(grade, L"%d", this->student.getGrade());
	lstrcat(this->buff4, grade);		
	
	wsprintf(this->buff5, L"���������� �������   : ");
	swprintf_s(right, L"%d", this->student.getRight());
	lstrcat(this->buff5, right);
	
	wsprintf(this->buff6, L"������������ ������� : ");
	swprintf_s(wrong, L"%d", this->student.getWrong());
	lstrcat(this->buff6, wrong);
	wsprintf(this->buff7, L"���� ����� : ");
	wsprintf(buff8, L"%S", this->student.getDate().c_str());
	lstrcat(this->buff7, this->buff8);
	

	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff1);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff2);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff3);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)L"\r\r");
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff4);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff5);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)&buff6);
	SendMessage(hList1, LB_ADDSTRING, 0, (LPARAM)L"\r");
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