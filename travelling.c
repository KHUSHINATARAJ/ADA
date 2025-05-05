#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int tsp(int graph[MAX][MAX], int visited[], int pos, int n, int count, int cost, int* minCost) {
    if (count == n && graph[pos][0]) {
        *minCost = cost + graph[pos][0];
        return *minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], minCost);
            visited[i] = 0;
        }
    }
    return *minCost;
}

int main() {
    int n, graph[MAX][MAX], visited[MAX] = {0}, minCost = INF;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    visited[0] = 1;
    printf("Minimum cost of TSP: %d\n", tsp(graph, visited, 0, n, 1, 0, &minCost));
    return 0;
}
