//Program to convert pounds to kilograms
#include <stdio.h>
void main(){
    float pounds, kilo;
    printf("Enter the weight to convert: ");
    scanf("%f", &pounds);
    kilo = pounds / 2.2;
    printf("%f Pounds = %f kg", pounds, kilo);
    
}