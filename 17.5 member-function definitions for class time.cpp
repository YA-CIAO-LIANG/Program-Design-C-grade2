// 17.5 member-function definitions for class time.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

 #include <iostream>
 #include <iomanip>
 #include <stdexcept>
 #include "Time.h"

using namespace std;

Time::Time(int Year, int minute, int second)
{
	setTime(Year, minute, second);    //調用成員函數setTime數值到建構子
}
void Time::setTime(int h, int m, int s)
{
	setYear(h);
	setMinute(m);
	setSecond(s);
}

void Time::setYear(int h)
{
	if (h >= 1911 && h < 2100)               //如果接收到超出範圍的參數，則為異常
		Year = h;
}
void Time::setMinute(int m)
{
	if (m >0 && m <=12)
		minute = m;	
} 
void Time::setSecond(int s)
{
	if (s > 0 && s <=31)
		second = s;	
}

unsigned int Time::getYear() const
{
	return Year;
}

unsigned Time:: getMinute() const
{
	return minute;
} 
unsigned Time::getSecond() const
{
	return second;
}
void Time::printUniversal() const
{
	cout << setfill('0') <<"西元"<< getYear() << "年"
		<< setw(2) << getMinute() << "月" << setw(2) << getSecond()<<"日";
}
void Time::printStandard() const
{
	cout << "民國"<<( getYear() - 1911)
		<< "年"
		<< setw(2) << getMinute() << "月" << setw(2) << getSecond() << "日";
	
}