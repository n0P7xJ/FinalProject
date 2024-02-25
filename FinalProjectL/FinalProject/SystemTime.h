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
	int getMonth() const;	//	три гетера для отримання дня, місяця, року
	int getYear() const;

	SystemTime() {
		GetSystemTime(reinterpret_cast<SYSTEMTIME*>(this)); //конструктор отримання цьогошеього дня по системного часу
	}

	int getDayOfWeek() const; //метод для отримання дня тижня
	
	std::string getMonthName(const int&) const; //метод для отримання ім'я місяця

	int getDayOfWeekForFirstDayOfMonth() const; //метод який повертає місцезнаходження першого дня місяця за календарним порядком

	void OutputCLOCK(); //функція для виводу часу та дати (тіло в .срр файлі)
};

int getMonthDay(const SystemTime& sysTime = SystemTime());