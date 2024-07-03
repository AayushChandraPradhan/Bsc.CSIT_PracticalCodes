// Program to compare two numbers.
#include <stdio.h>

void main() {
   int a, b;
 printf("Enter number a : ");
    scanf("%d", &a);
 printf("Enter number b : ");
    scanf("%d", &b);

   if(a > b)
      printf("a is greater than b");
   else
      printf("a is not greater than b");
}