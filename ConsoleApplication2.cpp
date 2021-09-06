#include <stdio.h>

void displayBits(unsigned int value);
// prototype
int main(void)
{
	unsigned int x;
	unsigned int y;
	printf("%s", "Enter a nonnegative int: ");
	scanf_s("%u", &x);
	displayBits(x);

	printf("%s", "Enter a nonnegative int: ");
	scanf_s("%u", &y);
	displayBits(y);


	printf(" AND \n");
	displayBits(x & y);
	printf(" OR \n");
	displayBits(x | y);
	printf(" XOR \n");
	displayBits(x ^ y);



}

void displayBits(unsigned int value)
{
	unsigned int displayMask = 1 << 31; //遮罩為1左移31個位元 其他的都遮起來
	for (unsigned int c = 1; c <= 32; ++c)   //宣告c
	{
		putchar(value & displayMask ? '1' : '0');  // value =199 =1100011是二進位的值,印出來要用字元方式   displaymask=00000001
		value <<= 1;                          
		if (c % 8 == 0)
		{
			putchar(' ');
		}
	}
	putchar('\n');
}
