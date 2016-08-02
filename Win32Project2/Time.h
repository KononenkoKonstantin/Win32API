#pragma once

struct Time
{
	int hour;
	int min;
public:
	Time();
	~Time();
	Time(const Time &t);
	std::string getCurrentTime();

	friend std::ostream &operator<<(std::ostream &os, const Time &t);
};
