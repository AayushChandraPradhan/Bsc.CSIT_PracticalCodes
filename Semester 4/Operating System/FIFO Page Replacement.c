// FIFO Page Replacement

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 3
#define NUM_FRAMES 5
int fifoPageReplacement(int pages[], int numPages)
{
    int frames[NUM_FRAMES];
    int pageFaults = 0;
    int i, j, k, nextIndex;
    for (i = 0; i < NUM_FRAMES; i++)
    {
        frames[i] = -1;
    }
    for (i = 0; i < numPages; i++)
    {
        int page = pages[i];
        int found = 0;
        for (j = 0; j < NUM_FRAMES; j++)
        {
            if (frames[j] == page)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            nextIndex = 0;
            for (j = 0; j < NUM_FRAMES; j++)
            {
                if (frames[j] == -1)
                {
                    frames[j] = page;
                    pageFaults++;
                    break;
                }
            }
        }
        if (j == NUM_FRAMES && !found)
        {
            nextIndex = 0;
            for (k = 1; k < NUM_FRAMES; k++)
            {
                if (frames[k] < frames[nextIndex])
                {
                    nextIndex = k;
                }
            }
            frames[nextIndex] = page;
            pageFaults++;
        }
    }
    return pageFaults;
}
int main()
{
    int pages[] = {4, 2, 1, 5, 2, 1, 5, 4, 3, 2, 1, 2, 5, 4, 3, 2, 1, 5, 4, 3,
                   2};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    printf("Number of page faults: %d\n", fifoPageReplacement(pages, numPages));
    return 0;
}
