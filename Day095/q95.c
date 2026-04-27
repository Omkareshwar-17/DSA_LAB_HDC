#include <stdio.h>
#include <stdlib.h>

// Structure for bucket nodes (linked list)
struct Node {
    double data;
    struct Node* next;
};

// Standard Insertion Sort for linked lists
struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;

    struct Node* sorted = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(double arr[], int n) {
    if (n <= 0) return;

    // 1. Create n buckets
    struct Node** buckets = (struct Node**)calloc(n, sizeof(struct Node*));

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in [0, n-1]
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 3. Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Free memory as we go
        }
    }
    free(buckets);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.4f%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }

    free(arr);
    return 0;
}