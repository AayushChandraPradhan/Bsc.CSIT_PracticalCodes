#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_die() {
    return rand() % 6 + 1; 
}

void simulate_dice_rolls(int num_simulations) {
    int sum_frequencies[13] = {0};
    
    for (int i = 0; i < num_simulations; i++) {
        int die1 = roll_die();
        int die2 = roll_die();
        int sum = die1 + die2;
        sum_frequencies[sum]++;
    }
    
    printf("Sum\tFrequency\tProbability\n");
    for (int sum = 2; sum <= 12; sum++) {
        double probability = (double)sum_frequencies[sum] / num_simulations;
        printf("%d\t%d\t\t%.4f\n", sum, sum_frequencies[sum], probability);
    }
}

int main() {
    srand(time(0));
    
    int num_simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);
    
    simulate_dice_rolls(num_simulations);
    
    return 0;
}
