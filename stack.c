#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void printStack()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int i;
        printf("Stack elements: ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int value; 
    scanf("%d",&value);
    push(value);
    value=20;
    push(value);
    value=30;
    push(value);
    printStack();

    printf("Popped: %d\n", pop());
    printStack();

    return 0;
}
