#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y)
{
    int temp = x;
    x = y;
    y = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int n)
{
    int *stack = (int *)malloc(n * sizeof(int));

    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0)
    {
        int high = stack[top--];
        int low = stack[top--];

        int p = partition(arr, low, high);

        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }

    free(stack);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterative(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
