#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, n - 1, capacity);
    } else {
        return max(
            values[n - 1] + knapsack(weights, values, n - 1, capacity - weights[n - 1]),
            knapsack(weights, values, n - 1, capacity));
    }
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];

    printf("Enter weights and values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum value in knapsack = %d\n", knapsack(weights, values, n, capacity));
    return 0;
}
