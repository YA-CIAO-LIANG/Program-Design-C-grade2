// 建立成員功能間類別.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//Fig. 17.1:Time.h
//Member class definition
//Member finctions are defined in at Time .cpp

#ifndef TIME_H
#define TIME_H


class Time
{
	public:
		Time();
		void setTime(int, int, int);
		void printUniversal()const;
		void printfStandard()const;


   private:
	   unsigned int hour;
	   unsigned int minute;
	   unsigned int second;
};


#endif

