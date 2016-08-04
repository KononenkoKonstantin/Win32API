#include "TestName.h"

TestName::TestName(int id, std::string &name, std::string &path)
{
	this->id = id;
	this->name = name;
	this->path = path;
}

TestName::TestName(const TestName &tn)
{
	this->id = tn.id;
	this->name = tn.name;
	this->path = tn.path;
}

TestName::~TestName()
{
}

