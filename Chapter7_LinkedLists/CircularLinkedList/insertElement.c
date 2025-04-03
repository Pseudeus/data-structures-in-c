#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int value;
    struct Node* next;
}Node_t;

typedef Node_t* NodePtr;

/* Insert element in front */
int insertNodeAtFront(NodePtr* ptrHead, NodePtr* ptrTail, int value)
{
    printf("\n INSERT NODE AT FRONT \n");
    NodePtr temp = (NodePtr)malloc(sizeof(Node_t));
    
    if (!temp)
        return 0;

    temp->value = value;
    NodePtr head = *ptrHead;
    NodePtr tail = *ptrTail;

    if (!head)
    {
        temp->next = temp;
        *ptrTail = *ptrHead = temp;
    }
    else
    {
        temp->next = head;
        tail->next = temp;
        *ptrHead = temp;
    }
    return 1;
}

/* Insert element at the end */
int insertNodeAtEnd(NodePtr* ptrHead, NodePtr* ptrTail, int value)
{
    printf("\n INSERT NODE AT END\n");
    NodePtr temp = (NodePtr)malloc(sizeof(Node_t));

    if (!temp)
        return 0;
    
    temp->value = value;
    NodePtr head = *ptrHead;
    NodePtr tail = *ptrTail;

    if (!head)
    {
        temp->next = temp;
        *ptrTail = *ptrHead = temp;
    }
    else
    {
        temp->next = head;
        tail->next = temp;
        *ptrTail = temp;
    }
    return 1;
}

/* Print list */
void printList(NodePtr head)
{
    printf("LIST IS:: ");
    NodePtr curr = head;
    if (curr != NULL)
    {
        printf("[%d] ", curr->value);
        curr = curr->next;
    }

    while (curr != head)
    {
        printf("[%d] ", curr->value);
        curr = curr->next;
    }
}

/* Delete a circular linked list */
void deleteList(NodePtr* ptrHead)
{
    printf("\n DELETE LIST\n");
    NodePtr const head = *ptrHead;
    NodePtr curr = *ptrHead;
    NodePtr next;

    if (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    while (curr != head)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *ptrHead = NULL;
}

/* Delete a node given its pointer */
void deleteNodePtr(NodePtr* ptrHead, NodePtr* ptrTail, NodePtr ptrDel)
{
    printf("\n DELETE NODE GIVEN ITS POINTER \n");

    if (!ptrDel || !ptrHead || !ptrTail)
        return;

    NodePtr head = *ptrHead;
    NodePtr tail = *ptrTail;
    NodePtr curr = head;
    NodePtr prev;

    if (!head || !tail)
        return;
    
    if (curr == ptrDel)
    {
        if (curr->next = curr)
        {
            *ptrTail = NULL;
            *ptrHead = NULL;
            free(curr);
            return;
        }
        else
        {
            *ptrHead = curr->next;
            tail->next = curr->next;
            free(curr);
            return;
        }
    }

    prev = curr;
    curr = curr->next;

    while (curr != head)
    {
        if (curr == ptrDel)
        {
            if (curr == tail)
                *ptrTail = prev;

            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* Delete a node given its value */
void deleteNodeValue(NodePtr* ptrHead, NodePtr* ptrTail, int value)
{
    printf("\n DELETE NODE GIVEN ITS VALUE \n");

    if (!ptrHead || !ptrTail)
        return;
    
    NodePtr head = *ptrHead;
    NodePtr tail = *ptrTail;
    NodePtr curr = head;
    NodePtr prev;

    if (!head || !tail)
        return;
    
    if (curr->value == value)
    {
        if (curr->next == curr)
        {
            *ptrHead = NULL;
            *ptrTail = NULL;
            free(curr);
            return;
        }
        else
        {
            *ptrHead = curr->next;
            tail->next = curr->next;
            free(curr);
            return;
        }
    }

    prev = curr;
    curr = curr->next;

    while (curr != head)
    {
        if (curr->value == value)
        {
            if (curr == tail)
                *ptrTail = prev;
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* Remove Duplicate */
void removeDuplicate(NodePtr* ptrHead, NodePtr* ptrTail)
{
    printf("\n Remove Duplicate\n");
    NodePtr head = *ptrHead;
    NodePtr curr = head;
    NodePtr deleteMe;

    if (!head)
        return;
    
    while (curr->next != head)
    {
        if (curr->value == curr->next->value)
        {
            deleteMe = curr->next;
            curr->next = deleteMe->next;

            if (deleteMe == *ptrTail)
                *ptrTail = curr;
            
            free(deleteMe);
        }
        else
        {
            curr = curr->next;
        }
    }
}

/* Copy List Reversed */
void copyListReversed(NodePtr head, NodePtr* newPtrHead, NodePtr* newPtrTail)
{
    printf("\n COPY LIST REVERSED\n");
    NodePtr curr = head;

    if (curr)
    {
        insertNodeAtFront(newPtrHead, newPtrTail, curr->value);
        curr = curr->next;
    }

    while (curr != head)
    {
        insertNodeAtFront(newPtrHead, newPtrTail, curr->value);
        curr = curr->next;
    }
}

/* Copy List */
void CopyList(NodePtr head, NodePtr* newPtrHead, NodePtr* newPtrTail)
{
    printf("\n COPY LIST\n");
    NodePtr curr = head;

    if (curr)
    {
        insertNodeAtEnd(newPtrHead, newPtrTail, curr->value);
        curr = curr->next;
    }

    while (curr != head)
    {
        insertNodeAtEnd(newPtrHead, newPtrTail, curr->value);
        curr = curr->next;
    }
}