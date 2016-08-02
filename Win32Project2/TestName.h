#pragma once
#include "Header.h"
struct TestName
{
	int id;
	TCHAR *name;
	std::string path;

	TestName(int id, TCHAR &name, std::string &path);
	~TestName();

	friend std::ostream &operator<<(std::ostream os, TestName &tn);
};

