#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;


// insertion of an element at the start of linked list
int insertNode(NodePtr *ptrHead, int value)
{
    printf("Insert Node: %d\n", value);
    NodePtr tempPtr = (NodePtr)malloc(sizeof(Node));

    if (!tempPtr)
        return -1;
    tempPtr->value = value;
    tempPtr->next = *ptrHead;
    *ptrHead = tempPtr;
    return 1;
}

// traversing Linked list
void printList(NodePtr head)
{
    while (head)
    {
        printf("value %d\n", head->value);
        head = head->next;
    }
}

// Insert an element at the end of linked list given head pointer
int insertAt_end(NodePtr *ptrHead, int value)
{
    printf("insert element %d\n", value);
    NodePtr head = *ptrHead;
    NodePtr tempNode = (NodePtr)malloc(sizeof(Node));

    if (!tempNode)
        return -1;
    
    tempNode->value = value;
    tempNode->next = NULL;

    if (head == NULL)
    {
        tempNode->next = *ptrHead;
        *ptrHead = tempNode;
        return 1;
    }

    while (head->next != NULL)
        head = head->next;

    tempNode->next = head->next;
    head->next = tempNode;
    return 1;
}

// Insertion of an element at the end of linked list (given head pointer, and
// tail pointer)
int insertNodeHT(NodePtr *ptrHead, NodePtr *ptrTail, int value)
{
    printf("Insert Node:: %d", value);
    NodePtr tempPtr = (NodePtr)malloc(sizeof(Node));

    if (!tempPtr)
        return -1;

    tempPtr->value = value;
    tempPtr->next = NULL;
    
    if (*ptrHead == NULL)
        *ptrTail = *ptrHead = tempPtr;
    else
    {
        NodePtr tail = *ptrTail;
        tail->next = tempPtr;
        *ptrTail = tempPtr;
    }
    return 1;   
}

int main()
{
    NodePtr head = NULL;
    int arr[5] = { 1, 2, 3, 4, 5 };
    
    for (int i = 0; i < 5; i++)
        insertNode(&head, arr[i]);
    
    return 0;
}