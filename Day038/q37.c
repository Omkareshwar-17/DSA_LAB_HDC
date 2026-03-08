#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Deque {
    struct Node *head, *tail;
    int count;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->head = dq->tail = NULL;
    dq->count = 0;
    return dq;
}

void push_front(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->head;
    if (dq->head == NULL) dq->tail = newNode;
    else dq->head->prev = newNode;
    dq->head = newNode;
    dq->count++;
}

void push_back(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->tail;
    if (dq->tail == NULL) dq->head = newNode;
    else dq->tail->next = newNode;
    dq->tail = newNode;
    dq->count++;
}

void pop_front(struct Deque* dq) {
    if (dq->head == NULL) return;
    struct Node* temp = dq->head;
    dq->head = dq->head->next;
    if (dq->head == NULL) dq->tail = NULL;
    else dq->head->prev = NULL;
    free(temp);
    dq->count--;
}

void pop_back(struct Deque* dq) {
    if (dq->tail == NULL) return;
    struct Node* temp = dq->tail;
    dq->tail = dq->tail->prev;
    if (dq->tail == NULL) dq->head = NULL;
    else dq->tail->next = NULL;
    free(temp);
    dq->count--;
}

void display(struct Deque* dq) {
    struct Node* temp = dq->head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL ? "" : " "));
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    char op[20];
    struct Deque* dq = createDeque();

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &val);
            push_front(dq, val);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &val);
            push_back(dq, val);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front(dq);
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back(dq);
        } else if (strcmp(op, "front") == 0) {
            if (dq->head) printf("%d\n", dq->head->data);
        } else if (strcmp(op, "back") == 0) {
            if (dq->tail) printf("%d\n", dq->tail->data);
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", dq->count);
        }
    }
    display(dq);
    return 0;
}