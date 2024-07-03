//Program to find area and perimeter of a rectangle
#include <stdio.h>
void main(){
int area,perimeter,lenght,breadth;
printf("Enter the lenght of rectangle: ");
scanf("%d",&lenght);
printf("\nEnter the breadth of rectangle: ");
scanf("%d",&breadth);
area = lenght * breadth;
perimeter = 2*(lenght + breadth);
printf("The area of rectangle is: %d",area);
printf("\nThe perimeter of rectangle is: %d",perimeter);

}
