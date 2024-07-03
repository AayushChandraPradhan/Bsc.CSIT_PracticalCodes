//Program to find the rupee equivalent of U.S. dollars

#include<stdio.h>
void main(){
float rup,us;
printf("Enter the amount (NPR): ");
scanf("%f",&rup);
us = rup / 127;
printf("NPR %.4f = USD %.4f\n", rup,us);
printf("USD %.4f = NPR %.4f", us,rup);

}