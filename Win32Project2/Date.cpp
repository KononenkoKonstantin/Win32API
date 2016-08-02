#include "Date.h"


Date::Date()
{
	this->getCurrentDate();
}

Date::~Date()
{
}

Date::Date(const Date &d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}
std::string Date::getCurrentDate()
{
	time_t current = time(NULL);
	tm ts;
	localtime_s(&ts, &current);
	this->day = ts.tm_mday;
	this->month = ts.tm_mon + 1;
	this->year = ts.tm_year + 1900;
	std::string tmp = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	return tmp;
}
std::ostream &operator<<(std::ostream &os, const Date &d)
{
	os << d.day << "." << d.month << "." << d.year << " ";
	return os;
}