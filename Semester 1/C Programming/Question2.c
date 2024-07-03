//Program to add, subtract, multiply, and divide two whole numbers
#include <stdio.h>
void main(){
    int a,b,add,sub,mul,div;
    printf("Enter any two numbers\n");
    scanf("%d %d",&a, &b);
    add = a + b;
    sub = a -b;
    mul = a *b;
    div = a / b ;

    printf("The addition is %d\n", add);
    printf("The substitution is %d\n", sub);
    printf("The multiplication is %d\n", mul);
    printf("The division is %d", div);

}