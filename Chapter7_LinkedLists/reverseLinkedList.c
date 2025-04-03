#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;

// Reverse a singly linked List interatively using three Pointers

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

// Recursively Reverse a singly linked List
NodePtr reverseRecurseUtil(NodePtr current, NodePtr next)
{
    NodePtr ret;
    if (!current)
        return NULL;
    
    if (!current->next)
    {
        current->next = next;
        return current;
    }

    ret = reverseRecurseUtil(current->next, current);
    current->next = next;

    return ret;
}

void reverseRecurse(NodePtr* ptrHead)
{
    *ptrHead = reverseRecurseUtil(*ptrHead, NULL);
}