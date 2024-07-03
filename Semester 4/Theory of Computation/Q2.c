// Write a program to implement DFA that accepts the strings having substring as 001 over an alphabet Σ = {0,1}.

#include <stdio.h>

#define NUM_STATES 3

int dfa(char* input) {
  int state = 0; 

  while (*input) {
    switch (state) {
      case 0:
        if (*input == '0') {
          state = 1;
        } else {
          state = 0;
        }
        break;
      case 1:
        if (*input == '0') {
          state = 2;
        } else {
          state = 0;
        }
        break;
      case 2:
        if (*input == '1') {
          state = 3;
        } else {
          state = 0;
        }
        break;
      default:
        return 0;
    }
    input++;
  }

  return state == 3;
}

int main() {
  char input[100];

  printf("Enter a string: ");
  scanf("%s", input);

  if (dfa(input)) {
    printf("String accepted (contains substring \"001\")\n");
  } else {
    printf("String not accepted.\n");
  }

  return 0;
}
