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

// Recursive function to check if two subtrees are mirrors
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    
    return (t1->data == t2->data) && 
           isMirror(t1->left, t2->right) && 
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        if (n == 0) printf("YES\n");
        return 0;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree using Level Order Traversal
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    
    if (root) queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        
        // Assign left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        
        // Assign right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    free(queue);
    return 0;
}