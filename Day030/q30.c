#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *last = NULL;

    // Create the linked list representing the polynomial
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    struct Node* temp = head;
    while (temp != NULL) {
        // Handle Coefficient and Variable
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Handle the " + " separator
        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");

    return 0;
}