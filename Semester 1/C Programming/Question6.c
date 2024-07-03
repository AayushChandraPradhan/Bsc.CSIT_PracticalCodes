//Program to find power of a given number. Hint: pow(a,b), a and b are user inputs
#include <stdio.h>
#include<math.h>
void main(){
    int a,b,power;
    printf("Enter any two numbers: ");
    scanf("%d %d", &a, &b);
    power = pow(a,b);
    printf("The power of %d %d is: %d", a,b,power);
}

