#include <stdio.h>
#include <stdlib.h>

double calculateMean(int data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double autoCorrelation(int data[], int n, int lag) {
    double mean = calculateMean(data, n);
    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < n - lag; i++) {
        numerator += (data[i] - mean) * (data[i + lag] - mean);
    }
    
    for (int i = 0; i < n; i++) {
        denominator += (data[i] - mean) * (data[i] - mean);
    }
    
    return numerator / denominator;
}

int main() {
    int data[] = {1, 0, 1, 1, 0, 0, 1, 0, 1, 1};  
    int n = sizeof(data) / sizeof(data[0]);
    int lag = 1; 

    double result = autoCorrelation(data, n, lag);
    printf("Autocorrelation coefficient for lag %d: %.4f\n", lag, result);

    if (result > 0.2) {
        printf("The sequence may not be random.\n");
    } else {
        printf("The sequence appears to be random.\n");
    }

    return 0;
}
