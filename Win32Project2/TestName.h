#pragma once
#include "Header.h"
struct TestName
{
	int id;
	std::string name;
	std::string path;

	TestName(int id, std::string &name, std::string &path);
	TestName(const TestName &tn);
	~TestName();
	
};

