#include <stdio.h>
#include <stdlib.h>

#define INF 1e9 // Using a large value for infinity

void floydWarshall(int n, long long** dist) {
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If a shorter path exists from i to j through k, update it
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for the distance matrix
    long long** dist = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        dist[i] = (long long*)malloc(n * sizeof(long long));
    }

    // Read Adjacency Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            scanf("%d", &weight);
            if (weight == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = weight;
            }
        }
    }

    floydWarshall(n, dist);

    // Print the resulting shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF) {
                printf("-1 ");
            } else {
                printf("%lld ", dist[i][j]);
            }
        }
        printf("\n");
    }

    // Cleanup
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);

    return 0;
}