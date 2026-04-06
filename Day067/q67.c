#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void addEdge(struct Node** adj, int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void topoSort(int u, struct Node** adj, int* visited, int* stack, int* top) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->vertex]) {
            topoSort(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)--] = u;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n, sizeof(struct Node*));
    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = n - 1;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSort(i, adj, visited, stack, &top);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}