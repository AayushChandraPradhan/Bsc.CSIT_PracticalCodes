//Program to find simple interest.
#include <stdio.h>
void main(){
    int principal, time, rate;
    printf("Enter the Principal Amount: ");
    scanf("%d",&principal);
    printf("\nEnter the Time period (in years): ");
    scanf("%d",&time);
    printf("\nEnter the rate: ");
    scanf("%d",&rate);
    printf("\nThe Simple Interest is: %d", (principal*time*rate)/100);
}
