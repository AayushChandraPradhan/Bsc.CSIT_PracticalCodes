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

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();

    bubbleSort(arr, n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nTime taken to execute bubble sort: %f seconds\n", cpu_time_used);

    return 0;
}
