// 使用預設引數.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。


#include <iostream>
using namespace std;

int boxVolume(int length = 1, int width = 1, int height = 1);

int main()
{
    cout << "The default box volume is:" << boxVolume();

    cout << "\n\nThe volume of a box with lenth 10,\n" << "width 1 and height 1 is " << boxVolume(10);

    cout << "\n\nThe volume of a box with lenth 10,\n" << "width 5 and height 1 is " << boxVolume(10,5);

    cout << "\n\nThe volume of a box with lenth 10,\n" << "width 5 and height 2 is " << boxVolume(10,5,2)<<endl;
}

int boxVolume(int length , int width , int height )
{
    return length * width * height;
}

