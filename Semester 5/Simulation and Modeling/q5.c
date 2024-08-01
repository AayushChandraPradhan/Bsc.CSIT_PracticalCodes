#include <stdio.h>
#include <math.h>

double chiSquare(int observed[], int expected[], int n) {
    double chiSquareVal = 0.0;
    for (int i = 0; i < n; i++) {
        chiSquareVal += pow(observed[i] - expected[i], 2) / (double)expected[i];
    }
    return chiSquareVal;
}

double criticalChiSquare(int df) {
    double criticalValues[] = {3.841, 5.991, 7.815}; 
    if (df >= 1 && df <= 3) {
        return criticalValues[df - 1];
    } else {
        return -1.0;
    }
}

int main() {
    int observed[] = {22, 18, 30};
    int expected[] = {25, 25, 20};
    int n = sizeof(observed) / sizeof(observed[0]);
    double chiSquareValue = chiSquare(observed, expected, n);
    int df = n - 1;

    printf("Chi-square value: %.2f\n", chiSquareValue);
    printf("Degrees of freedom: %d\n", df);

    double criticalValue = criticalChiSquare(df);
    if (criticalValue < 0) {
        printf("Invalid degrees of freedom for critical value lookup.\n");
        return 1;
    }

    printf("Critical Chi-square value at alpha=0.05: %.2f\n", criticalValue);

    if (chiSquareValue > criticalValue) {
        printf("Reject the null hypothesis: The observed frequencies are not uniformly distributed.\n");
    } else {
        printf("Accept the null hypothesis: The observed frequencies are uniformly distributed.\n");
    }

    return 0;
}
