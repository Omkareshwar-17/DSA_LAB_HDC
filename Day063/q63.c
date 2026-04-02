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
    printf("%d ", u);

    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n, sizeof(struct Node*));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    scanf("%d", &s);
    DFS(s, adj, visited);

    return 0;
}