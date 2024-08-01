#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    double x = *(const double *)a;
    double y = *(const double *)b;
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

double gapTest(double data[], int n)
{
    qsort(data, n, sizeof(double), compare);
    double maxGap = 0.0;
    for (int i = 1; i < n; i++)
    {
        double gap = data[i] - data[i - 1];
        if (gap > maxGap)
        {
            maxGap = gap;
        }
    }
    return maxGap;
}

int main()
{
    double data[] = {0.15, 0.27, 0.50, 0.72, 0.85};
    int n = sizeof(data) / sizeof(data[0]);
    double maxGap = gapTest(data, n);
    printf("Max observed gap: %.4f\n", maxGap);
    double expectedGap = 1.0 / (n + 1);
    printf("Expected gap (uniform distribution): %.4f\n", expectedGap);
    if (maxGap > expectedGap)
    {
        printf("Reject the null hypothesis: Variables do not appear to be independent.\n");
    }
    else
    {
        printf("Accept the null hypothesis: Variables appear to be independent.\n");
    }
    return 0;
}
