#include <stdio.h>
#include <stdlib.h>

// Finds the index of the first element >= x
int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            high = mid; // Potential answer, look left
        } else {
            low = mid + 1; // Too small, look right
        }
    }
    return low;
}

// Finds the index of the first element > x
int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            high = mid; // Potential answer, look left
        } else {
            low = mid + 1; // Too small or equal, look right
        }
    }
    return low;
}

int main() {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    int lb = findLowerBound(arr, n, x);
    int ub = findUpperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    free(arr);
    return 0;
}