// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <stdio.h>

void displayBits(unsigned int value);
// prototype
int main(void)
{
	unsigned int x;
	unsigned int y;
	printf("%s", "Enter a nonnegative int: ");
	scanf_s("%u", &x);
	printf("%s", "Enter a nonnegative int: ");
	scanf_s("%u", &y);
	displayBits(x);
	displayBits(y);

	puts("and");
	displayBits(x&y);
	puts("or");
	displayBits(x | y);
	puts("xor");
	displayBits(x ^ y);

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


