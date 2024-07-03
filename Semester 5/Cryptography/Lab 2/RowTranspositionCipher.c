#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[], char key[]) {
    int keyLength = strlen(key);
    int plaintextLength = strlen(plaintext);
    int rows = (plaintextLength + keyLength - 1) / keyLength;

    char ciphertext[rows][keyLength];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLength; j++) {
            ciphertext[i][j] = ' ';
        }
    }

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLength && index < plaintextLength; j++) {
            ciphertext[i][j] = plaintext[index++];
        }
    }

    for (int i = 0; i < keyLength; i++) {
        int col = key[i] - '1';
        for (int j = 0; j < rows; j++) {
            printf("%c", ciphertext[j][col]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    printf("Encrypted message: ");
    encrypt(plaintext, key);

    return 0;
}
