// Write macros to compute area and circumference of circle and make a program to use this macro.
#include <stdio.h>
#define PI 3.14

void main()
{
    float radius, area, circumference;
    printf("radius: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("The area of circle is: %.2f \n", area);
    printf("The circumference of circle is: %.2f \n", circumference);
}