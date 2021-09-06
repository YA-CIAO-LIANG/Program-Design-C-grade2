#include <iostream >
#include<stdio.h>
#define SIZE 10
#define EXAM 4

void bubbleSort(char name[][20], int
    studentGrade[][EXAM], int(*compare)(int a, int b));
void printArr(char name[][20], int studentGrade[][EXAM], bool isBeforeSort);
void average(int studentGrade[][EXAM]);

void swap(int* element1Ptr, int* element2Ptr);
void copy1(char* s1, const char* s2);  //字串拷貝
int ascending(int a, int b);
int descending(int a, int b);

int main()
{
    const char* stu_name[SIZE] = {
"Danny","Mary","Jimmy","Peter","Sue","John","Hearts",
"Diamonds","Clubs","Spades" };
    char stu1_name[10][20];

   int studentGrade[SIZE][EXAM] = { {1,74,55,0},{2,56,88,0},
{3,84,11,0}, {4,88,52,0}, {5,100,100,0}, {6,0,0,0}, {7,51,81,0},
{8,74,14,0}, {9,77,55,0}, {10,97,68,0} };
    int searchScore;

    for (int i = 0; i < SIZE; i++)
        copy1(stu1_name[i], stu_name[i]);

    printArr(stu1_name, studentGrade, true);
    printf("\n");

    average(studentGrade);
    printf("%s", "遞增順序排序\n");
    bubbleSort(stu1_name, studentGrade, ascending);
    printArr(stu1_name, studentGrade, false);
    printf("\n");

    printf("%s", "遞減順序排序\n");
    bubbleSort(stu1_name, studentGrade, descending);
    printArr(stu1_name, studentGrade, false);
}
void copy1(char* s1, const char* s2)
{
    for (; ((*s1 = *s2) != '\0'); ++s1, ++s2);
}
void average(int studentGrade[][EXAM])
{
    for (int i = 0; i < SIZE; i++) 
    {
        studentGrade[i][3] = (studentGrade[i][1] + studentGrade[i][2]) / 2;
    }
}
void bubbleSort(char name[][20], int
    studentGrade[][EXAM], int(*compare)(int a, int b)) {
    char temp[20];
    for (int pass = 1; pass < SIZE; ++pass) {
        for (int i = 0; i < SIZE - 1; ++i) {
            if ((*compare)(studentGrade[i][3], studentGrade[i + 1][3]))
            {
                for (int j = 0; j < EXAM; j++)
                    swap(&studentGrade[i][j], &studentGrade[i + 1][j]);
                copy1(temp, name[i]);
                copy1(name[i], name[i + 1]);
                copy1(name[i + 1], temp);
            }
        }
    }
}
void printArr(char name[][20], int studentGrade[][EXAM], bool isBeforeSort)
{
    if (isBeforeSort)
    {
        puts("\n排序前成績：\n");
        printf("學號   姓名      國文   數學 \n");
        for (int i = 0; i < SIZE; ++i)
            printf("%4d %8s %6d %6d \n", studentGrade[i][0], name[i],
                studentGrade[i][1], studentGrade[i][2]);
    }
    else
    {
        puts("\n排序後成績：\n");
        printf("學號   姓名      國文   數學    平均 名次\n");
        for (int i = 0; i < SIZE; ++i)
            printf("%4d %8s %6d %6d %6d %4d\n", studentGrade[i][0],
                name[i], studentGrade[i][1], studentGrade[i][2], studentGrade[i][3],
                i + 1);
        puts("\n");
        puts("");
    }
}
void swap(int* element1Ptr, int* element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
int ascending(int a, int b)    //確定元素是否按升序/順序排序不正常
{
    return b < a; // 如果b小於a則應該交換
}
int descending(int a, int b)  //確定元素是否按升序/順序排序不正常
{
    return b > a;  //如果b大於a則應該交換
}