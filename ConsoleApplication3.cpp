#include<string.h>
#include<stdio.h>

void dis1(unsigned int value);
void dis2(unsigned int value,unsigned int a,unsigned int b );

int main(void)
{
	unsigned int x;
	printf("input number");
	scanf_s("%d", &x);

	 int a;
	printf("1 left 2 right");
	scanf_s("%d", &a);

	 int b;
	printf("how many step to move");
	scanf_s("%d", &b);

	dis1(x);
	dis2(x, a, b);
}
void dis1(unsigned int value)
{
	unsigned int displayMask = 1 << 31;
	printf("(原)%u", value);

	unsigned int c;
	for (c = 1; c <= 32; c++)
	{

		putchar(value & displayMask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 1)
		{
			putchar(' ');
		}
	}
	putchar('\n');
}
void dis2(unsigned int value, unsigned int a, unsigned int b)
{
	unsigned int displayMask = 1 << 31;
	printf("(後)%u", value);

	if (a == 1)
	{
		value = value << b;
	}
	else if (a == 2)
	{
		value = value >> b;
	}
	else
	{
		printf("error");
	}

	unsigned int c;
	for (c = 1; c <= 32; c++)
	{
		
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 1)
		{
			putchar(' ');
		}
	}
	putchar('\n');
}
