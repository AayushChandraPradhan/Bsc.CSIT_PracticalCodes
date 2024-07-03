//Program to print the largest number among three numbers input by the user.

#include<stdio.h>
void main(){
    float a,b,c,d;
    printf("Enter first number: ");
    scanf("%f",&a);
    printf("Enter second number: ");
    scanf("%f",&b);
    printf("Enter third number: ");
    scanf("%f",&c);
    if(a>b&&a>c){
        d=a;
    }else if(b>a&&b>c){
        d=b;
    }else {
        d=c;
    }
    printf("The greatest number is %.2f",d);
}