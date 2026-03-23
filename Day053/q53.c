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

struct QueueNode {
    struct Node* node;
    int hd;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

void findMinMax(struct Node* root, int hd, int* min, int* max) {
    if (!root) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    q[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = q[head++];
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[tail++] = curr->left;
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) q[tail++] = curr->right;
            }
        }
    }

    int min = 0, max = 0;
    findMinMax(root, 0, &min, &max);

    int range = max - min + 1;
    struct ListNode** map = (struct ListNode**)calloc(range, sizeof(struct ListNode*));
    struct ListNode** last = (struct ListNode**)calloc(range, sizeof(struct ListNode*));

    struct QueueNode* vq = (struct QueueNode*)malloc(n * sizeof(struct QueueNode));
    int vhead = 0, vtail = 0;
    vq[vtail++] = (struct QueueNode){root, 0};

    while (vhead < vtail) {
        struct QueueNode curr = vq[vhead++];
        int idx = curr.hd - min;

        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->data = curr.node->data;
        temp->next = NULL;

        if (map[idx] == NULL) {
            map[idx] = temp;
        } else {
            last[idx]->next = temp;
        }
        last[idx] = temp;

        if (curr.node->left) vq[vtail++] = (struct QueueNode){curr.node->left, curr.hd - 1};
        if (curr.node->right) vq[vtail++] = (struct QueueNode){curr.node->right, curr.hd + 1};
    }

    for (int j = 0; j < range; j++) {
        struct ListNode* curr = map[j];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }

    return 0;
}