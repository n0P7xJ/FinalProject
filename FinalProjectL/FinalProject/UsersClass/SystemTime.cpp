#include "SystemTime.h"

void SystemTime::Output()
{
	while (true)
	{
		GetLocalTime(&sTIME);

		std::cout << "\t" << sTIME.wHour << ":" << sTIME.wMinute << ":" << sTIME.wSecond
			<< std::endl << "\t" << sTIME.wDay << "." << sTIME.wMonth << "." << sTIME.wYear;

		Sleep(1000);

		system("cls");
	}
}