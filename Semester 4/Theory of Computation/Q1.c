// Write a program to implement DFA that accepts the strings ending with 01 over an alphabet Σ = {0,1}.

#include <stdio.h>
#define NUM_STATES 3
int dfa(char *input)
{
    int state = 0; // Start state
    while (*input)
    {
        switch (state)
        {
        case 0:
            if (*input == '0')
            {
                state = 1;
            }
            break;
        case 1:
            if (*input == '0')
            {
                state = 1;
            }
            else if (*input == '1')
            {
                state = 2;
            }
            break;
        case 2:
            break;
        }
        input++;
    }
    return state == 2; // Accepted only if ending in state 2}
    int main()
    {
        char input[100];
        printf("Enter a string: ");
        scanf("%s", input);
        if (dfa(input))
        {
            printf("String accepted!\n");
        }
        else
        {
            printf("String not accepted.\n");
        }
        return 0;
    }
}