#include <stdio.h>
#include <stdlib.h>

/**
 * For an array-based level-order representation:
 * Parent at index i:
 * - Left child: 2*i + 1
 * - Right child: 2*i + 2
 */

int isMinHeap(int arr[], int n) {
    // We only need to check internal nodes
    // Internal nodes exist up to index (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Skip NULL nodes if they were represented as -1
        if (arr[i] == -1) continue;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[left] != -1) {
            if (arr[i] > arr[left]) return 0;
        }

        // Check right child
        if (right < n && arr[right] != -1) {
            if (arr[i] > arr[right]) return 0;
        }
    }
    return 1;
}

/**
 * Completeness Check:
 * Ensures no non-NULL node appears after a NULL node in level order.
 */
int isComplete(int arr[], int n) {
    int seenNull = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            seenNull = 1;
        } else {
            if (seenNull) return 0; // A node appeared after a NULL
        }
    }
    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isComplete(arr, n) && isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}