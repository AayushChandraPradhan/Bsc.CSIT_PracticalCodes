//Program to find area and circumference of circle
#include <stdio.h>
void main(){
    const float pi = 3.14;
    float area,circumference,radius;
    printf("Enter the radius of circle: ");
    scanf("%f", &radius);
    area = pi * radius * radius;
    circumference = 2 * pi * radius;  
    printf("The area of circle is %.2f\n", area);
    printf("The circumference of circle is %.2f",circumference);
}

