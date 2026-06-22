#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    char array[size];
    int i;

    printf("Enter %d characters:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf(" %c", &array[i]);
    }

    int j;
    char temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("after sorting: ");
    for (i = 0; i < size; i++)
    {
        printf("%c ", array[i]);
    }
    char target;
    printf("Enter the target character: ");
    scanf(" %c", &target);
    int left = 0, right = size - 1;
    int found = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target)
        {
            found = mid;
            break;
        }
        else if (target > array[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found == -1)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("The character '%c' is at index %d.\n", target, found);
    }

    return 0;
}
