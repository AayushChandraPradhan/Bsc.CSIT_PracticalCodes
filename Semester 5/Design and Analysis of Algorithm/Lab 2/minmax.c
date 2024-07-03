#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n) {
    struct Pair minmax;
    int i;

    if (n % 2 == 0) {
        if (arr[0] > arr[1]) {
            minmax.max = arr[0];
            minmax.min = arr[1];
        } else {
            minmax.max = arr[1];
            minmax.min = arr[0];
        }
        i = 2; // Set the starting index for loop
    } else {
        minmax.max = arr[0];
        minmax.min = arr[0];
        i = 1; // Set the starting index for loop
    }

    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > minmax.max) {
                minmax.max = arr[i];
            }
            if (arr[i + 1] < minmax.min) {
                minmax.min = arr[i + 1];
            }
        } else {
            if (arr[i + 1] > minmax.max) {
                minmax.max = arr[i + 1];
            }
            if (arr[i] < minmax.min) {
                minmax.min = arr[i];
            }
        }
        i += 2; // Increment the index by 2 as two elements are processed in loop
    }

    return minmax;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    struct Pair minmax = getMinMax(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    printf("\nTime executed: %f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}
