#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the start
void insertAtStart(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at start.\n", value);
}

// Insert at the end
void insertAtEnd(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

// Insert at specific position
void insertAtPosition(int value, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        insertAtStart(value);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}

// Delete a node by value
void deleteNode(int value)
{
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value)  // If head node is to be deleted
    {
        head = temp->next;
        free(temp);
        printf("Deleted %d.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) //traverse the list
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)  // If value not found
    {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next; // Link previous node to next node
    free(temp);
    printf("Deleted %d.\n", value);
}

// Display the linked list
void displayList()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main()
{
    int choice, value, position;

    while (1)
    {
        printf("\n1. Insert at Start\n2. Insert at End\n3. Insert at Position\n4. Delete\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtStart(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 5:
            displayList();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
