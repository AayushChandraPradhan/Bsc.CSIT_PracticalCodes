// program to count number of times a function executes using static local variable
#include<stdio.h>
int stv(){
static int n;
return n++; 
}
void main(){
int n;
printf("Enter the value of n:");
scanf("%d",&n);
for(int i=0;i<n;i++){
stv();
}
printf("The number of times function was executed was %d",stv());
}
