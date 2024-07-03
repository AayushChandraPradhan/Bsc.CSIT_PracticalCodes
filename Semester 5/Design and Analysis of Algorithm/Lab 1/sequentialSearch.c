#include <stdio.h>
#include <time.h>

int timeToSeconds(int hr, int min, int sec) {
    return hr * 3600 + min * 60 + sec;
}

void printTimeDifference(int seconds) {
    int hr = seconds / 3600;
    int min = (seconds % 3600) / 60;
    int sec = seconds % 60;
    printf("\nTime difference is %02d:%02d:%02d\n", hr, min, sec);
}

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, target, index;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target integer to search for: ");
    scanf("%d", &target);

    start = clock();

    index = sequentialSearch(arr, n, target);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found in the array\n");
    }

    printf("\nTime taken to execute the program: %f seconds\n", cpu_time_used);

    return 0;
}
