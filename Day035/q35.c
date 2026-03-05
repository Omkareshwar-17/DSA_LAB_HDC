#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Display operation
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL ? "" : " "));
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            enqueue(q, val);
        }
    }

    display(q);

    return 0;
}