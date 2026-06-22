// Lab_9_Singly_Circular_Doubly_LinkedList.c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct DNode
{
    int data;
    struct DNode *next;
    struct DNode *prev;
};

struct Node *head_singly = NULL;
struct Node *head_circular = NULL;
struct DNode *head_doubly = NULL;

void insertAtEndSingly(int value);
void deleteNodeSingly(int value);
void displayListSingly();

void insertAtEndCircular(int value);
void deleteNodeCircular(int value);
void displayListCircular();

void insertAtEndDoubly(int value);
void deleteNodeDoubly(int value);
void displayListDoubly();

int main()
{
    int choice, value, listType;

    printf("Select the type of linked list:\n");
    printf("1. Singly Linked List\n");
    printf("2. Circular Linked List\n");
    printf("3. Doubly Linked List\n");
    printf("Enter your choice: ");
    scanf("%d", &listType);

    while (1)
    {
        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Insert node
            printf("Enter value to insert: ");
            scanf("%d", &value);
            if (listType == 1)
                insertAtEndSingly(value);
            else if (listType == 2)
                insertAtEndCircular(value);
            else if (listType == 3)
                insertAtEndDoubly(value);
            break;
        case 2: // Delete node
            printf("Enter value to delete: ");
            scanf("%d", &value);
            if (listType == 1)
                deleteNodeSingly(value);
            else if (listType == 2)
                deleteNodeCircular(value);
            else if (listType == 3)
                deleteNodeDoubly(value);
            break;
        case 3: // Display list
            if (listType == 1)
                displayListSingly();
            else if (listType == 2)
                displayListCircular();
            else if (listType == 3)
                displayListDoubly();
            break;
        case 4: // Exit
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Singly Linked List Functions
void insertAtEndSingly(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head_singly == NULL)
    {
        head_singly = newNode;
    }
    else
    {
        struct Node *temp = head_singly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted: %d\n", value);
}

void deleteNodeSingly(int value)
{
    struct Node *temp = head_singly, *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head_singly = temp->next;
        free(temp);
        printf("Node deleted: %d\n", value);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted: %d\n", value);
}

void displayListSingly()
{
    struct Node *temp = head_singly;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Singly linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Circular Linked List Functions
void insertAtEndCircular(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head_circular == NULL)
    {
        head_circular = newNode;
        newNode->next = head_circular;
    }
    else
    {
        struct Node *temp = head_circular;
        while (temp->next != head_circular)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head_circular;
    }
    printf("Node inserted: %d\n", value);
}

void deleteNodeCircular(int value)
{
    struct Node *temp = head_circular, *prev = NULL;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (temp->data == value && temp->next == head_circular)
    {
        head_circular = NULL;
        free(temp);
        printf("Node deleted: %d\n", value);
        return;
    }

    do
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                struct Node *last = head_circular;
                while (last->next != head_circular)
                {
                    last = last->next;
                }
                head_circular = temp->next;
                last->next = head_circular;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Node deleted: %d\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head_circular);

    printf("Node not found!\n");
}

void displayListCircular()
{
    struct Node *temp = head_circular;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Circular linked list: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head_circular);
    printf("HEAD\n");
}

// Doubly Linked List Functions
void insertAtEndDoubly(int value)
{
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head_doubly == NULL)
    {
        head_doubly = newNode;
    }
    else
    {
        struct DNode *temp = head_doubly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted: %d\n", value);
}

void deleteNodeDoubly(int value)
{
    struct DNode *temp = head_doubly;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (temp->data == value)
    {
        head_doubly = temp->next;
        if (head_doubly != NULL)
        {
            head_doubly->prev = NULL;
        }
        free(temp);
        printf("Node deleted: %d\n", value);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Node deleted: %d\n", value);
}

void displayListDoubly()
{
    struct DNode *temp = head_doubly;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly linked list: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}