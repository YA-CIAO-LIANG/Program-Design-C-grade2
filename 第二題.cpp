// 第二題.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<stdio.h>
#include<ctype.h>

 int upper(char *str);
 int lower(char*str);
 int  num(char* str);

    
 int main(void)
 {
	 int(*f[3])(char*) = { upper, lower,  num };         

	 char str[] = "abcDEFG000";   

	 for (int c = 0; c <= 2; c++)
	 {
		 (*f[c])(str);
	 }
 }
 

 int upper(char* str)
 {
	  
	 int  size = strlen(str);   //函式會回傳字串的長度，其中的＂字串＂是必要項目，即為要計算長度的 String。
	 int count = 0;
	 for (int c = 0; c <= size; c++)
	 {
		 if (isupper(str[c]))
		 {
			 count++;
		 }
	 }
	 printf("大寫有:%d個\n", count);
	 return 0;
 }
 int lower(char* str)

 {
	 int  size = strlen(str);
	 int count = 0;
	 for (int c = 0; c <= size; c++)
	 {
		 if (islower(str[c]))
		 {
			 count++;
		 }
	 }
	 printf("小寫有:%d個\n", count);
	 return 0;
 }
 int  num(char* str)
 {
	 int  size = strlen(str);
	 int count = 0;
	 for (int c = 0; c <= size; c++)
	 {
		 if (isdigit(str[c]))
		 {
			 count++;
		 }
	 }
	 printf("數字:%d個\n", count);
	 return 0;
 }

 ///////////////////////