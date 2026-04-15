#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

// Function to add an edge to an undirected graph
void addEdge(struct Node** adj, int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Standard DFS to mark all nodes in a component
void DFS(int u, struct Node** adj, int* visited) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Use 1-based indexing for vertices as per sample
    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int componentCount = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Every time we find an unvisited node, it's a new component
            componentCount++;
            DFS(i, adj, visited);
        }
    }

    printf("%d\n", componentCount);

    // Cleanup
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
    free(visited);

    return 0;
}