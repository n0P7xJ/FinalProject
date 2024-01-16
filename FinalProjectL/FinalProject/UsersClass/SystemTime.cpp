#include "SystemTime.h"

int SystemTime::getHour() const{
	 return SYSTEMTIME::wHour;
}

int SystemTime::getMinute() const
{
	return SYSTEMTIME::wMinute;
}

void SystemTime::Output()
{
}

