
#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[], int rails) {
    int plaintextLength = strlen(plaintext);

    char fence[rails][plaintextLength];

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < plaintextLength; j++) {
            fence[i][j] = '.';
        }
    }

    int row = 0;
    int dir = 1; 
    for (int i = 0; i < plaintextLength; i++) {
        fence[row][i] = plaintext[i];
        row += dir;
        if (row == rails - 1 || row == 0) {
            dir = -dir; 
        }
    }

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < plaintextLength; j++) {
            if (fence[i][j] != '.') {
                printf("%c", fence[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    printf("Encrypted message: ");
    encrypt(plaintext, rails);

    return 0;
}
