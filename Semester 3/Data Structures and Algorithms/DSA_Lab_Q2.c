
/*
Code by Dishant 
Date: 23/06/2023
*/

#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

struct Stack
{
    char stack[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, char element)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = element;
}

char pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    char element = s->stack[s->top];
    s->top--;
    return element;
}

int is_operator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        return 1;
    return 0;
}

int precedence(char operator)
{
    if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '+' || operator== '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *expression)
{
    struct Stack stack;
    initialize(&stack);

    printf("Postfix Expression: ");
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char symbol = expression[i];
        if (isalnum(symbol))
            printf("%c", symbol);
        else if (symbol == '(')
            push(&stack, symbol);
        else if (symbol == ')')
        {
            while (stack.top != -1 && stack.stack[stack.top] != '(')
            {
                printf("%c", pop(&stack));
            }
            if (stack.top != -1 && stack.stack[stack.top] == '(')
                pop(&stack); // Discard the opening parenthesis
        }
        else if (is_operator(symbol))
        {
            while (stack.top != -1 && stack.stack[stack.top] != '(' &&
                   precedence(stack.stack[stack.top]) >= precedence(symbol))
            {
                printf("%c", pop(&stack));
            }
            push(&stack, symbol);
        }
    }

    while (stack.top != -1)
    {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main()
{
    char expression[] = "((a+(b*c))-d)";
    infixToPostfix(expression);
    return 0;
}