// Q.1 WAP to traverse an array.

#include <stdio.h>

// Function to traverse and print the array

void printArray(int *arr, int n)

{

    int i;

    printf("Array: ");

    for (i = 0; i < n; i++)

    {

        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()

{

    int arr[] = {6, 3, -4, 1, 0, -8};

    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    return 0;
}