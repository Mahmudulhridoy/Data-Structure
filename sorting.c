#include <stdio.h>
int main()
{
    int n;
    printf("enter the array size: ");
    scanf("%d", &n);
    int array[n];

    int i;
    printf("array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("enter array elements-%d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int temp, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {

                temp = array[i]; // data swapping
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("\narray in ascending order: \n");
    for (i = 0; i < n; i++)
    {
        printf("elements in position-%d: %d \n", i + 1, array[i]);
    }
}
