#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n, m, val;
    int stack[MAX];
    int top = -1;

    // Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Push n elements onto the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (top < MAX - 1) {
            stack[++top] = val;
        }
    }

    // Read number of pop operations
    if (scanf("%d", &m) != 1) return 0;

    // Perform m pops
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    // Display remaining stack elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    return 0;
}