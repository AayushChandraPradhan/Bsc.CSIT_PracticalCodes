/* create a structure to specify data on customers in a bank with the parameters Acct. No., 
Name, Balance in Account. Assume there are 1000 customers in the bank. Write a program 
to store the data in “CUST.DAT” file and print the Acct. No. and Name of each customer 
with balance below Rs. 1000. */

#include<stdio.h>
#include<stdlib.h>
#define N 1000;
struct customer{
    int accno;
    char name[30];
    float balance;
}c[1000];
void main(){
    int n=5;
    FILE *fp;
    fp=fopen("CUST.dat","w");
    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("Enter the name of the customer:");
        gets(c[i].name);
        printf("Enter the account number:");
        scanf("%d",&c[i].accno);
        printf("Enter the balance:");
        scanf("%f",&c[i].balance);
        fprintf(fp,"%d\t %s\t %.f\n",c[i].accno,c[i].name,c[i].balance);
    }
    printf("The name and account number of customer with balance below Rs.1000 is:\n");
    for(int i=0;i<n;i++){
        if(c[i].balance<1000){
            printf("%s\t %d\n",c[i].name,c[i].accno);
        }
    }
}