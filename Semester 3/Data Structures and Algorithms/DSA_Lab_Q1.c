
/*
Code by Dishant 
Date: 23/06/2023
*/

// WAP to Implement Stack with an example through Push, Pop and Display elements {3,6,7,8} in stack.

#include <stdio.h>
#define MAX_SIZE 100

struct Stack
{
    int stack[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, int element)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = element;
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int element = s->stack[s->top];
    s->top--;
    return element;
}

void display(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack Elements: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    // Push elements into the stack
    push(&stack, 3);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);

    // Display the stack
    display(&stack);

    // Pop elements from the stack
    int popped_element = pop(&stack);
    printf("Popped Element: %d\n", popped_element);

    // Display the updated stack
    display(&stack);

    return 0;
}