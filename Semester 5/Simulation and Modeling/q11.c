#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie() {
    return (rand() % 6) + 1;
}

int main() {
    int numberOfRolls, roll1, roll2;

    srand(time(NULL));

    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &numberOfRolls);

    for (int i = 0; i < numberOfRolls; i++) {
        roll1 = rollDie();
        roll2 = rollDie();
        printf("Roll %d: Die 1: %d, Die 2: %d, Sum: %d\n", i + 1, roll1, roll2, roll1 + roll2);
    }

    return 0;
}
