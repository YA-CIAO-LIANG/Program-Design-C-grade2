// 多載的square函式.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;
int volume(int& x)
{
    return  x = x * x * x;
}
float  volume(int& a, int& b)
{
    return (float)b * 3.1415926 * a * a;
}

float volume(int& a, int& b, int& c)
{
    return (float)a * b * c;
}

int main()
{
    int int1, int2, int3;
    cout << "輸入1個數算正方體體積\n輸入2個數算圓柱體體積\n輸入3個數算長方體體積\n ";

    cin >> int1;
    cout << "ans=" << volume(int1) << endl;

    cin >> int1 >> int2;
    cout << "ans=" << volume(int1, int2) << endl;

    cin >> int1 >> int2 >> int3;
    cout << "ans=" << volume(int1, int2, int3) << endl;
}




