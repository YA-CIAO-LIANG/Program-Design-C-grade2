// 0426.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


struct stuData
{
    unsigned int StuNum;
    int math, computer;
    struct stuData* nextPtr;

};
typedef struct stuData StuData;
typedef StuData* StuDataPtr;


// prototypes
void insert(StuDataPtr* sPtr, int value, int math, int computer);
void printList(StuDataPtr currentPtr);
int delete1(StuDataPtr* sPtr, int value);

int main(void)
{
    StuDataPtr startPtr = NULL; // initially there are no nodes
    int item; // char entered by user
    int i, math, computer;
    for (i = 0; i < 5; i++) {
        printf("%s", "Enter a ID: ");
        scanf_s("\n%d", &item);
        printf("%s", "Enter a math: ");
        scanf_s("\n%d", &math);
        printf("%s", "Enter a computer: ");
        scanf_s("\n%d", &computer);
        insert(&startPtr, item, math, computer);
    }
    printList(startPtr);
    printf("%s", "請輸入要刪除的學號 ");
    int a;
    scanf_s("%d", &a);
    if (delete1(&startPtr,a))
    {
        printList(startPtr);
    }
    else
    {
        printf("%s", "無此學號");
    }
}


// insert a new value into the list in sorted order
void insert(StuDataPtr* sPtr, int value, int math, int computer)
{
    StuDataPtr newPtr = (StuDataPtr)malloc(sizeof(StuData)); // create node

    if (newPtr != NULL) { // is space available
        newPtr->StuNum = value;
        newPtr->math = math;
        newPtr->computer = computer;// place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        StuDataPtr previousPtr = NULL;
        StuDataPtr currentPtr = *sPtr;

        // loop to find the correct location in the list       
        while (currentPtr != NULL && value > currentPtr->StuNum) {
            previousPtr = currentPtr; // walk to ...               
            currentPtr = currentPtr->nextPtr; // ... next node 
        }
        // insert new node at beginning of list
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("%c not inserted. No memory available.\n", value);
    }
}
// print the list

int delete1(StuDataPtr* sPtr, int value)
{
    // delete first node if a match is found
    if (value == (*sPtr)->StuNum) {
        StuDataPtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return value;
    }
    else {
        StuDataPtr previousPtr = *sPtr;
        StuDataPtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->StuNum != value) {
            previousPtr = currentPtr; // walk to ...  
            currentPtr = currentPtr->nextPtr; // ... next node  
        }

        // delete node at currentPtr
        if (currentPtr != NULL) {
            StuDataPtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}


void printList(StuDataPtr currentPtr)
{
    // if list is empty
    if (currentPtr == NULL) {
        puts("List is empty.\n");
    }
    else {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL) {
            printf("%d %d %d --> ", currentPtr->StuNum, currentPtr->math, currentPtr->computer);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
