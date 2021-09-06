// 17.3 時間.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<stdexcept>
#include "Time.h"
using namespace std;

int main()
{
	Time t;

	cout << "The initial universal time is : ";
	t.printUniversal();
	cout << "\nThe initial standard time is : ";
	t.printStandard();
	
	int h, m, s;
	cout << "Please input time : ";
	cin >> h>> m>>s;

	t.setTime(h, m, s);


	cout << "\n\nUniversal time after setTime is : ";
	t.printUniversal();
	cout << "\nStandard time after seetTime is : ";
	t.printStandard();


	try
	{
		t.setTime(99, 99, 99);
	}
	catch(invalid_argument & e)
	{
		cout << "\nExcaption:" << e.what() << endl;
	}
	cout << "\n\nAfter attempting invalid settings:" << "\nUniversal time:";

	t.printUniversal(); 
	cout << "\nStandard time";
	t.printStandard();
	cout << endl;

}