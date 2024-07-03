//Write a program to calculate area and perimeter of a rectangle using macros
#include <stdio.h>
#define const 2
void main()
{
    float l,b;
    printf("lenght: ");
    scanf("%f",&l);
    printf("breadth: ");
    scanf("%f",&b);

    printf("Area = %.2f",l*b);
    printf("Perimeter = %.2f", const*l*b);
}