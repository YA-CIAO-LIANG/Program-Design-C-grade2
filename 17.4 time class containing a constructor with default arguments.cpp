// 17.4 time class containing a constructor with default arguments.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

#ifndef TIME_H
#define TIME_ H

class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	unsigned int getHour() const;
	unsigned int getMinute() const;
	unsigned int getSecond() const;

	void printUniversal() const;
	void printStandard() const;
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
};
#endif

