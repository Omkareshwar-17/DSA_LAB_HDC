#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted subarray
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) break;
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }

    free(arr);
    return 0;
}