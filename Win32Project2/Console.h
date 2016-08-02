#pragma once
#include "Header.h"

class Console
{
	std::wofstream  consoleOut;

public:
	Console();
	~Console();

	void write(const std::wstring &_str);
	void write(const int &i);
	void write(const double &d);
	void write(const float &f);
	void write(const char &c);
	
};