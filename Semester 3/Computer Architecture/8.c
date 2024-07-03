// 8. WAP to compute 1’s complement of a Binary number.

#include <stdio.h>

#include <string.h>

int main()

{

    char binaryNumber[100], onesComplement[100];

    int counter, error = 0, digitCount;

    printf("Enter a Binary Number: ");

    scanf("%s", binaryNumber);

    digitCount = strlen(binaryNumber);

    for (counter = 0; counter < digitCount; counter++)

    {

        if (binaryNumber[counter] == '1')

        {

            onesComplement[counter] = '0';
        }

        else if (binaryNumber[counter] == '0')

        {

            onesComplement[counter] = '1';
        }

        else

        {

            printf("Error :( ");

            return 1;
        }
    }

    onesComplement[digitCount] = '\0';

    printf("1's Complement : %s", onesComplement);

    return 0;
}