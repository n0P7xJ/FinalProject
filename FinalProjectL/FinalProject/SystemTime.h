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
	int getMonth() const;	//	три гетера для отримання дня, місяця, року
	int getYear() const;

	SystemTime() {
		GetSystemTime(reinterpret_cast<SYSTEMTIME*>(this)); //конструктор отримання цьогошеього дня по системного часу
	}

	int getDayOfWeek() const; //метод для отримання неть тижня
	
	std::string getMonthName(const int&) const; //метод для отримання ім'я місяця

	void OutputCLOCK(); //функція для виводу часу та дати (тіло в .срр файлі)
};

int getMonthDay(const SystemTime& sysTime = SystemTime());