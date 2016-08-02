#include "Console.h"

Console::Console()
{
	AllocConsole();
	consoleOut.open(L"CONOUT$");
	std::wcout.rdbuf(consoleOut.rdbuf());
	std::wcout.imbue(std::locale("rus_rus.866"));  // для кириллицы
}


Console::~Console()
{
	FreeConsole();
}

//void Console::write(const std::wstring &_str) { std::wcout << _str << std::endl; }
void Console::write(const int &i)             { std::wcout << i << std::endl; }
void Console::write(const double &d)          { std::wcout << d << std::endl; }
void Console::write(const float &f)			  { std::wcout << f << std::endl; }
void Console::write(const char &c)			  { std::wcout << c << std::endl; }
void Console::write(const std::wstring _str1) { std::wcout << _str1 << std::endl; }