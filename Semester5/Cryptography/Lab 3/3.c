// Program to find multiplicative inverse (Extended Euclidean Algorithm)

#include <stdio.h>
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
void findMultiplicativeInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
    {
        printf("Multiplicative inverse doesn't exist\n");
    }
    else
    {
        int res = (x % m + m) % m;
        printf("Multiplicative inverse is %d\n", res);
    }
}
int main()
{
    int a, m;
    printf("Enter a and m: ");
    scanf("%d %d", &a, &m);
    findMultiplicativeInverse(a, m);
    return 0;
}