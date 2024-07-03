// Program to find the additive inverse.
#include <stdio.h>
int additive_inverse(int a, int n)
{
    return (n - a) % n;
}
int main()
{
    int a, n;
    printf("Enter the number: ");
    scanf("%d", &a);
    printf("Enter the modulo: ");
    scanf("%d", &n);
    int result = additive_inverse(a, n);
    printf("The additive inverse of %d under modulo %d is %d\n", a, n, result);
    return 0;
}
