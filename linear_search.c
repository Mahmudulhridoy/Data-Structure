#include <stdio.h>

int main()
{
    int arr[] = {10, 25, 37, 49, 58, 63, 72, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 100;
    int found = -1;
    int i;
    for (i = 0; i < size; i++) // O(n) //
    {
        if (arr[i] == target)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
        printf("Element found at index %d\n", found);
    else
        printf("Element not found\n");

    return 0;
}
