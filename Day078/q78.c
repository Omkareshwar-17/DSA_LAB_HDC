#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex, weight;
    struct Node* next;
};

void addEdge(struct Node** adj, int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    int* key = (int*)malloc((n + 1) * sizeof(int));
    int* inMST = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) key[i] = INT_MAX;

    // Start from the first vertex
    key[1] = 0;
    long long totalWeight = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum key vertex not yet in MST
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) break; // Graph is disconnected

        inMST[u] = 1;
        totalWeight += key[u];

        // Update keys of adjacent vertices
        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    printf("%lld\n", totalWeight);

    return 0;
}