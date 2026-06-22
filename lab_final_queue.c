#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int front = -1, rear = -1;
queue[MAX];

void enque(char c)
{

    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = c;
    printf("%c added to queue\n", c);
}
char dequeue(char c)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return c;
    }
    printf("%c removed from the  queue\n", queue[front]);
    front++;
}
void display()
{
    int i;
    printf("queue elements are :\n");
    for (i = front; i <= rear; i++)
    {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

int main()
{

    char a, b, c, d, e;
    printf("enter character to enqueue\n");
    scanf(" %c", &a);
    scanf(" %c", &b);
    scanf(" %c", &c);
    scanf(" %c", &d);

    enque(c);
    enque(d);
    enque(a);
    enque(b);

    printf("enter character to dequeue\n");
    scanf(" %c", &e);
    printf("the deleting value is %c ", dequeue(c));

    printf("\nnow its time to display.\n");
    display();

    printf("thank you for !!!!!!!");
}
