#include "Student.h"


Student::Student()
{
	this->id = 0;
	this->test_id = 0;
	this->right = 0;
	this->wrong = 0;
	this->grade = 0;	

	this->lname = nullptr;
	this->fname = nullptr;
	this->group = nullptr;

	Date d;
	Time t;
	this->date = d.getCurrentDate();
	this->time = t.getCurrentTime();
}


Student::~Student(){}

Student::Student(int id, int test_id, int right, int wrong, int grade,
	TCHAR &lname, TCHAR &fname, TCHAR &group, std::string date, std::string time)
{
	this->id = id;
	this->test_id = test_id;
	this->right = right;
	this->wrong = wrong;
	this->grade = grade;

	this->lname = (TCHAR*)lname;
	this->fname = (TCHAR*)fname;
	this->group = (TCHAR*)group;
	Date d;
	Time t;
	this->date = d.getCurrentDate();
	this->time = t.getCurrentTime();
}

Student::Student(const Student &s)
{
	this->id = s.id;
	this->test_id = s.test_id;
	this->right = s.right;
	this->wrong = s.wrong;
	this->grade = s.grade;

	this->lname = (TCHAR*)s.lname;
	this->fname = (TCHAR*)s.fname;
	this->group = (TCHAR*)s.group;	
	this->date = s.date;
	this->time = s.time;
}

int Student::getId() const
{
	return this->id;
}
int Student::getTestId() const
{
	return this->test_id;
}
int Student::getRight() const
{
	return this->right;
}
int Student::getWrong() const
{
	return this->wrong;
}
int Student::getGrade() const
{
	return this->grade;
}
TCHAR &Student::getLname() const
{
	return *this->lname;
}
TCHAR &Student::getFname() const
{
	return *this->fname;
}
TCHAR &Student::getGroup() const
{
	return *this->group;
}
std::string Student::getDate() const
{
	return this->date;
}
std::string Student::getTime() const
{
	return this->time;
}
//Setters
void Student::setId(int id)
{
	this->id = id;
}
void Student::setTestId(int test_id)
{
	this->test_id = test_id;
}
void Student::setRight(int right)
{
	this->right += right;
}
void Student::setWrong(int wrong)
{
	this->wrong += wrong;
}
void Student::setGrade(int grade)
{
	this->grade += grade;
}
void Student::setLname(TCHAR &lname)
{
	this->lname = &lname;
}
void Student::setFname(TCHAR &fname)
{
	this->fname = &fname;
}
void Student::setGroup(TCHAR &group)
{
	this->group = &group;
}
void Student::setDate(std::string &date)
{
	this->date = date;	
}
void Student::setTime(std::string &time)
{
	this->time = time;	
}