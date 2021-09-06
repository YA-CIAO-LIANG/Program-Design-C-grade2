#include <stdio.h>
void displayBits(unsigned int value);
int main(void)
{
    unsigned int x, OperateValue;
    unsigned int y;
    unsigned int z;
    printf("%s", "Enter a nonnegative int: ");
    scanf_s("%u", &x);
    printf("%s", "1 : Right Rotation, 0: Left Rotation ");
    scanf_s("%u", &y);
    printf("%s", "How many bits do you want to rotate? ");
    scanf_s("%u", &z);

    printf("Original bits \n");

    displayBits(x);
    printf(" After rotation  bits \n");
    if (y == 1)  //R R
    {
        OperateValue = x << (32 - z);               //
        x = x >> z;                         //  for rotation
        x = x | OperateValue;
        displayBits(x);
    }
    if (y == 0)
    {
        OperateValue = x >> (32 - z);   //
        x = x << z;                 //  for rotation
        x = x | OperateValue;       //
        displayBits(x);
    }
}
void displayBits(unsigned int value)
{
    unsigned int displayMask = 1 << 31;
    for (unsigned int c = 1; c <= 32; ++c)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;
        if (c % 8 == 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}
