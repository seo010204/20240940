#ifndef _REPORT_H
#define _REPORT_H
#include <stdio.h>
#include <time.h>

void week2(int year, int month, int day)
{
	time_t current = time(NULL);
	struct tm* timeinfo = localtime(&current);
	
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	time_t userday = mktime(timeinfo);
	
	int diff = difftime(userday, current);

	diff = diff / 60 / 60 / 24;
	printf("%d %d %d -> ���÷κ��� %d�� ��(-��) �Դϴ�.\n", year, month, day, diff);

	return 0;
}
#endif