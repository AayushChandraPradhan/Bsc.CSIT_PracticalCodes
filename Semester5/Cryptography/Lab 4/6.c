#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
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

unsigned long long mod_inv(unsigned long long a, unsigned long long mod) {
    unsigned long long m0 = mod, t, q;
    unsigned long long x0 = 0, x1 = 1;

    if (mod == 1) return 0;

    while (a > 1) {
        q = a / mod;
        t = mod;

        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

unsigned long long random_range(unsigned long long min, unsigned long long max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));

    unsigned long long p = 23; 
    unsigned long long g = 5;  

    unsigned long long x = random_range(2, p - 2);

    unsigned long long y = mod_exp(g, x, p);

    printf("Public key (p, g, y) = (%llu, %llu, %llu)\n", p, g, y);
    printf("Private key x = %llu\n", x);

    unsigned long long m = 10;

    unsigned long long k = random_range(2, p - 2);
    unsigned long long a = mod_exp(g, k, p);
    unsigned long long b = (m * mod_exp(y, k, p)) % p;

    printf("Plaintext message m = %llu\n", m);
    printf("Ciphertext (a, b) = (%llu, %llu)\n", a, b);

    unsigned long long s = mod_exp(a, x, p);
    unsigned long long s_inv = mod_inv(s, p);
    unsigned long long decrypted_m = (b * s_inv) % p;

    printf("Decrypted message = %llu\n", decrypted_m);

    return 0;
}
