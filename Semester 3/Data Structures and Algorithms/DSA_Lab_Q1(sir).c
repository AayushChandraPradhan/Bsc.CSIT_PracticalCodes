// https://www.onlinegdb.com/online_c++_compiler
// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int count = 0;

// Creating a stack

struct stack 
{
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) 
{
  s->top = -1;
}

// Check if the stack is full

int isfull(st *s) 
{
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty

int isempty(st *s) 
{
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack

void push(st *s, int newitem) 
{
  if (isfull(s)) 
  {
    printf("STACK FULL");
  } 
  else 
  {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Remove element from stack

void pop(st *s) 
{
  if (isempty(s)) 
  {
    printf("\n STACK EMPTY \n");
  } 
  else 
  {
    printf("Item popped= %d", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(st *s) 
{
  printf("Stack: ");
  for (int i = 0; i < count; i++) 
  {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Driver code
int main() 
{
  int choice, x;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);
  
  do 
 {
  printf("1.push\n2.pop\n3.Display\n4.Exit\n");
  scanf("%d",&choice);
   
	switch(choice)
	{
		case 1: 
			{ 
			printf("Enter the number to Add\t");
          		scanf("%d", &x);
			push(s,x); 
			break;
			}
		case 2:pop(s);break;
		case 3:printStack(s);break;
		case 4:exit(1);
		default:printf("Invalid choice");
	
	}}
while (choice!=4);

}






