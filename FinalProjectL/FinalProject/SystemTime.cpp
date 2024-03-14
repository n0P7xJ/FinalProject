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
	//�������� �� ���������� ������ �����
	if (monthNumber < 1 || monthNumber > 12)
		throw (std::runtime_error("Invalid month number"));

	//����������� ����� ������
	const char* monthNames[] = {
			"January", "February", "March", "April",
			"May", "June", "July", "August",
			"September", "October", "November", "December"
	};

	//���������� ����� ����� �� ���� ������� (�� 1 �� 12)
	return monthNames[monthNumber - 1];
}

void SystemTime::OutputCLOCK()
{
	while (true)
	{
		GetLocalTime(&sTIME); //�������� ��������� ���

		std::cout << "\t" << sTIME.wHour << ":" << sTIME.wMinute << ":" << sTIME.wSecond
			<< std::endl << "\t" << sTIME.wDay << "." << sTIME.wMonth << "." << sTIME.wYear; //�������� ��� ��� �� ����

		Sleep(1000);

		system("cls");
	}
}


int getMonthDay(const int& month, const int& year)
{
	//�������� �� ���������� ��
	bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

	//�����, �� ������ ������� ��� � �����
	int daysInMonth[] = { 0, 31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return daysInMonth[month];
}

int SystemTime::getDayOfWeekForFirstDayOfMonth(const int& month,const int& year) const {
	// Перевірка коректності введених даних
	if (month < 1 || month > 12) {
		throw std::invalid_argument("Invalid month number");
	}

	// Отримання поточної дати та часу
	SYSTEMTIME firstDayOfMonth = *this;

	// Встановлення першого дня місяця
	firstDayOfMonth.wDay = 1;

	// Встановлення номера місяця
	firstDayOfMonth.wMonth = month;
	firstDayOfMonth.wYear = year;
	// Конвертація системного часу в файловий час
	FILETIME ft;
	SystemTimeToFileTime(&firstDayOfMonth, &ft);

	// Конвертація файлового часу в системний час з врахуванням часового поясу
	TIME_ZONE_INFORMATION timeZoneInfo;
	if (!FileTimeToSystemTime(&ft, &firstDayOfMonth)) {
		// Обробка помилки конвертації
		throw std::runtime_error("Failed to convert system time to local time");
	}

	// Повернення номера дня тижня першого дня місяця
	return static_cast<int>(firstDayOfMonth.wDayOfWeek) == 0 ? 7: static_cast<int>(firstDayOfMonth.wDayOfWeek);
}