#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;

// Insert an element in sorted order in linked list given Head pointer
int sortedInsert(NodePtr *ptrHead, int value)
{
    NodePtr curr = *ptrHead;
    NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
    printf("Insert element %d\n", value);

    if (!tempNode)
        return -1;
    
    tempNode->value = value;
    tempNode->next = NULL;

    if (curr == NULL || curr->value > value)
    {
        tempNode->next = *ptrHead;
        *ptrHead = tempNode;
        return 1;
    }

    while (curr->next != NULL && curr->next->value < value)
        curr = curr->next;

    tempNode->next = curr->next;
    curr->next = tempNode;
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

//Search element in a linked-list
int searchList(NodePtr head, int value)
{
    while (head)
    {
        if (head->value == value)
        {
            printf("The value was found");
            return 1;
        }

        head = head->next;
    }
    return 0;
}

int main()
{
    NodePtr head = NULL;
    int arr[5] = { 1, 4, 2, 5, 3 };
    
    for (int i = 0; i < 5; i++)
        sortedInsert(&head, arr[i]);

    printList(head);
    
    return 0;
}