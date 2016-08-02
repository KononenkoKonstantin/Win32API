#include "TestName.h"

TestName::TestName(int id, TCHAR &name, std::string &path)
{
	this->id = id;
	this->name = (TCHAR*)name;
	this->path = path;
}


TestName::~TestName()
{
}

std::ostream &operator<<(std::ostream os, TestName &tn)
{
	os << tn.id << " " << tn.name << " " << tn.path << std::endl;
	return os;
}