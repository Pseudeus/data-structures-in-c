#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;


// Slow pointer and fast pointer approach
int loopDetect(NodePtr head)
{
    printf("loop detect\n");
    NodePtr slowPtr;
    NodePtr fastPtr;
    slowPtr = fastPtr = head;

    while (fastPtr->next && fastPtr->next->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}

void reverse(NodePtr* ptrHead)
{
    NodePtr curr = *ptrHead;
    NodePtr prev;
    NodePtr next;

    if (!curr)
        return;

    if (!curr->next)
        return;

    prev = curr;
    curr = curr->next;
    prev->next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *ptrHead = prev;
}

// Reverse list approach
int ReverseListLoopDetect(NodePtr head)
{
    NodePtr* ptrHead = &head;
    NodePtr head2 = head;
    reverse(ptrHead);

    if (*ptrHead == head2)
    {
        reverse(ptrHead);
        return 1;
    }
    else 
    {
        reverse(ptrHead);
        return 0;
    }
}

int loopTypeDetect(NodePtr const head)
{
    printf("loop detect\n");

    NodePtr slowPtr;
    NodePtr fastPtr;
    slowPtr = fastPtr = head;

    while (fastPtr->next && fastPtr->next->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (head == fastPtr->next || head == fastPtr->next->next)
            return 2;
        
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}

void removeLoop(NodePtr* ptrHead)
{
    unsigned int loopLength;
    NodePtr slowPtr, fastPtr, head;
    slowPtr = fastPtr = head = *ptrHead;
    NodePtr loopNode = NULL;

    while (fastPtr->next && fastPtr->next->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;

        if (fastPtr == slowPtr /*|| fastPtr->next == slowPtr*/)
        {
            loopNode = slowPtr;
            break;
        }
    }

    if (loopNode)
    {
        // NodePtr temp = loopNode->next;
        // loopLength = 1;

        // while (temp != loopNode)
        // {
        //     loopLength++;
        //     temp = temp->next;
        // }
        // temp = head;
        // NodePtr breakNode = head;

        // for (int i = 1; i < loopLength; i++)
        //     breakNode = breakNode->next;
        
        // while (temp != breakNode->next)
        // {
        //     temp = temp->next;
        //     breakNode = breakNode->next;
        // }

        // breakNode->next = NULL;

        NodePtr temp = head;

        while (temp->next != loopNode->next)
        {
            temp = temp->next;
            loopNode = loopNode->next;
        }
        loopNode->next = NULL;
    }
}

NodePtr findIntersection(NodePtr head, NodePtr head2)
{
    int firstListLength = 0;
    int secondListLength = 0;
    NodePtr tempHeead = head;
    NodePtr tempHead2 = head2;

    while (tempHeead)
    {
        firstListLength++;
        tempHeead = tempHeead->next;
    }
    while (tempHead2)
    {
        secondListLength++;
        tempHead2 = tempHead2->next;
    }

    int diff = abs(firstListLength - secondListLength);

    // make shure to set the head pointer to the longest list
    if (firstListLength < secondListLength)
    {
        NodePtr temp = head;
        head = head2;
        head2 = temp;
    }

    // Tie the distance to a posible intersection.
    while (diff > 0)
    {
        head = head->next;
        diff--;
    }

    while (head != head2)
    {
        head = head->next;
        head2 = head2->next;
    }
    return head;
}