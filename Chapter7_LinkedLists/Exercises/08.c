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

NodePtr createNode(int value)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(NodePtr* ptrHead, int value)
{
    NodePtr head = *ptrHead;

    if (!head)
    {
        NodePtr newn = createNode(value);
        *ptrHead = newn;
        return;
    }

    NodePtr newNode = createNode(value);
    newNode->next = head;
    *ptrHead = newNode;
}

void reverseList(NodePtr* ptrHead)
{
    NodePtr curr = *ptrHead;
    NodePtr next = NULL;
    NodePtr prev = NULL;

    if (!curr)
        return;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *ptrHead = prev;    
}

// Given two linked lists. Whe have to find that whether the data in one is
// reverse that of data in another. No extra space should be used and traverse
// the linked list only once.

int isReverse(NodePtr* ptrHead1, NodePtr* ptrHead2)
{
    if (!*ptrHead1 && !*ptrHead2)
        return 1;
    if (!*ptrHead1 || !*ptrHead2)
        return 0;

    reverseList(ptrHead2);

    NodePtr head1 = *ptrHead1;
    NodePtr head2 = *ptrHead2;

    while (head1 && head2)
    {
        if (head1->value != head2->value)
        {
            reverseList(ptrHead2);
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    reverseList(ptrHead2);

    return !head1 && !head2;
}

int main()
{
    NodePtr list1 = NULL;
    NodePtr list2 = NULL;

    int rev = isReverse(&list1, &list2);

    printf("isReverse = %d\n", rev);

    for (int i = 0; i < 10; i++)
    {
        insertNode(&list1, i + 1);
        insertNode(&list2, i + 1);
    }

    rev = isReverse(&list1, &list2);
    printList(list1);
    printList(list2);
    printf("isReverse = %d\n", rev);

    reverseList(&list2);

    rev = isReverse(&list1, &list2);
    printList(list1);
    printList(list2);
    printf("isReverse = %d\n", rev);
}