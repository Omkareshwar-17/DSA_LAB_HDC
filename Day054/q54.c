#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printZigZag(struct Node* root, int n) {
    if (!root) return;

    // Use two stacks for alternating levels
    struct Node** currentStack = (struct Node**)malloc(n * sizeof(struct Node*));
    struct Node** nextStack = (struct Node**)malloc(n * sizeof(struct Node*));
    int topCurrent = -1;
    int topNext = -1;

    int leftToRight = 1;
    currentStack[++topCurrent] = root;

    while (topCurrent >= 0) {
        struct Node* curr = currentStack[topCurrent--];
        printf("%d ", curr->data);

        if (leftToRight) {
            // Level is L->R: Push children L then R so next level is R->L
            if (curr->left) nextStack[++topNext] = curr->left;
            if (curr->right) nextStack[++topNext] = curr->right;
        } else {
            // Level is R->L: Push children R then L so next level is L->R
            if (curr->right) nextStack[++topNext] = curr->right;
            if (curr->left) nextStack[++topNext] = curr->left;
        }

        if (topCurrent == -1) {
            leftToRight = !leftToRight;
            // Swap stacks
            struct Node** temp = currentStack;
            currentStack = nextStack;
            nextStack = temp;
            topCurrent = topNext;
            topNext = -1;
        }
    }
    free(currentStack);
    free(nextStack);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) queue[tail++] = curr->right;
            }
        }
    }

    printZigZag(root, n);

    free(arr);
    free(queue);
    return 0;
}