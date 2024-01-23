#pragma once

#include <iostream>
#include <Windows.h>

class SystemTime : public SYSTEMTIME
{
	SYSTEMTIME sTIME;
public:
	int getDay() const;
	int getMonth() const;	//	��� ������ ��� ��������� ���, �����, ����
	int getYear() const;

	SystemTime() {
		GetSystemTime(reinterpret_cast<SYSTEMTIME*>(this)); //����������� ��������� ����������� ��� �� ���������� ����
	}

	int getMonthDays() const {
		SYSTEMTIME lastDayOfMonth = *this;
		lastDayOfMonth.wDay = SYSTEMTIME::wDay;
		lastDayOfMonth.wHour = lastDayOfMonth.wMinute = lastDayOfMonth.wSecond = lastDayOfMonth.wMilliseconds = 0;

		FILETIME ft;
		SystemTimeToFileTime(&lastDayOfMonth, &ft);
		FileTimeToSystemTime(&ft, &lastDayOfMonth);

		return lastDayOfMonth.wDay;
	} 
	// ������������ ���� ���� ��������� ��������� ��� � ̲����

	void OutputCLOCK(); //������� ��� ������ ���� �� ���� (��� � .��� ����)
};