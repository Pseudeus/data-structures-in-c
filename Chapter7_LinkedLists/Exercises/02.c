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

// Insert an element kth position from the end of linked list. Return 1 if
// success and if list is not long enough, then return -1

int insertElementKthPositionEnd(NodePtr* ptrHead, int position, int value)
{
    int count = 0;
    NodePtr temp = NULL;
    NodePtr curr = *ptrHead;
    NodePtr prev = NULL;

    while (curr && count < position - 1)
    {
        count++;
        prev = curr;
        curr = curr->next;
    }

    if (count < position - 1)
        return -1;

    if (!prev)
    {
        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = prev;
        *ptrHead = newNode;
        return 1;
    }
    
    temp = *ptrHead;

    while (curr && temp->next)
    {
        prev = temp;
        temp = temp->next;
        curr = curr->next;
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value; 
    newNode->next = temp;

    if (temp == *ptrHead)
        *ptrHead = newNode;
    
    else
        prev->next = newNode;
    
    return 1;
}

int main()
{
    NodePtr head = NULL;

    insertElementKthPositionEnd(&head, 1, 3);
    insertElementKthPositionEnd(&head, 2, 2);
    insertElementKthPositionEnd(&head, 3, 6);

    printList(head);

    insertElementKthPositionEnd(&head, 2, 8);

    insertElementKthPositionEnd(&head, 6, -1);

    printList(head);

    // insertElementKthPosition(&head, 2, 45);
    // printList(head);
}