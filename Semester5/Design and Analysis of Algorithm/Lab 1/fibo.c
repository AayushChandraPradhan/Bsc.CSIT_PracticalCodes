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

void printFibonacci(int n) {
    if (n <= 0) return;

    long long first = 0, second = 1, next;
    
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%lld", first);
        } else if (i == 1) {
            printf(", %lld", second);
        } else {
            next = first + second;
            first = second;
            second = next;
            printf(", %lld", next);
        }
    }
    printf("\n");
}

int main() {
    int num1, num2;
    clock_t start, end;
    double cpu_time_used;

    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    start = clock();

    printFibonacci(n);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute the program: %f seconds\n", cpu_time_used);

    return 0;
}
