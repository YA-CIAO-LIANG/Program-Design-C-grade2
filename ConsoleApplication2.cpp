#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{
    int data;
    struct listNode* nextPtr; // pointer to next node
};

typedef  struct     mystu
{
    int StuNum;
    int math;
    int computer;
}student;

typedef struct listNode ListNode; //; synonym for struct listNode
typedef ListNode* ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr* sPtr, int value);


void printList(ListNodePtr currentPtr);

int main(void)
{

    ListNodePtr startPtr = NULL; // initially there are no nodes

    student  mystu = { 0,0,0 };

    // printf("%s", "? ");
    // unsigned int choice; // user's choice
    // scanf("%u", &choice);

    for (int i = 0; i < 5; i = i + 1)
    {
        printf("第%d個:\n", i + 1);
        printf("%s", "輸入學生學號");
        scanf_s("\n%d", &mystu.StuNum);
        insert(&startPtr, mystu.StuNum);
        printf("%s", "輸入數學成績");
        scanf_s("\n%d", &mystu.math);
        insert(&startPtr, mystu.math);
        printf("%s", "輸入計概成績");
        scanf_s("\n%d", &mystu.computer);
        insert(&startPtr, mystu.computer);


    }
    printList(startPtr);
    puts("End of run.");
}



void insert(ListNodePtr* sPtr, int value)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    if (newPtr != NULL) { // is space available
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && value > currentPtr->data) {
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
        printf("%d not inserted. No memory available.\n", value);
    }
}




// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty

    puts("The list is:");

    // while not the end of the list
    while (currentPtr != NULL) {
        printf("%d --> ", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }

    puts("NULL\n");

}
