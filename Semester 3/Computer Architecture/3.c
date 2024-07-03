// 3. WAP to add elements of an array.

#include <stdio.h>

int main()

{

    int arr[100], size, i, sum = 0;

    printf("Enter array size of an array: ");

    scanf("%d", &size);

    printf("Enter array elements\n");

    for (i = 0; i < size; i++)

        scanf("%d", &arr[i]);

    // add all elements to the variable sum.

    for (i = 0; i < size; i++)

        sum = sum + arr[i];

    // print the result

    printf("Sum of the array = %d\n", sum);

    return 0;
}