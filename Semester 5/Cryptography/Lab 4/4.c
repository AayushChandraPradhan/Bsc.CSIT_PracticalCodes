#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (gcd(a, m) != 1)
        return -1;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int generatePrime(int bits) {
    int prime = 0;
    while (!prime) {
        int p = rand() % (1 << bits) + (1 << (bits - 1));
        if (isPrime(p))
            prime = p;
    }
    return prime;
}

void generateKeyPair(int *p, int *q, int *n, int *e, int *d, int bits) {
    *p = generatePrime(bits);
    *q = generatePrime(bits);
    *n = *p * *q;
    int phi = (*p - 1) * (*q - 1);
    *e = 2;
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }
    *d = modInverse(*e, phi);
}

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void encrypt(int n, int e, char *message, long long *encrypted) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        encrypted[i] = modExp(message[i], e, n);
    }
    encrypted[i] = -1;  
}

void decrypt(int n, int d, long long *encrypted, char *decrypted) {
    int i;
    for (i = 0; encrypted[i] != -1; i++) {
        decrypted[i] = modExp(encrypted[i], d, n);
    }
    decrypted[i] = '\0';
}

int main() {
    srand(time(0)); 

    int p, q, n, e, d, bits;
    printf("Enter bit size for prime generation: ");
    scanf("%d", &bits);

    generateKeyPair(&p, &q, &n, &e, &d, bits);
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    char message[256];
    printf("Enter the message to encrypt: ");
    scanf(" %[^\n]", message);

    long long encrypted[256];
    encrypt(n, e, message, encrypted);

    printf("Encrypted Message: ");
    for (int i = 0; encrypted[i] != -1; i++) {
        printf("%lld ", encrypted[i]);
    }
    printf("\n");

    char decrypted[256];
    decrypt(n, d, encrypted, decrypted);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}
