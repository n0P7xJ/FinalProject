#pragma once

#include <iostream>
#include <Windows.h>

class SystemTime : public SYSTEMTIME{
public:
	int getHour() const;
	int getMinute() const;
	int getSecond() const;


	/*int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }*/

	void Output();
};