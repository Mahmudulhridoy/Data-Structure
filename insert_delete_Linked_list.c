#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

// Function prototypes
void insertAtEnd(int value);
void deleteNode(int value);
void displayList();

// Initialize head to NULL (empty list)
struct Node *head = NULL;

int main()
{
    int choice, value;

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
            insertAtEnd(value);
            break;
        case 2: // Delete node
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 3: // Display list
            displayList();
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

// Function to insert a node at the end of the linked list
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create new node
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    { // If list is empty, make the new node the head
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link the new node at the end
    }
    printf("Node inserted: %d\n", value);
}

// Function to delete a node from the linked list
void deleteNode(int value)
{
    struct Node *temp = head, *prev = NULL;

    // If the head contains the value to be deleted
    if (temp != NULL && temp->data == value)
    {
        head = temp->next; // Change the head
        free(temp);        // Free the old head
        printf("Node deleted: %d\n", value);
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    // Unlink the node and free the memory
    prev->next = temp->next;
    free(temp);
    printf("Node deleted: %d\n", value);
}

// Function to display the linked list
void displayList()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}