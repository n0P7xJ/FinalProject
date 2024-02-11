#pragma once

#include <iostream>
#include <Windows.h>
//#include "Calendar.h"

class SystemTime : public SYSTEMTIME
{
	SYSTEMTIME sTIME;
	//Calendar calendar;
public:
	int getDay() const;
	int getMonth() const;	//	��� ������ ��� ��������� ���, �����, ����
	int getYear() const;

	SystemTime() {
		GetSystemTime(reinterpret_cast<SYSTEMTIME*>(this)); //����������� ��������� ����������� ��� �� ���������� ����
	}

	int getDayOfWeek() const; //����� ��� ��������� ���� �����
	
	std::string getMonthName(const int&) const; //����� ��� ��������� ��'� �����

	void OutputCLOCK(); //������� ��� ������ ���� �� ���� (��� � .��� ����)
};

int getMonthDay(const SystemTime& sysTime = SystemTime());