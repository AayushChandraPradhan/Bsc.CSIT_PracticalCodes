#include <stdio.h>
#include <stdlib.h>

void countDigits(int number, int *count) {
    while (number > 0) {
        count[number % 10]++;
        number /= 10;
    }
}

const char* categorizeThreeDigitPattern(int count[]) {
    int distinct = 0, pair = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] == 1) distinct++;
        if (count[i] == 2) pair++;
    }

    if (distinct == 3) return "All Different";
    if (pair == 1) return "One Pair";
    if (count[0] == 3 || count[1] == 3 || count[2] == 3 || count[3] == 3 || count[4] == 3 ||
        count[5] == 3 || count[6] == 3 || count[7] == 3 || count[8] == 3 || count[9] == 3)
        return "Three of a Kind";

    return "Invalid Pattern";
}

const char* categorizeFourDigitPattern(int count[]) {
    int distinct = 0, pair = 0, triple = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] == 1) distinct++;
        if (count[i] == 2) pair++;
        if (count[i] == 3) triple++;
    }

    if (distinct == 4) return "All Different";
    if (pair == 2) return "Two Pair";
    if (pair == 1 && triple == 1) return "Full House";
    if (triple == 1) return "Three of a Kind";
    if (count[0] == 4 || count[1] == 4 || count[2] == 4 || count[3] == 4 || count[4] == 4 ||
        count[5] == 4 || count[6] == 4 || count[7] == 4 || count[8] == 4 || count[9] == 4)
        return "Four of a Kind";

    return "Invalid Pattern";
}

int main() {
    int threeDigitNumbers[] = {123, 122, 111, 321, 112};
    int fourDigitNumbers[] = {1234, 1122, 1233, 1111, 2233};
    int nThree = sizeof(threeDigitNumbers) / sizeof(threeDigitNumbers[0]);
    int nFour = sizeof(fourDigitNumbers) / sizeof(fourDigitNumbers[0]);

    printf("Poker Test for Three-Digit Numbers:\n");
    for (int i = 0; i < nThree; i++) {
        int count[10] = {0};
        countDigits(threeDigitNumbers[i], count);
        printf("Number: %d, Pattern: %s\n", threeDigitNumbers[i], categorizeThreeDigitPattern(count));
    }

    printf("\nPoker Test for Four-Digit Numbers:\n");
    for (int i = 0; i < nFour; i++) {
        int count[10] = {0};
        countDigits(fourDigitNumbers[i], count);
        printf("Number: %d, Pattern: %s\n", fourDigitNumbers[i], categorizeFourDigitPattern(count));
    }

    return 0;
}
