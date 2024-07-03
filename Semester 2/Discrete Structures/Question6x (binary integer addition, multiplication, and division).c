// WAP to implement binary integer addition, multiplication, and division

#include <stdio.h>

// Function to perform binary addition
int binaryAddition(int a, int b)
{
    int carry;
    while (b != 0)
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Function to perform binary multiplication
int binaryMultiplication(int a, int b)
{
    int result = 0;
    while (b != 0)
    {
        if (b & 1)
            result = binaryAddition(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

// Function to perform binary division
int binaryDivision(int a, int b)
{
    int quotient = 0;
    while (a >= b)
    {
        a = binaryAddition(a, -b);
        quotient = binaryAddition(quotient, 1);
    }
    return quotient;
}

int main()
{
    int a = 0b1010; // Binary representation of 10
    int b = 0b1100; // Binary representation of 12

    int sum = binaryAddition(a, b);
    printf("Binary Sum: %d\n", sum);

    int product = binaryMultiplication(a, b);
    printf("Binary Product: %d\n", product);

    int quotient = binaryDivision(a, b);
    printf("Binary Quotient: %d\n", quotient);

    return 0;
}
