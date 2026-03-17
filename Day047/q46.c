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

int getHeight(struct Node* node) {
    if (!node) return 0;
    int l = getHeight(node->left);
    int r = getHeight(node->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        if (n == 0) printf("0\n");
        return 0;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    if (!root) {
        printf("0\n");
        free(arr);
        return 0;
    }

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    printf("%d\n", getHeight(root));

    free(arr);
    free(queue);
    return 0;
}