#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;
typedef Node* NodePtr;

void printList(NodePtr head)
{
    while (head)
    {
        printf("[%d] ", head->value);
        head = head->next;
    }
    printf("\n");
}

// If linked list having a loop is given. Count the number of nodes in the
// linked list

int countLoopedList(NodePtr* ptrHead)
{
    int count = 0;
    NodePtr slowPtr;
    NodePtr fastPtr;
    slowPtr = fastPtr = *ptrHead;
    NodePtr loopNode = NULL;

    if (!slowPtr)
        return 0;
    
    while (fastPtr->next && fastPtr->next->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
        {
            loopNode = slowPtr;
            break;
        }
    }
    NodePtr temp = *ptrHead;

    if (!loopNode)
    {
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    while (temp->next != loopNode->next)
    {
        temp = temp->next;
        loopNode = loopNode->next;
    }

    temp = *ptrHead;

    while (temp != loopNode)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}