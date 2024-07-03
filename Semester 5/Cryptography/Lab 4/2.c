
// wap to chec k if the given number is prime using traditional method

#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // 1 or less are not prime
    }
    if (num <= 3) {
        return 1; // 2 and 3 are prime
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0; // Divisible by 2 or 3 (except 2 and 3 themselves)
    }

    // Check divisibility by 6k +/- 1 for efficiency (after handling 2 and 3)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }

    return 1; // Prime if not divisible by 2, 3, or 6k +/- 1 up to its square root
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
