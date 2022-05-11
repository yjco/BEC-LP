#include <stdio.h>

/*
 * Exercise 5-8 (P. 93)
 * Add error checks to day_of_month() and month_day()
 */

int day_of_year(int year, int month, int day);
int month_day(int year, int yesterday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int main() {

	int m, d, y;

	y = day_of_year(2019, 5, 14);
	printf("%d\n", y);

	month_day(2019, y, &m, &d);
	printf("%d - %d\n", m, d);

}

int day_of_year(int year, int month, int day) {

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return -1;

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; i < month; i++) day += daytab[leap][i];     	
	return day;

}

int month_day(int year, int yearday, int *pmonth, int *pday) {

	if (year < 0 || yearday < 0 || yearday > 365) return -1;

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; yearday > daytab[leap][i]; i++) yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;

	return 0;

}
