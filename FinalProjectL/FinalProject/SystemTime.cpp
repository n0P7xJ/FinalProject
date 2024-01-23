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

void SystemTime::OutputCLOCK()
{
	while (true)
	{
		GetLocalTime(&sTIME); //отримуємо локальний час

		std::cout << "\t" << sTIME.wHour << ":" << sTIME.wMinute << ":" << sTIME.wSecond
			<< std::endl << "\t" << sTIME.wDay << "." << sTIME.wMonth << "." << sTIME.wYear; //виводимо цкй час та дату

		Sleep(1000);

		system("cls");
	}
}