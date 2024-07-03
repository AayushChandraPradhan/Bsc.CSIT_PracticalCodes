// 5. WAP to right shift elements of an array by n position.

#include <stdio.h>

int main()

{

    int length;

    printf("Enter the length of the array: ");

    scanf("%d", &length);

    int arr[length];

    printf("Enter the array elements: ");

    for (int i = 0; i < length; i++)

        scanf("%d", &arr[i]);

    int n;

    printf("Enter the index of rotation ");

    scanf("%d", &n);

    printf("Original array: \n");

    for (int i = 0; i < length; i++)

    {

        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++)

    {

        int j, temp;

        temp = arr[length - 1];

        for (j = length - 1; j > 0; j--)

        {

            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }

    printf("\n");

    printf("Array after circular rotation: \n");

    for (int i = 0; i < length; i++)

    {

        printf("%d ", arr[i]);
    }

    return 0;
}