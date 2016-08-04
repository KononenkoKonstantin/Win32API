#include "Date.h"


Date::Date()
{
	this->getCurrentDate();
}

Date::Date(const Date &d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

Date::~Date() {}

std::string Date::getCurrentDate()
{
	time_t current = time(NULL);
	tm ts;
	localtime_s(&ts, &current);
	this->day = ts.tm_mday;
	this->month = ts.tm_mon + 1;
	this->year = ts.tm_year + 1900;
	std::string d1;
	std::string m1;
	(day < 10) ? d1 = "0" + std::to_string(day) : d1 = std::to_string(day);
	(month < 10) ? m1 = "0" + std::to_string(month) : d1 = std::to_string(month);
	
	return (d1 + "." + m1 + "." + std::to_string(year));
}
std::ostream &operator<<(std::ostream &os, const Date &d)
{
	os << d.day << "." << d.month << "." << d.year << " ";
	return os;
}