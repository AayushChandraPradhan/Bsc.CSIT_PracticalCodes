#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    double x = *(const double *)a;
    double y = *(const double *)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}

double ksTestUniform(double data[], int n, double *Dplus, double *Dminus) {
    qsort(data, n, sizeof(double), compare);
    *Dplus = 0.0;
    *Dminus = 0.0;

    for (int i = 0; i < n; i++) {
        double CDF = (double)(i + 1) / n;
        double D1 = fabs(CDF - data[i]);
        double D2 = fabs(data[i] - (double)i / n);

        if (D1 > *Dplus) {
            *Dplus = D1;
        }
        if (D2 > *Dminus) {
            *Dminus = D2;
        }
    }

    double KS = fmax(*Dplus, *Dminus);
    return KS;
}

int main() {
    double data[] = {0.12, 0.32, 0.45, 0.56, 0.68};
    int n = sizeof(data) / sizeof(data[0]);
    double Dplus, Dminus;
    double KS = ksTestUniform(data, n, &Dplus, &Dminus);

    printf("Dplus: %.4f\n", Dplus);
    printf("Dminus: %.4f\n", Dminus);
    printf("Max(Dplus, Dminus): %.4f\n", fmax(Dplus, Dminus));
    printf("KS statistic: %.4f\n", KS);

    double criticalValue = 1.36 / sqrt(n);
    if (KS > criticalValue) {
        printf("Reject the null hypothesis: The sample is not uniformly distributed.\n");
    } else {
        printf("Accept the null hypothesis: The sample is uniformly distributed.\n");
    }

    return 0;
}
