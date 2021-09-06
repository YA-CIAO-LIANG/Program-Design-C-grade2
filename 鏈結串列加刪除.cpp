#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{
    int  data;
    int math;
    int computer;
    struct listNode* nextPtr; // pointer to next node
};



typedef struct listNode ListNode; //; synonym for struct listNode
typedef ListNode* ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr* sPtr, int value,int math,int computer);
int datadelete(ListNodePtr* sPtr, int value);
void printList(ListNodePtr currentPtr);
int isEmpty(ListNodePtr sPtr);

int main(void)
{

    ListNodePtr startPtr = NULL;
    int  item;
    int  i, math, computer;
    

    for (int i = 0; i < 5; i = i + 1)
    {
        printf("第%d個:\n", i + 1);
        printf("%s", "輸入學生學號");
        scanf_s("\n%d", &item);
       
        printf("%s", "輸入數學成績");
        scanf_s("\n%d", &math);
       
        printf("%s", "輸入計概成績");
        scanf_s("\n%d", &computer);
        insert(&startPtr, item,math, computer);
    }


    if (!isEmpty(startPtr))
    {
        printf("%s", "Enter character to be deleted: ");
        scanf_s("\n%d", &item);

        if (datadelete(&startPtr, item))
        {
            printf("%d deleted.\n", item);
            printList(startPtr);
        }
        else
        {
            printf("%d not found.\n\n", item);
        }
    }
    
}



void insert(ListNodePtr* sPtr, int value, int math, int computer)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(listNode)); // create node

    if (newPtr != NULL) { // is space available
        newPtr->data = value;
        newPtr->math = math;
        newPtr->computer = computer;// place value in node
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
        printf("%c not inserted. No memory available.\n", value);
    }
}

int datadelete(ListNodePtr* sPtr, int value)
{
    // delete first node if a match is found


    if (value == (*sPtr)->data) {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return value;
    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr; // walk to ...  
            currentPtr = currentPtr->nextPtr; // ... next node  
        }

        // delete node at currentPtr
        if (currentPtr != NULL) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}
// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty

    puts("The list is:");

    // while not the end of the list
    while (currentPtr != NULL) {
        printf("%d %d %d --> ", currentPtr->data,currentPtr->math,currentPtr->computer);
        currentPtr = currentPtr->nextPtr;
    }

    puts("NULL\n");

}
