//Program to print a six digit integer in reverse order.

#include<stdio.h>
void main(){
    int number,reverse=0;
    printf("Enter any number:");
    scanf("%6d",&number);
    while(number!=0){
        reverse=reverse*10+number%10;
        number/=10;
    }
    printf("The reversed number is: %d",reverse);
}