#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
	// char s1[100] = "";    //長度限制
	//printf("輸入字串，印出字串中的浮點數");
	//scanf_s("%s", s1, 100);
	char s1[] = "bubu3.14jojo6.66";
	const char* string = s1;
	char* stringPtr;
	char a[] = " ";
	int i;
	for (i = 0; i < strlen(s1); i = i + 1)
	{
		strncpy(a, s1, 1);
		printf("%s\n", a);
	}


	double d = strtod(string, &stringPtr);

	printf("double value %.5f and the string \"%s\"\n", d, stringPtr);

 }