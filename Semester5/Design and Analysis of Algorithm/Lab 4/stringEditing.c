#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printExecutionTime(clock_t start, clock_t end) {
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime executed: %f seconds\n", cpu_time_used);
}

int main() {
    char str1[100], str2[100], temp[100];
    int choice;
    clock_t start, end;

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character if present

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character if present

    printf("Select operation:\n");
    printf("1. Concatenate\n");
    printf("2. Substring Extraction\n");
    printf("3. Replace substring\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    start = clock();

    switch (choice) {
        case 1:
            strcpy(temp, str1);
            strcat(temp, str2);
            printf("Concatenated string: %s\n", temp);
            break;
        case 2:
            printf("Enter start index and length for substring (space-separated): ");
            int startIdx, length;
            scanf("%d %d", &startIdx, &length);
            strncpy(temp, str1 + startIdx, length);
            temp[length] = '\0'; // Null terminate the substring
            printf("Extracted substring: %s\n", temp);
            break;
        case 3:
            printf("Enter substring to replace and its replacement: ");
            char oldSub[50], newSub[50];
            scanf("%s %s", oldSub, newSub);
            
            char *pos = strstr(str1, oldSub);
            if (pos != NULL) {
                strcpy(temp, str1);
                pos = strstr(temp, oldSub);
                int index = pos - temp;
                strcpy(temp + index, newSub);
                strcat(temp, pos + strlen(oldSub));
                printf("String after replacement: %s\n", temp);
            } else {
                printf("Substring not found in string 1.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    end = clock();
    printExecutionTime(start, end);

    return 0;
}
