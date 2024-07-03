// find the totient of given number

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int totient_brute_force(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int phi = totient_brute_force(num);
    printf("The totient of %d (brute force) is %d\n", num, phi);

    return 0;
}

