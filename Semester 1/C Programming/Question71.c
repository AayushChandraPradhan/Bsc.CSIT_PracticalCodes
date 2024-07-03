//Program to sort numbers stored in an array using bubble sort in descending order.
#include <stdio.h>
void main()
{
    int arr[] = {1, 9, 3, 7, 4, 10, 5, 11, 6, 14};
    printf("Sorted array in descending order\n");
    int l = sizeof(arr) / sizeof(arr[0]);
    for (int j = 0; j < l; j++)
    {
        for (int i = 0; i < l - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        printf("%d\t", arr[i]);
    }
}