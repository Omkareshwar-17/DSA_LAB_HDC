#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for the linked list based stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

int main() {
    char exp[100];
    // Use %[^\n] to read the entire line including spaces
    if (scanf("%[^\n]", exp) != 1) return 0;

    struct Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        // If token is a digit (or a negative number)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            // Token is an operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (token[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", pop(&stack));

    return 0;
}