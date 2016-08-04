#pragma once
#include "Header.h"
#include "Date.h"
#include "Time.h"

class Student
{
	int id;
	std::string testName;
	int right;
	int wrong;
	int grade;

	TCHAR *lname;
	TCHAR *fname;
	TCHAR *group;
	std::string date;
	std::string time;
public:
	Student();	
	Student(int id, std::string testName, int right, int wrong, int grade, TCHAR &lname, TCHAR &fname,
				TCHAR &group, std::string date, std::string time);
	Student(const Student &s);
	~Student();
	
	int getId() const;
	std::string getTestName() const;
	int getRight() const;
	int getWrong() const;
	int getGrade() const;
	TCHAR &getLname() const;
	TCHAR &getFname() const;
	TCHAR &getGroup() const;
	std::string getDate() const;
	std::string getTime() const;
	
	void setId(int id);
	void setTestName(std::string testName);
	void setRight(int right);
	void setWrong(int wrong);
	void setGrade(int grade);
	void setLname(TCHAR &lname);
	void setFname(TCHAR &fname);
	void setGroup(TCHAR &group);
	void setDate(std::string &date);
	void setTime(std::string &time);
};

