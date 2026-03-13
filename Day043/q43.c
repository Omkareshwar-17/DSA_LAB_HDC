#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) return -1;
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return data;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *front = NULL, *rear = NULL;
    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&front, &rear, val);
    }

    while (front != NULL) {
        stack[++top] = dequeue(&front, &rear);
    }

    while (top >= 0) {
        enqueue(&front, &rear, stack[top--]);
    }

    while (front != NULL) {
        printf("%d ", dequeue(&front, &rear));
    }

    free(stack);
    return 0;
}