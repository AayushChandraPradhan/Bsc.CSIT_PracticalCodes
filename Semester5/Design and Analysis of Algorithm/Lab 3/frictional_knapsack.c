#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return (ratioB > ratioA) - (ratioB < ratioA); // Sort in descending order of value/weight ratio
}

double fractionalKnapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);

    printf("Enter item details (Weight, Value):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    double maxValue = fractionalKnapsack(W, items, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Maximum value in knapsack = %.2f\n", maxValue);
    printf("\nTime executed: %f seconds\n", cpu_time_used);

    return 0;
}
