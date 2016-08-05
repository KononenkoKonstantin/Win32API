#include "Test_constructor_controller.h"

Test_constructor_controller *Test_constructor_controller::ptr = nullptr;

int Test_constructor_controller::currentQuest = 0;
//int Test_constructor_controller::count = 0;

Test_constructor_controller::Test_constructor_controller()
{
	ptr = this;
	this->indexRadio = 0;
	this->count = 0;
	this->rightAns = 0;		
	this->isNameWrite = false;
	this->path1 = "Data/TestsList.txt";	
}


Test_constructor_controller::~Test_constructor_controller()
{
}

void Test_constructor_controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}

BOOL Test_constructor_controller::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{
	hStatic2 = GetDlgItem(hWnd, IDC_STATIC2);

	hEditName = GetDlgItem(hWnd, IDC_EDIT1);
	hEditQuest = GetDlgItem(hWnd, IDC_EDIT6);
	hEditWeight = GetDlgItem(hWnd, IDC_EDIT7);
	hEditAns1 = GetDlgItem(hWnd, IDC_EDIT2); 
	hEditAns2 = GetDlgItem(hWnd, IDC_EDIT3);
	hEditAns3 = GetDlgItem(hWnd, IDC_EDIT8);
	hEditAns4 = GetDlgItem(hWnd, IDC_EDIT9); 
	hEditAns5 = GetDlgItem(hWnd, IDC_EDIT4);

	hButtonNext = GetDlgItem(hWnd, IDC_BUTTON3);

	hRadio1 = GetDlgItem(hWnd, IDC_RADIO1);
	hRadio2 = GetDlgItem(hWnd, IDC_RADIO2);
	hRadio3 = GetDlgItem(hWnd, IDC_RADIO3);
	hRadio4 = GetDlgItem(hWnd, IDC_RADIO4);
	hRadio5 = GetDlgItem(hWnd, IDC_RADIO6);

	
	SetWindowText(hEditQuest, L"");
	SetWindowText(hEditWeight, L"");
	SetWindowText(hEditAns1, L"");
	SetWindowText(hEditAns2, L"");
	SetWindowText(hEditAns3, L"");
	SetWindowText(hEditAns4, L"");
	SetWindowText(hEditAns5, L"");

	SendMessage(hRadio1, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio2, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio3, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio4, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
	SendMessage(hRadio5, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);

	swprintf_s(buffNum, L"%d", this->currentQuest + 1);
	SetWindowText(hStatic2, buffNum);

	return TRUE;
}

void Test_constructor_controller::Cls_OnCommand(HWND hWnd, int id, HWND hCtl, UINT codeNotify)
{
	USES_CONVERSION;

	if (id == IDC_BUTTON3)
	{
		EnableWindow(hEditName, FALSE);
		int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
		r1 = SendMessage(hRadio1, BM_GETCHECK, 0, 0);
		r2 = SendMessage(hRadio2, BM_GETCHECK, 0, 0);
		r3 = SendMessage(hRadio3, BM_GETCHECK, 0, 0);
		r4 = SendMessage(hRadio4, BM_GETCHECK, 0, 0);
		r5 = SendMessage(hRadio5, BM_GETCHECK, 0, 0);

		GetWindowText(hEditName, name, 512);
		GetWindowText(hEditQuest, quest, 1024);
		GetWindowText(hEditWeight, weight, 16);
		GetWindowText(hEditAns1, buff1, 512);
		GetWindowText(hEditAns2, buff2, 512);
		GetWindowText(hEditAns3, buff3, 512);
		GetWindowText(hEditAns4, buff4, 512);
		GetWindowText(hEditAns5, buff5, 512);

		
		int index[5];
		(r1) ? (index[0] = 1, indexRadio = 1) : index[0] = 0;
		(r2) ? (index[1] = 2, indexRadio = 2) : index[1] = 0;
		(r3) ? (index[2] = 3, indexRadio = 3) : index[2] = 0;
		(r4) ? (index[3] = 4, indexRadio = 4) : index[3] = 0;
		(r5) ? (index[4] = 5, indexRadio = 5) : index[4] = 0;

		if (lstrlen(name) == 0 || lstrlen(quest) == 0 || lstrlen(weight) == 0 || lstrlen(buff1) == 0 || lstrlen(buff2) == 0
			|| lstrlen(buff3) == 0 || lstrlen(buff4) == 0 || lstrlen(buff5) == 0)
		{
			MessageBox(hWnd, L"Вы заполнили не все поля", L"", MB_OK);
		}
		else
		{
			if (!indexRadio)
			{
				MessageBox(hWnd, L"Выберите правильный ответ", L"", MB_OK);
			}
			else
			{
				if (!count)
				{
					std::string buf;
					std::ifstream fin;
					fin.open(this->path1.c_str(), std::ios_base::in);
					if (!fin.is_open())
					{
						MessageBox(hWnd, L"Ошибка, не могу открыть файл TestsList", L"", MB_OK);
					}
					else
					{
						while (!fin.eof())
						{
							std::getline(fin, buf);
							count++;
						}
					}
					fin.close();
				}
				
				if (!isNameWrite)
				{
					std::ofstream fout;
					fout.open(this->path1.c_str(), std::ios_base::app);
					{
						if (!fout.is_open())
						{
							MessageBox(hWnd, L"Ошибка, не могу открыть файл TestsList для записи", L"", MB_OK);
							fout.close();
						}
						else
						{
							fout << "\n" 
								<< (count + 1)
								<< " - Тест по "
								<< T2A(name);
							fout.close();
							this->isNameWrite = true;
						}
					}
					
				}
				std::string tmp;
				(count < 10) ? (tmp = "0" + std::to_string(count + 1)) : (tmp = std::to_string(count + 1));
				path2 = "Data/" + tmp + ".txt";

				
				std::ofstream fout1;
				fout1.open(path2.c_str(), std::ios_base::app);
				if (!fout1.is_open())
				{
					MessageBox(hWnd, L"Ошибка, не могу открыть файл 1", L"", MB_OK);
				}
				else
				{
					
					fout1 << '#' << this->currentQuest+1 << "\n"
						<< T2A(quest) << "\n"
						<< T2A(weight) << "\n"
						<< T2A(buff1) << "\n"
						<< T2A(buff2) << "\n"
						<< T2A(buff3) << "\n"
						<< T2A(buff4) << "\n"
						<< T2A(buff5) << "\n"
						<< indexRadio << std::endl;
				}
				fout1.close();

				if ((this->currentQuest + 1) < maxQuest)
				{
					++this->currentQuest;
					SendMessage(hWnd, WM_INITDIALOG, 0, 0);
				}
				else
				{
					MessageBox(hWnd, L"Тест создан", L"", MB_OK);					
					EndDialog(hWnd, 0);
				}
			}
		}
	}
}

BOOL CALLBACK Test_constructor_controller::DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}