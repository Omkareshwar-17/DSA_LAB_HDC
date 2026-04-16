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

    // Handling the case with 0 or 1 vertex
    if (n <= 1) {
        printf("CONNECTED\n");
        return 0;
    }

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    // Start DFS from the first vertex
    DFS(1, adj, visited);

    // Check if all vertices were visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");

    return 0;
}