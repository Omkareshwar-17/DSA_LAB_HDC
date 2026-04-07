#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void addEdge(struct Node** adj, int u, int v, int* inDegree) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    inDegree[v]++;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n, sizeof(struct Node*));
    int* inDegree = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, inDegree);
    }

    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    int count = 0;
    int* result = (int*)malloc(n * sizeof(int));

    while (head < tail) {
        int u = queue[head++];
        result[count++] = u;

        struct Node* temp = adj[u];
        while (temp) {
            inDegree[temp->vertex]--;
            if (inDegree[temp->vertex] == 0) {
                queue[tail++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("Cycle detected\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}