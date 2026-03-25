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

void printRightView(struct Node* root, int n) {
    if (!root) return;

    // Queue for Level Order Traversal
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        // Number of nodes at the current level
        int levelCount = tail - head;

        for (int i = 0; i < levelCount; i++) {
            struct Node* curr = queue[head++];

            // If it's the last node of the current level, print it
            if (i == levelCount - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Construct the tree from level order array
    struct Node* root = newNode(arr[0]);
    if (!root) {
        free(arr);
        return 0;
    }

    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int q_head = 0, q_tail = 0;
    q[q_tail++] = root;

    int i = 1;
    while (i < n && q_head < q_tail) {
        struct Node* curr = q[q_head++];
        if (curr) {
            if (i < n) {
                curr->left = newNode(arr[i++]);
                if (curr->left) q[q_tail++] = curr->left;
            }
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) q[q_tail++] = curr->right;
            }
        }
    }

    printRightView(root, n);

    free(arr);
    free(q);
    return 0;
}