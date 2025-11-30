#include <stdio.h>
#define MAX 100

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (isStackFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Queue implementation
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int val) {
    if (isQueueFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->data[(q->front)++];
}

int main() {
    Stack s;
    Queue q;
    int choice, val;

    initStack(&s);
    initQueue(&q);

    while (1) {
        printf("\n-- Menu --\n");
        printf("1. Stack Push\n");
        printf("2. Stack Pop\n");
        printf("3. Queue Enqueue\n");
        printf("4. Queue Dequeue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push onto stack: ");
                scanf("%d", &val);
                push(&s, val);
                break;
            case 2:
                val = pop(&s);
                if (val != -1)
                    printf("Popped from stack: %d\n", val);
                break;
            case 3:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 4:
                val = dequeue(&q);
                if (val != -1)
                    printf("Dequeued from queue: %d\n", val);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}