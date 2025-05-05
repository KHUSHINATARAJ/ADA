#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    double ratio;
} Item;

int compareItems(const void* a, const void* b) {
    double r1 = ((Item*)a)->ratio;
    double r2 = ((Item*)b)->ratio;
    return (r2 > r1) - (r1 > r2);
}

void fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compareItems);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);
    return 0;
}
