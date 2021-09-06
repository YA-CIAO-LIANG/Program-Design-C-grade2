// 使用一元範圍解析運算子.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

int number = 7;                     //宣告相同名稱的區域 全域變數(number)

int main()
{
    double number = 10.5;

    cout << "Local double value of number=" << number << "\nGlobal int value of number=" << ::number << endl; 
                                                                                        //加上::取全域變數  
}


