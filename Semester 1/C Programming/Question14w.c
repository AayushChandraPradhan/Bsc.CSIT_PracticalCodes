//Program to express a length given in millimeters in meters, centimeters, and millimeters.
#include<stdio.h>
void main(){
    int length;
    float m,cm,mm;
    printf("Enter the length in millimeters:");
    scanf("%d",&length);
    m=length/1000;
    cm=(length%1000)/10;
    mm=length%10;
    printf("The length in meters, centimeters, and millimeters is %f meters %f centimter and %d millimeter",m,cm,mm);
}