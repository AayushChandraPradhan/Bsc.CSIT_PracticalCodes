#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double random_double() {
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

int main() {
    int num_simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    srand(time(0)); 

    int points_inside_circle = 0;
    double x, y, distance;

    for (int i = 0; i < num_simulations; i++) {
        x = random_double();
        y = random_double();
        distance = x * x + y * y;
        if (distance <= 1.0) {
            points_inside_circle++;
        }
    }

    double pi_estimate = (double)points_inside_circle / num_simulations * 4.0;
    double circumference_estimate = pi_estimate * 2.0;

    printf("Estimated Pi: %.6f\n", pi_estimate);
    printf("Estimated Circumference of Unit Circle: %.6f\n", circumference_estimate);

    return 0;
}
