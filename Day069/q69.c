#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Edge {
    int v, dist;
};

void addEdge(struct Node** adj, int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void swap(struct Edge* a, struct Edge* b) {
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Edge heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && heap[l].dist < heap[smallest].dist) smallest = l;
    if (r < n && heap[r].dist < heap[smallest].dist) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void dijkstra(int n, struct Node** adj, int s) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[s] = 0;

    struct Edge* heap = (struct Edge*)malloc(n * n * sizeof(struct Edge));
    int heapSize = 0;

    heap[heapSize++] = (struct Edge){s, 0};

    while (heapSize > 0) {
        struct Edge root = heap[0];
        heap[0] = heap[--heapSize];
        minHeapify(heap, heapSize, 0);

        int u = root.v;
        if (root.dist > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                heap[heapSize++] = (struct Edge){v, dist[v]};
                int curr = heapSize - 1;
                while (curr > 0 && heap[(curr - 1) / 2].dist > heap[curr].dist) {
                    swap(&heap[curr], &heap[(curr - 1) / 2]);
                    curr = (curr - 1) / 2;
                }
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, s;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Node** adj = (struct Node**)calloc(n, sizeof(struct Node*));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }
    scanf("%d", &s);
    dijkstra(n, adj, s);
    return 0;
}