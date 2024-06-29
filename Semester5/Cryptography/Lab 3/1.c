// Program to implement Euclidean Algorithm (GCD)

#include <stdio.h>
int gcd(int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    int m, n;
    printf("Enter the first number: ");
    scanf("%d", &m);
    printf("Enter the second number: ");
    scanf("%d", &n);
    int result = gcd(m, n);
    printf("The GCD of %d and %d is %d\n", m, n, result);
    return 0;
}