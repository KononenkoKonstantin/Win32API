#pragma once
#include "Header.h"

struct Date
{
	int day;
	int month;
	int year;
public:
	Date();
	~Date();
	Date(const Date &d);
	std::string getCurrentDate();

	friend std::ostream &operator<<(std::ostream &os, const Date &d);
};
