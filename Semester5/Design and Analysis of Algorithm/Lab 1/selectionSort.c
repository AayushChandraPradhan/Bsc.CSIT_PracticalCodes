#include <stdio.h>
#include <time.h>

int timeToSeconds(int hr, int min, int sec) {
    return hr * 3600 + min * 60 + sec;
}

void printTimeDifference(int seconds) {
    int hr = seconds / 3600;
    int min = (seconds % 3600) / 60;
    int sec = seconds % 60;
    printf("Time difference is %02d:%02d:%02d\n", hr, min, sec);
}

void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();

    selectionSort(arr, n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nTime taken to execute selection sort: %f seconds\n", cpu_time_used);

    return 0;
}
