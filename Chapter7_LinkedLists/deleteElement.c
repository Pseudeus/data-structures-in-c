#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef Node* NodePtr;

void deleteFirstNode(NodePtr* ptrHead)
{
    printf("\nDelete first node \n");
    NodePtr tempNode = *ptrHead;
    if (tempNode == NULL)
        return;
    *ptrHead = tempNode->next;
    free(tempNode);
}

// Delete node from the linked list given its value.
void deleteNode(NodePtr* ptrHead, int value)
{
    printf("Delete value %d\n", value);
    NodePtr curr = *ptrHead;
    NodePtr next;

    if (curr->value == value)
    {
        *ptrHead = curr->next;
        free(curr);
        return;
    }
    
    while (curr != NULL)
    {
        next = curr->next;
        if (next && next->value == value)
        {
            curr->next = next->next;
            free(next);
            return;
        }
        else
            curr = next;
    }
    
}

void deleteNodes(NodePtr* ptrHead, int delVal)
{
    printf("\nDelete Node \n");

    NodePtr curr = *ptrHead;
    NodePtr next;
    NodePtr delNode;


    // treat the head is a different use case so it deserves its own logic
    while (curr != NULL && curr->value == delVal)
    {
        *ptrHead = curr->next;
        delNode = curr;
        curr = curr->next;
        free(delNode);
    }

    while (curr != NULL)
    {
        next = curr->next;
        if (next && next->value == delVal)
        {
            curr->next = next->next;
            free(next);
        }
        else 
            curr = next;
    }
}

// Delete node from the linked list given its pointer
void deleteNodePtr(NodePtr* ptrHead, NodePtr ptrDel)
{
    printf("\ndeleteNode\n");
    NodePtr curr = *ptrHead;
    NodePtr next;

    if (ptrDel == NULL)
        return;
    
    if (curr == ptrDel)
    {
        *ptrHead = curr->next;
        free(curr);
    }

    while (curr != NULL)
    {
        next = curr->next;
        if (next == ptrDel)
        {
            curr->next = next->next;
            free(next);
        }
        else
            curr = next;
    }
}

void deleteList(NodePtr* ptrHead)
{
    printf("\nDelete list\n");
    NodePtr deleteMe = *ptrHead;
    NodePtr next;

    while (deleteMe != NULL)
    {
        next = deleteMe->next;
        free(deleteMe);
        deleteMe = next;
    }
    *ptrHead = NULL;
}

void removeDuplicate(NodePtr head)
{
    NodePtr delme;
    while (head)
    {
        if (head->next && head->value == head->next->value)
        {
            delme = head->next;
            head->next = delme->next;
            free(delme);
        }
        else
            head = head->next;
    }
    
}

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



int main()
{
    NodePtr head = NULL;
    int arr[5] = { 1, 4, 2, 4, 3 };
    
    for (int i = 0; i < 5; i++)
       sortedInsert(&head, arr[i]);

    printf("\n");

    removeDuplicate(head);

    printList(head);
    
    return 0;
}