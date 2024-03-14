#pragma once

#include <iostream>
#include <Windows.h>
#include <timezoneapi.h>
#include <stdexcept>

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

	int getDayOfWeek() const; //����� ��� ��������� ��� �����
	
	std::string getMonthName(const int&) const; //����� ��� ��������� ��'� �����

	int getDayOfWeekForFirstDayOfMonth(const int& month, const int& year) const; //����� ���� ������� ��������������� ������� ��� ����� �� ����������� ��������

	void OutputCLOCK(); //������� ��� ������ ���� �� ���� (��� � .��� ����)
};

int getMonthDay(const int& month, const int& year);