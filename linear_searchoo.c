#include <stdio.h>

int linearSearch(int arr[], int size, int target)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 25, 37, 49, 58, 63, 72, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 49;

    int result = linearSearch(arr, size, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
