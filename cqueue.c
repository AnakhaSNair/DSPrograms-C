#include <stdio.h>
#define MAX_SIZE 5  // Maximum size of the circular queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to add an element to the queue (Enqueue)
void add(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot add element.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
    printf("Added %d to the queue.\n", value);
}

// Function to delete an element from the queue (Dequeue)
void delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }
    int deletedValue = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Deleted %d from the queue.\n", deletedValue);
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
