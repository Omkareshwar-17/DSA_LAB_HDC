#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int k) {
    struct Node *head = NULL, *last = NULL;
    int val;
    for (int i = 0; i < k; i++) {
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
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node *p1 = head1, *p2 = head2;
    int found = 0;

    while (p1 != NULL) {
        p2 = head2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d\n", p1->data);
                found = 1;
                break;
            }
            p2 = p2->next;
        }
        if (found) break;
        p1 = p1->next;
    }

    if (!found) printf("No Intersection\n");

    return 0;
}