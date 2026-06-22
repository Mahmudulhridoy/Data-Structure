#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid size. Size must be a positive integer.\n");
        return 1;
    }

    int array[n];
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int left = 0;
    int right = n - 1;
    int found = -1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (array[mid] == key)
        {
            found = mid;
            break;
        }
        else if (array[mid] < key)
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
        printf("%d not found\n", key);
    }
    else
    {
        printf("Element found at index %d\n", found);
    }
    int j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i]; // ascending the aray
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("inserting into sorted array...\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
