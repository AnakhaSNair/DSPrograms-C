#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/* Push operation */
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}

/* Pop operation */
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;
    free(temp);
}

/* Linear Search operation */
void linearSearch(int key) {
    struct Node *temp = top;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d from top\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("%d not found in stack\n", key);
}

/* Display stack elements */
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack using Singly Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Linear Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            linearSearch(value);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
