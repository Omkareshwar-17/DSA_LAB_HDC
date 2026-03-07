#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    if (size == MAX) return;
    int i = size - 1;
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq[0]);
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int n, val;
    char op[10];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}