
/*
Code by Dishant 
Date: 23/06/2023
*/

// WAP to Implement Stack with an example through Push, Pop and Display elements {3,6,7,8} in stack.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// struct named stack is declared to push elements into an array named item.
struct stack
{
    int item[MAX]; // declaring an array to store items
    int top;
};

typedef struct stack st;

void push(st *, int); // push function prototype
int pop(st *);        // pop function prototype
void display(st *);   // display function prototype

void main()
{
    int data, ch, x;
    st *s;
    s->top = -1; // make stack empty

    printf("Choose 1-4\n");
    printf("1:push\n 2:pop\n 3:display\n 4:exit \n");

    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to be inserted:\n");
            scanf("%d", &data);
            push(s, data);
            break;

        case 2:
            x = pop(s);
            printf("\n popped item is:");
            printf("%d\n", x);
            break;

        case 3:
            display(s);
            break;

        default:
            exit(1);
        }

    } while (ch < 4);
}

void push(st *s, int d) // push function definition
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        ++s->top;
        s->item[s->top] = d;
    }
}

int pop(st *s) // pop function definition
{
    int itm;
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return (0);
    }
    else
    {
        itm = s->item[s->top];
        s->top--;
        return (itm);
    }
}

void display(st *s) // display function definition
{
    int i;
    if (s->top == -1)
    {
        printf("there is no item to display.");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\t", s->item[i]);
        }
    }
}
