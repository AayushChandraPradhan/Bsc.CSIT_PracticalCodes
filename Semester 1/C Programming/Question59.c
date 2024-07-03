//program to find product of first n natural numbers using recursive function.
#include <stdio.h>
int multiplyNumbers(int n);
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Product of natural number up %d = %d", n, multiplyNumbers(n));
    return 0;
}

int multiplyNumbers(int n)
{
    if (n >= 1)
        return n * multiplyNumbers(n - 1);
    else
        return 1;
}