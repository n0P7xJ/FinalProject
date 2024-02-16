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

int getMonthDay(const SystemTime& sysTime)
{
	int month = sysTime.getMonth();
	int year = sysTime.getYear();

	//�������� �� ���������� ��
	bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

	//�����, �� ������ ������� ��� � �����
	int daysInMonth[] = { 0, 31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return daysInMonth[month];
}
