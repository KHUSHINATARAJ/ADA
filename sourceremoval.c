#include <stdio.h>

#define MAX 100

void topologicalSort(int graph[MAX][MAX], int n) {
    int in_degree[MAX] = {0}, visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                in_degree[j]++;
            }
        }
    }

    printf("Topological Order: ");
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && in_degree[i] == 0) {
                u = i;
                break;
            }
        }

        if (u == -1) {
            printf("\nCycle detected. Topological sorting not possible.\n");
            return;
        }

        visited[u] = 1;
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v]) {
                in_degree[v]--;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}
