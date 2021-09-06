// 17.2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<iomanip>
#include<stdexcept>
#include"Time.h"

using namespace std;

Time::Time()
	:hour(0), minute(0), second(0)
{

}

void Time::setTime(int h, int m, int s)
{
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
	{
		hour = h;
		minute = m;
		second = s;
	}
	else
		throw invalid_argument
		(
			"hour,minute and/or second was out of range"
		);
}
	void Time::printUniversal() const       
	{
		cout <<setfill('0')<< setw(2) << hour    //參數化流由操作者setfill指定填充字符//當參數印出低於數值 
			<< ":"setw(2) << minute << ":" << set(2) << second;
	}
	void Time::printStandard() const
	{
		cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)  //決定數值小時要被取代,小時為0或12(AM or PM) //14%12於2//下午兩點
			<< ":" << setfill('0') << setw(2) << minute << ":"
			<< setw(2) << second << (hour < 12 ? "AM" : "PM");

	}





