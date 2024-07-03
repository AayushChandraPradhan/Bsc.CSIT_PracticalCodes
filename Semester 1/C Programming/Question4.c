//Program to convert a temperature given in Celsius to Fahrenheit
#include <stdio.h>
void main(){
    float cel,Fah;
    printf("Enter temperature (Celsius): ");
    scanf("%f",&cel);
    Fah = (cel * 1.8) + 32;
    printf("The value of %.2f (Celsius) in Fahrenheit is %.2f", cel, Fah);
}

