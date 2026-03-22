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

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

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

    struct Node* lca = findLCA(root, n1, n2);
    if (lca) printf("%d\n", lca->data);

    free(arr);
    free(queue);
    return 0;
}