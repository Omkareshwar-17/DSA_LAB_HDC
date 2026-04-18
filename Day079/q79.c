#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

void addEdge(Node** adj, int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && heap[l].dist < heap[smallest].dist) smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void push(HeapNode heap[], int* size, int v, int dist) {
    heap[*size] = (HeapNode){v, dist};
    int curr = (*size)++;
    while (curr > 0 && heap[(curr - 1) / 2].dist > heap[curr].dist) {
        swap(&heap[curr], &heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

HeapNode pop(HeapNode heap[], int* size) {
    HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return root;
}

int main() {
    int n, m, src;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // Assuming undirected as per general shortest path problems
    }
    scanf("%d", &src);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    HeapNode* heap = (HeapNode*)malloc(m * 2 * sizeof(HeapNode));
    int heapSize = 0;
    push(heap, &heapSize, src, 0);

    while (heapSize > 0) {
        HeapNode top = pop(heap, &heapSize);
        int u = top.v;

        if (top.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            if (dist[u] + temp->w < dist[temp->v]) {
                dist[temp->v] = dist[u] + temp->w;
                push(heap, &heapSize, temp->v, dist[temp->v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}