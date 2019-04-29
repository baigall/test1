#include"stdafx.h"
#include"iostream"
using namespace std;
class CBaiGaLi
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int check();
public:
	CBaiGaLi();
	CBaiGaLi(int y,int m,int d,int h,int mi,int s);
	void addOneDay();
	void displayCBaiGaLi();
	int setCBaiGaLi(int y, int m, int d, int h, int mi, int s);
	int backYear();
	int backMonth();
	int backDay();
	int backHour();
	int backMinute();
	int backSecond();
};
CBaiGaLi::CBaiGaLi()
{
	year = 2000;
	month = 1;
	day = 21;
	hour = 21;
	minute = 39;
	second = 41;
}
CBaiGaLi::CBaiGaLi(int y, int m, int d, int h, int mi, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = mi;
	second = s;
	if (check() == -1 || check() == 1)
	{
		year = 2019;
		month = 1;
		day = 1;

	}
}
int CBaiGaLi::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
		{
			return 1;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
		{
			return 1;
		}
	}
	if (month > 12 || month < 1)
	{
		return -1;
	}
	return 0;
}
int CBaiGaLi::backYear()
{
	return year;
}
int CBaiGaLi::backMonth()
{
	return month;
}
int CBaiGaLi::backDay()
{
	return year;
}
int CBaiGaLi::backHour()
{
	return hour;
}
int CBaiGaLi::backMinute()
{
	return minute;
}
int CBaiGaLi::backSecond()
{
	return second;
}
int CBaiGaLi::setCBaiGaLi(int y, int m, int d, int h, int mi, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = mi;
	second = s;
	if (check() == -1 || check() == 1)
	{
		year = 2019;
		month = 1;
		day = 1;
		return -1;
	}
	return 0;
}
void CBaiGaLi::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			month++;
			day = 1;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			month++;
			day = 1;
		}
	}
	if (month > 12 )
	{
		year++;
		month = 1;
	}
}
void CBaiGaLi::displayCBaiGaLi()
{
	cout << year <<"年"<< month << "月" << day << "日" << hour << "时" << minute << "分" << second << "秒" << endl;
}
int main()
{
	int count = 1;
	CBaiGaLi od;
	od.setCBaiGaLi(2000, 1, 21, 21, 31, 33);
	od.displayCBaiGaLi();
	while (!((od.backYear() == 2019) && (od.backMonth() == 4) && (od.backDay() == 29)))
	{
		od.addOneDay();
		count++;
	}
	cout << count << endl;
    return 0;
}

