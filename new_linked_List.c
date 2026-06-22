#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

int main()
{

    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10.90;
    head->next = second;

    second->data = 20.34;
    second->next = third;
    third->data = 30.45;
    third->next = NULL;

    printf("head address: %d\n", head);
    printf("head data: %d\n", head->data);
    printf("head next pointer: %d\n", head->next);
    printf("second address: %d\n", second);
    printf("second data: %d\n", second->data);
    printf("second next pointer: %d\n", second->next);
    printf("third address: %d\n", third);
    printf("third data: %d\n", third->data);
    printf("third next pointer: %d\n", third->next);

    printf("[%d]->[%d][%d]->[%d][%d]->[%d][%d]\n", head, head->data, head->next, second->data, second->next, third->data, third->next);

    printf("linked list traversal fucked up");
}