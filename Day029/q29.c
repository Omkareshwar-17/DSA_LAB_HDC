#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val, k;
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    struct Node *head = NULL, *last = NULL;

    // Create the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n;

    // If k is 0, no rotation is needed
    if (k == 0) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Step 1: Connect last node to head to make it circular
    last->next = head;

    // Step 2: Traverse to the (n-k)th node
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    // Step 3: Set the (n-k+1)th node as the new head and break the circle
    head = newTail->next;
    newTail->next = NULL;

    // Output the rotated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}