// 初始化並使用參考.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。


#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int& y = x;              //&y為x的別名

	cout << "x=" << x << endl << "y=" << y << endl;
	y = 7;
	cout << "x=" << x << endl << "y=" << y << endl;
}


/*#include <iostream>
using namespace std;
int main()
{
	int x = 3;
	int& y ;   //错误y必须初始化


	cout << "x=" << x << endl << "y=" << y << endl;
	y = 7;
	cout << "x=" << x << endl << "y=" << y << endl;
}
*/


