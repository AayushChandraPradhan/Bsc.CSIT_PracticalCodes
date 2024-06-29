#include <stdio.h>
#include <time.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("The GCD of %d and %d is %d\n", num1, num2, result);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute the program: %f seconds\n", cpu_time_used);

    return 0;
}
