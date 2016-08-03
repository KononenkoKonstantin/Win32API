#include "Header.h"
#include "Time.h"



Time::Time()
{
	this->getCurrentTime();
}


Time::~Time()
{
}

Time::Time(const Time &t)
{
	this->hour = t.hour;
	this->min = t.min;
}
std::string Time::getCurrentTime()
{
	time_t current = time(NULL);
	tm ts;
	localtime_s(&ts, &current);
	this->hour = ts.tm_hour;
	this->min = ts.tm_min;
	std::string h1, m1;
	(hour < 10) ? h1 = "0" + std::to_string(hour) : h1 = std::to_string(hour);
	(min < 10) ? m1 = "0" + std::to_string(min) : m1 = std::to_string(min);
	return h1 + ":" + m1;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
	os << t.hour << ":" << t.min;
	return os;
}