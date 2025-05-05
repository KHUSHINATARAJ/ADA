#include <stdio.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int visited[], int v, int n, int* stack, int* top) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, i, n, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void topologicalSortDFS(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0}, stack[MAX], top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, n, stack, &top);
        }
    }

    printf("Topological Order: ");
    while (top > 0) {
        printf("%d ", stack[--top]);
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

    topologicalSortDFS(graph, n);

    return 0;
}
