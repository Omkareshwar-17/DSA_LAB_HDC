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
    struct Node* l1 = createList(n);
    
    scanf("%d", &m);
    struct Node* l2 = createList(m);

    struct Node dummy;
    struct Node* last = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            last->next = l1;
            l1 = l1->next;
        } else {
            last->next = l2;
            l2 = l2->next;
        }
        last = last->next;
    }

    if (l1 != NULL) last->next = l1;
    else last->next = l2;

    struct Node* temp = dummy.next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}