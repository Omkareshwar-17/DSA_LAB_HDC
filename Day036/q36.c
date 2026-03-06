#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node *front, *rear;
};

// Initialize the circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation for Circular Linked List
void enqueue(struct CircularQueue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->rear->next = q->front; // Maintain circularity
}

// Dequeue operation
void dequeue(struct CircularQueue* q) {
    if (q->front == NULL) return;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Update rear to point to new front
        free(temp);
    }
}

// Display operation
void display(struct CircularQueue* q) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    do {
        printf("%d%s", temp->data, (temp->next == q->front ? "" : " "));
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    int n, m, val;
    struct CircularQueue* q = createQueue();

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            enqueue(q, val);
        }
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}