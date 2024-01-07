#pragma once

#include <iostream>
#include <Windows.h>

class SystemTime : protected SYSTEMTIME{
public:
	int getHour() const;
	/*int GetMinute() const { return minute; }
	int GetSecond() const { return second; }

	int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }*/

	void Output();
};