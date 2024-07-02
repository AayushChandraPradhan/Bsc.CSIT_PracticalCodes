#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int editDistance(char *str1, char *str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j],      // Remove
                                   dp[i][j - 1],      // Insert
                                   dp[i - 1][j - 1]); // Replace
            }
        }
    }
    return dp[m][n];
}

void printExecutionTime(clock_t start, clock_t end)
{
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime executed: %f seconds\n", cpu_time_used);
}

int main()
{
    char str1[100], str2[100];
    clock_t start, end;

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character if present

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character if present

    start = clock();
    int result = editDistance(str1, str2, strlen(str1), strlen(str2));
    end = clock();

    printf("The minimum edit distance is: %d\n", result);
    printExecutionTime(start, end);

    return 0;
}
