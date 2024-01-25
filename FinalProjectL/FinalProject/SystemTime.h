#pragma once

#include <iostream>
#include <Windows.h>

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

	int getMonthDays() const {
		SYSTEMTIME lastDayOfMonth = *this;
		lastDayOfMonth.wDay = SYSTEMTIME::wDay;
		lastDayOfMonth.wHour = lastDayOfMonth.wMinute = lastDayOfMonth.wSecond = lastDayOfMonth.wMilliseconds = 0;

		FILETIME ft;
		SystemTimeToFileTime(&lastDayOfMonth, &ft);
		FileTimeToSystemTime(&ft, &lastDayOfMonth);

		return lastDayOfMonth.wDay;
	} 
	// НЕДОРОБЛЕНИЙ БЕТА ТЕСТ ОТРИМАННЯ ОСТАНЬОГО ДНЯ З МІСЯЦЯ

	void OutputCLOCK(); //функція для виводу часу та дати (тіло в .срр файлі)
};