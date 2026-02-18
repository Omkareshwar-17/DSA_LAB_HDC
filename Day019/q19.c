#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int res1 = arr[0], res2 = arr[1];
    int min_sum = abs(arr[0] + arr[1]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int current_sum = arr[i] + arr[j];
            if (abs(current_sum) < min_sum) {
                min_sum = abs(current_sum);
                res1 = arr[i];
                res2 = arr[j];
            }
        }
    }

    printf("%d %d\n", res1, res2);

    return 0;
}