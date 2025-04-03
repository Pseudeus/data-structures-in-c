#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int value;
    struct Node* prev;
    struct Node* next;
} Node;
typedef Node* NodePtr;

int insertNode(NodePtr* ptrHead, int value)
{
    printf("\n INSERT NODE\n");
    NodePtr temp = (NodePtr)malloc(sizeof(Node));

    if (!temp)
        return;
    
    NodePtr head = *ptrHead;

    if (!head)
    {
        temp->value = value;
        temp->next = temp;
        temp->prev = temp;
        *ptrHead = temp;
    }
    else
    {
        temp->value = value;
        temp->next = head;
        temp->prev = head->prev;
        temp->prev->next = temp;
        head->prev = temp;
        *ptrHead = temp;
    }
    return 1;
}

void deleteNodePtr(NodePtr* ptrHead, NodePtr ptrDel)
{
    printf("\ndeleteNode\n");
    NodePtr curr = *ptrHead;
    NodePtr head = *ptrHead;

    if (!ptrDel || !(*ptrHead))
        return;
    
    if (curr == ptrDel)
    {
        if (curr->next = curr)
        {
            *ptrHead = NULL;
            free(curr);
            return;
        }
        else
        {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            *ptrHead = curr->next;
            free(curr);
            return;
        }
    }
    curr = curr->next;

    while (curr != head)
    {
        if (curr == ptrDel)
        {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            free(curr);
            return;
        }
        curr = curr->next;
    }
}

void removeDuplicate(NodePtr head)
{
    NodePtr delMe;
    NodePtr const tagHead = head;

    if (!head)
        return;

    if (head->next == head)
        return;
    else
    {
        if (head->next->value == head->value)
        {
            delMe = head->next;
            delMe->prev->next = delMe->next;
            delMe->next->prev = delMe->prev;
            free(delMe);
        }
    }

    head = head->next;

    while (head != tagHead)
    {   
        if (head == head->next)
            break;

        if (head->next && head->value == head->next->value)
        {
            delMe = head->next;
            delMe->prev->next = delMe->next;
            delMe->next->prev = delMe->prev;
            free(delMe);
        }
        else
            head = head->next;
    }
}

void copyListReversed(NodePtr head, NodePtr* ptrHead2)
{
    printf("copy list");
    NodePtr newNext = NULL;
    NodePtr newCurrent = NULL;
    NodePtr const head2 = head;

    if (head)
    {
        newCurrent = (NodePtr)malloc(sizeof(Node));
        newCurrent->value = head->value;
        newCurrent->next = newNext;
        newCurrent->prev = NULL;
        newNext = newCurrent;
        head = head->next;
    }

    while (head != head2)
    {
        newCurrent = (NodePtr)malloc(sizeof(Node));
        newCurrent->value = head->value;
        newCurrent->next = newNext;
        newCurrent->prev = NULL;
        newNext->prev = newCurrent;
        newNext = newCurrent;
        head = head->next;
    }
    *ptrHead2 = newNext;
}

void copyList(NodePtr head, NodePtr* ptrHead2)
{
    printf("copy list");
    NodePtr headNode = NULL;
    NodePtr tempNode = NULL;
    NodePtr const tagHead = head;
    NodePtr tailNode;

    if (!head)
        return;

    tailNode = headNode = (NodePtr)malloc(sizeof(Node));
    headNode->value = head->value;
    headNode->next = headNode;
    headNode->prev = headNode;
    head = head->next;

    while (head != tagHead)
    {
        tempNode = (NodePtr)malloc(sizeof(Node));
        tempNode->value = head->value;
        tailNode->next = tempNode;
        tempNode->prev = tailNode;
        tempNode->next = headNode;
        headNode->prev = tempNode;
        tailNode = tempNode;
        head = head->next;
    }
    *ptrHead2 = headNode;
}