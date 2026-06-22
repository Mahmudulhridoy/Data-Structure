#include <stdio.h>
#include <stdlib.h>

struct DNode
{
    int data;
    struct DNode *next;
    struct DNode *prev;
};

struct DNode *head = NULL;

void insertAtBeginning(int value)
{
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at beginning: %d\n", value);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct DNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    printf("Node deleted from end: %d\n", temp->data);
    free(temp);
}

void displayForward()
{
    struct DNode *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly linked list (forward): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse()
{
    struct DNode *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Doubly linked list (reverse): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{

    insertAtBeginning(11);
    insertAtBeginning(80);
    insertAtBeginning(86);
    insertAtBeginning(196);

    displayForward();

    deleteFromEnd();
    displayForward();

    displayReverse();

    return 0;
}