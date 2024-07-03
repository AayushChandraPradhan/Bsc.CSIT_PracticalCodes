// Program to verify given numbers are relatively prime or not.

#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int areRelativelyPrime(int a, int b)
{
    return gcd(a, b) == 1;
}
int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if (areRelativelyPrime(num1, num2))
        printf("%d and %d are relatively prime.\n", num1, num2);
    else
        printf("%d and %d are not relatively prime.\n", num1, num2);
    return 0;
}