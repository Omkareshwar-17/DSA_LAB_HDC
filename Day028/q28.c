#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself initially
            last = head;
        } else {
            last->next = newNode;
            newNode->next = head; // Maintain the circular link
            last = newNode;
        }
    }

    // Traversal logic
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
            
        } while (temp != head);
    }

    return 0;
}