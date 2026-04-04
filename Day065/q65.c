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

int hasCycleDFS(int u, int p, struct Node** adj, int* visited) {
    visited[u] = 1;

    struct Node* temp = adj[u];
    while (temp) {
        int v = temp->vertex;
        if (!visited[v]) {
            if (hasCycleDFS(v, u, adj, visited)) return 1;
        } else if (v != p) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n, sizeof(struct Node*));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int cycleFound = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adj, visited)) {
                cycleFound = 1;
                break;
            }
        }
    }

    if (cycleFound) printf("YES\n");
    else printf("NO\n");

    return 0;
}