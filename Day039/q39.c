#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    int current = size;
    size++;
    while (current != 0 && heap[(current - 1) / 2] > heap[current]) {
        swap(&heap[(current - 1) / 2], &heap[current]);
        current = (current - 1) / 2;
    }
}

void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void extractMin() {
    if (size <= 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    if (size == 1) {
        size--;
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
}

void peek() {
    if (size <= 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n, val;
    char op[20];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}