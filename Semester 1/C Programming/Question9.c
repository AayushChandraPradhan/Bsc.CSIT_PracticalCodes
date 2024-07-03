//Program to find price of n mangos given the price of a dozen mangos
#include <stdio.h>
void main()
{
    int a,b;
    printf("The amount (number) of mangoes: ");
    scanf("%d",&a);
    printf("The price of given mangoes: ");
    scanf("%d",&b);
    float onemango = (float) b/a;
    double dozenmango = onemango * 12;
    printf("The price of dozen mangoes is %.2f", dozenmango);    

}
