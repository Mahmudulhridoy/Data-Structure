#include<stdio.h>
#include<stdlib.h>

#define size 100
int queue[size];
int front =-1, rear=-1;
int isFull()
{
    if(rear==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(front==-1 || front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int value)
{
    if(isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("%d inserted\n",value);
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d deleted\n",queue[front]);
        front++;
    }
}
void display()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice, value;
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
