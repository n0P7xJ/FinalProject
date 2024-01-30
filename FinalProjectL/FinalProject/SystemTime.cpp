#include "SystemTime.h"

int SystemTime::getDay() const
{
	return wDay;
}

int SystemTime::getMonth() const
{
	return wMonth;
}

int SystemTime::getYear() const
{
	return wYear;
}

int SystemTime::getDayOfWeek() const
{
	return static_cast<int>(wDayOfWeek);
}

std::string SystemTime::getMonthName(const int& monthNumber) const
{
	//перев≥рка на коректн≥сть номера м≥с€ц€
	if (monthNumber < 1 || monthNumber > 12)
		throw (std::runtime_error("Invalid month number"));

	//константний масив м≥с€ц≥в
	const char* monthNames[] = {
			"January", "February", "March", "April",
			"May", "June", "July", "August",
			"September", "October", "November", "December"
	};

	//поверненн€ назви м≥с€ц€ за його номером (в≥д 1 до 12)
	return monthNames[monthNumber - 1];
}

void SystemTime::OutputCLOCK()
{
	while (true)
	{
		GetLocalTime(&sTIME); //отримуЇмо локальний час

		std::cout << "\t" << sTIME.wHour << ":" << sTIME.wMinute << ":" << sTIME.wSecond
			<< std::endl << "\t" << sTIME.wDay << "." << sTIME.wMonth << "." << sTIME.wYear; //виводимо цкй час та дату

		Sleep(1000);

		system("cls");
	}
}

int getMonthDay(const SystemTime& sysTime)
{
	int month = sysTime.getMonth();
	int year = sysTime.getYear();

	//ѕерев≥рка на високосний р≥к
	bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

	//ћасив, що м≥стить к≥льк≥сть дн≥в у м≥с€ц≥
	int daysInMonth[] = { 0, 31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return daysInMonth[month];
}
