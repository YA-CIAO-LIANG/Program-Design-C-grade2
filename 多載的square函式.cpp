// 多載的square函式.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;
int volume(int& x)
{
   x= x * x * x;
}
float  volume(int& a ,int& b)
{
    return (float)b * 3.1415926 * a*a;
}

float volum(int&a, int& b, int& c)
{
    return (float)a * b * c;
}

int main()
{
    int int1, int2, int3;
    cout << "輸入";
    cin >> int1;
    cout << "ans=" << volume(int1);

    cin >> int1>> int2;
    cout << "ans=" << volume(int1, int2);

    cin >> int1>> int2>> int3;
    cout << "ans=" << volume(int1, int2,int3);
}




