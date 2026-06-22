#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted: %d\n", value);
}

void deleteNode(int value)
{
    struct Node *temp = head, *prev = NULL;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (temp->data == value && temp->next == head)
    {
        head = NULL;
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
                struct Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                head = temp->next;
                last->next = head;
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
    } while (temp != head);

    printf("Node not found!\n");
}

void displayList()
{
    struct Node *temp = head;

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
    } while (temp != head);
    printf("HEAD\n");
}

int main()
{
    insertAtEnd(5);
    insertAtEnd(15);
    insertAtEnd(25);
    displayList();

    deleteNode(15);
    displayList();

    return 0;
}
