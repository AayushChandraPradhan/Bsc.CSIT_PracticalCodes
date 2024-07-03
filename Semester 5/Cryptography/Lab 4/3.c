

// implement miller algorithm for testing primarily

#include <stdio.h>
#include <stdlib.h>

// Function to perform modular exponentiation
// It returns (base^exp) % mod
unsigned long long modular_exponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// This function performs the Miller-Rabin test
// Returns 0 if n is composite, returns 1 if n is probably prime
int miller_rabin_test(unsigned long long d, unsigned long long n) {
    unsigned long long a = 2 + rand() % (n - 4);
    unsigned long long x = modular_exponentiation(a, d, n);

    if (x == 1 || x == n - 1) {
        return 1;
    }

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) {
            return 0;
        }
        if (x == n - 1) {
            return 1;
        }
    }

    return 0;
}

// Main function to perform Miller-Rabin primality test
// Returns 1 if n is probably prime, returns 0 if n is composite
int is_prime(unsigned long long n, int k) {
    if (n <= 1 || n == 4) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }

    // Find d such that d * 2^r = n - 1 for some r >= 1
    unsigned long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        if (!miller_rabin_test(d, n)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    unsigned long long num;
    int k = 4; // Number of iterations

    printf("Enter an integer to test for primality: ");
    scanf("%llu", &num);

    if (is_prime(num, k)) {
        printf("%llu is probably a prime number.\n", num);
    } else {
        printf("%llu is a composite number.\n", num);
    }

    return 0;
}
