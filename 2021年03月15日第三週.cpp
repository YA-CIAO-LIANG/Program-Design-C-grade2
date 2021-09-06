#include<stdio.h>
#include<string.h>
int main(void)
{
	char s1[100] = "";    //長度限制
	printf("輸入字串");
	scanf_s("%s", s1, 100);
	printf("輸入要搜尋的字串");
	char s2[100] = " ";
	scanf_s("%s", s2, 100);
	int c = 0;
	for (int i = 0; i < strlen(s1) - strlen(s2) + 1; i++)  //+1往後找
	{
		if(strncmp(s2,s1+i,strlen(s2)) == 0)
		{
			c++;
		}
	}
	printf("共 %d次",c);
}