// Program to calculate discount. If purchased amount is greater than or equal to 1000, discount is 5%.

#include <stdio.h>
void main(){
    float purchase, discount,final;
    printf("Amount Purchased: ");
    scanf("%f", &purchase);
    if(purchase >= 1000){
        discount = 0.05;
    }
    else{
        discount = 0;

    }
final = purchase - discount * purchase;
printf("Final price after discount is %.2f",final);

}