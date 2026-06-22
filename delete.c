#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int array[n];
    int i;

    for (i = 0; i < n; i++)
    {

        printf("enter the elements-%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int index, j, temp;
    printf("enter the endex of inserting value: ");
    scanf("%d", &index);
    int value;
    printf("enter the value: ");
    scanf("%d", &value);

    for (i = n - 1; i >= index; i--)
    {

        array[i + 1] = array[i];
    }
    array[index] = value;
    printf("array after inserting the value: ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", array[i]);
    }
}