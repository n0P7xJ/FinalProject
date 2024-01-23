#pragma once

#include <iostream>
#include <Windows.h>

class SystemTime
{
	int hour, minute, second;
	int day, month, year;
	SYSTEMTIME sTIME;
public:
	int GetHour() const { return hour; }
	int GetMinute() const { return minute; }
	int GetSecond() const { return second; }

	int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }

	SystemTime() : hour(sTIME.wHour), minute(sTIME.wMinute), second(sTIME.wSecond),
		day(sTIME.wDay), month(sTIME.wMonth), year(sTIME.wYear) {}

	void Output();
};