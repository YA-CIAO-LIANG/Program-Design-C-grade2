

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[20] = "3.14 bubu 3.1415926";
       

        const char* string = s1;
        char* stringPtr;

        double d = strtod(string, &stringPtr);


          
        printf("double value %.5f and the string \"%s\"\n", d, stringPtr);



   
}