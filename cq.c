#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q)
{
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(CircularQueue* q)
{
    return (q->front == -1);
}

void enqueue(CircularQueue* q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

void display(CircularQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;

    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

void search(CircularQueue* q, int value)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    int pos = 0;

    while (1)
    {
        if (q->arr[i] == value)
        {
            printf("Value %d found at position %d (0-based index in queue)\n", value, pos);
            return;
        }

        if (i == q->rear)
            break;

        i = (i + 1) % MAX;
        pos++;
    }

    printf("Value %d not found in the queue.\n", value);
}

int main()
{
    CircularQueue q;
    initialize(&q);

    int choice, value;

    do
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(&q, value);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
