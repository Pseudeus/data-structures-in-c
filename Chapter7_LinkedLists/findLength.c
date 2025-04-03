#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;

int findLenght(NodePtr head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

// find Nth Node from beginning
NodePtr nthNodeFromBegining(NodePtr head, int index)
{
    int count = 0;
    while (head && count < index - 1)
    {
        count++;
        head = head->next;
    }

    if (head)
        return head;
    else
        return NULL;
}

// Nth Node from end
NodePtr nthNodeFromEnd(NodePtr head, int index)
{
    int size = findLenght(head);
    int startIndex;
    if (size && size < index)
    {
        printf("list does not have %d elements", index);
        return NULL;
    }
    startIndex = size - index + 1;
    return nthNodeFromBegining(head, startIndex);
}

NodePtr nthfNodeFromEndSecApproach(NodePtr head, int index)
{
    int count = 0;
    NodePtr temp = NULL;
    NodePtr curr = head;

    while (curr && count < index - 1)
    {
        count++;
        curr = curr->next;
    }

    if (!curr)
        return NULL;
    
    temp = head;

    while (curr)
    {
        temp = temp->next;
        curr = curr->next;
    }
    return temp;
}

// NodePtr nthNodeFromEnd3(NodePtr head, int index)
// {
//     static int count = 0;
//     NodePtr retval;

//     if (!head)
//         return NULL;

//     retval = nth
// }

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

int main()
{
    NodePtr head;

    for (int i = 0; i < 5; i++)
    {
        insertNode(&head, i + 1);
    }

    int length = findLenght(head);

    printf("The lenght of the linked list is %d\n", length);

    int kth = 4;

    NodePtr kthNode = nthNodeFromBegining(head, kth);

    printf("The %dth value from begining is %d.\n", kth, kthNode->value);

    NodePtr kthNodeFromEnd = nthNodeFromEnd(head, 5);

    printf("The %dth value from the end is %d.\n", 5, kthNodeFromEnd->value);
}
