#include <stdio.h>
#include <limits.h>

#define MAX 100

void findMin(int cost[MAX][MAX], int n) {
    int minCost = 0;

    for (int i = 0; i < n; i++) {
        int rowMin = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (cost[i][j] < rowMin) {
                rowMin = cost[i][j];
            }
        }
        minCost += rowMin;
    }

    printf("Estimated Minimum Cost for Assignment = %d\n", minCost);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter the number of tasks (NxN matrix): ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    findMin(cost, n);
    return 0;
}
