#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;
typedef Node* NodePtr;

int getLength(NodePtr head)
{
    int length = 0;

    if (!head)
        return length;

    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// Insert an element kth position from the start of linked list. Return 1 if
// success and if list is not long enough, then return -1.

int insertElementKthPosition(NodePtr* ptrHead, int index, int value)
{
    NodePtr curr = *ptrHead;
    NodePtr newNode;
    int currentPos = 1;

    if (index > getLength(*ptrHead) + 1)
        return -1;
    
    if (!curr)
    {
        newNode = (NodePtr)malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = NULL;
        *ptrHead = newNode;
        return 1;
    }

    while (currentPos < index - 1)
    {
        curr = curr->next;
        currentPos++;
    }

    newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = curr->next;
    curr->next = newNode;
    return 1;
}

void printList(NodePtr head)
{
    while (head)
    {
        printf("[%d] ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    NodePtr head = NULL;

    insertElementKthPosition(&head, 1, 3);
    insertElementKthPosition(&head, 2, 2);
    insertElementKthPosition(&head, 3, 6);

    printList(head);

    insertElementKthPosition(&head, 2, 8);

    insertElementKthPosition(&head, 6, -1);

    printList(head);

    // insertElementKthPosition(&head, 2, 45);
    // printList(head);
}