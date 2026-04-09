#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge* edges, int s) {
    long* dist = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    int hasNegativeCycle = 0;
    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) printf("INF ");
            else printf("%ld ", dist[i]);
        }
        printf("\n");
    }
    free(dist);
}

int main() {
    int n, m, s;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &s);
    bellmanFord(n, m, edges, s);

    free(edges);
    return 0;
}