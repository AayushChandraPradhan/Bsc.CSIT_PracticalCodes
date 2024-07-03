/* 
Jet Company gives 5% commission to its salesman if their monthly sales are less than Rs.
10,000 and a 10% commission if it is equal to or greater than Rs. 10,000. Write a program to
calculate commission at the end of the month.
*/
#include<stdio.h>
void main(){
    float com,sal,total;
    printf("Enter the sales of the salesman:");
    scanf("%f",&sal);
    if(sal<10000){
        com=0.05;
    }else{
        com=0.1;
    }
    total=com*sal;
    printf("The total commission is %.2f",total); 

}