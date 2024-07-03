// 4. WAP to left shift elements of an array by n position.

#include <stdio.h>

    // Function to rotate the array

    void
    reverseArray(int arr[], int start, int end)

{

    while (start < end)

    {

        int temp = arr[start];

        arr[start] = arr[end];

        arr[end] = temp;

        start++;

        end--;
    }
}

// Function for circular Rotation

void circularRotate(int arr[], int d, int n)
{

    reverseArray(arr, 0, n - 1);

    reverseArray(arr, 0, d - 1);

    reverseArray(arr, d, n - 1);
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)

        printf("%d ", arr[i]);
}

int main()

{

    int n;

    printf("\nEnter the number of elements ");

    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the array elements ");

    for (int i = 0; i < n; i++)

        scanf("%d", &arr[i]);

    int k;

    printf("\nEnter the number of array rotation ");

    scanf("%d", &k);

    circularRotate(arr, k, n);

    printf("\nAfter %d array rotation, the resulting array is \n", k);

    printArray(arr, n);

    return 0;
}