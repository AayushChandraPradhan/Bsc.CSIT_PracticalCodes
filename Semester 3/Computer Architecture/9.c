// 9. WAP to compute 2’s complement of a Binary number.

#include <stdio.h>

#include <string.h>

int main()

{

    char binaryNumber[100], onesComplement[100], twosComplement[100];

    int counter, error = 0, digitCount, carry = 1;

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

    for (counter = digitCount - 1; counter >= 0; counter--)

    {

        if (onesComplement[counter] == '1' && carry == 1)

        {

            twosComplement[counter] = '0';
        }

        else if (onesComplement[counter] == '0' && carry == 1)

        {

            twosComplement[counter] = '1';

            carry = 0;
        }

        else

        {

            twosComplement[counter] = onesComplement[counter];
        }
    }

    twosComplement[digitCount] = '\0';

    printf("2's Complement : %s", twosComplement);

    return 0;
}