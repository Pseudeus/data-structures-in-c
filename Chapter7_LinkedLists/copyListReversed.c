#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;

void copyListReversed(NodePtr head, NodePtr* ptrHead2)
{
    printf("copy list reversed");
    NodePtr tempNode = NULL;
    NodePtr tempNode2 = NULL;

    while (head)
    {
        tempNode2 = (NodePtr)malloc(sizeof(Node));
        tempNode2->value = head->value;
        tempNode2->next = tempNode;
        tempNode = tempNode2;
        head = head->next;
    }
    *ptrHead2 = tempNode;
}

void copyList(NodePtr head, NodePtr* ptrHead2)
{
    printf("copy list");
    NodePtr headNode = NULL;
    NodePtr tailNode = NULL;
    NodePtr tempNode = NULL;

    if (!head)
        return;
    headNode = (NodePtr)malloc(sizeof(Node));
    tailNode = headNode;
    headNode->value = head->value;
    headNode->next = NULL;
    head = head->next; 

    while (head)
    {
        tempNode = (NodePtr)malloc(sizeof(Node));
        tempNode->value = head->value;
        tempNode->next = NULL;

        tailNode->next = tempNode;
        tailNode = tailNode->next;
        head = head->next;
    }
    *ptrHead2 = headNode;
}

// Compare list
int compareListRec(NodePtr head1, NodePtr head2)
{
    printf("compare list");
    if (!head1 && !head2)
        return 1;
    else if (!head1 || !head2 || head1->value != head2->value)
        return 0;
    else 
        return compareListRec(head1->next, head2->next);
}

// Compare list
int compareListLin(NodePtr head1, NodePtr head2)
{
    while (head1 && head2)
    {
        if (head1->value != head2->value)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == head2)
        return 1;
    else 
        return 0;
}