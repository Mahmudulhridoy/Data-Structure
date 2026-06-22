#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum size of the stack

int stack[MAX];
int top = -1; // initially stack is empty

// Function to push an element into the stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int popped = stack[top];
        top--;
        return popped;
    }
}

// Function to display the stack
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, value;

    printf("Stack Operations:\n");

    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value);
        break;
    case 2:
        value = pop();
        if (value != -1)
            printf("Popped value: %d\n", value);
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid choice\n");
    }

    return 0;
}
