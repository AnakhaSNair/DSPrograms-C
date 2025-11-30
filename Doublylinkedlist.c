#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Insert at front
void insertFront(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->prev = NULL;
    n->next = head;
    if (head != NULL) head->prev = n;
    head = n;
}

// Insert at end
void insertEnd(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    struct node *t = head;
    while (t->next != NULL) t = t->next;

    t->next = n;
    n->prev = t;
}

// Insert at position
void insertPos(int x, int pos) {
    if (pos == 1) { insertFront(x); return; }

    struct node *t = head;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) return;

    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = t->next;
    n->prev = t;

    if (t->next != NULL)
        t->next->prev = n;

    t->next = n;
}

// Delete front
void deleteFront() {
    if (head == NULL) return;

    struct node *t = head;
    head = head->next;

    if (head != NULL) head->prev = NULL;

    free(t);
}

// Delete end
void deleteEnd() {
    if (head == NULL) return;

    struct node *t = head;
    if (t->next == NULL) { head = NULL; free(t); return; }

    while (t->next != NULL) t = t->next;

    t->prev->next = NULL;
    free(t);
}

// Delete position
void deletePos(int pos) {
    if (pos == 1) { deleteFront(); return; }

    struct node *t = head;
    for (int i = 1; i < pos && t != NULL; i++)
        t = t->next;

    if (t == NULL) return;

    if (t->next != NULL)
        t->next->prev = t->prev;

    if (t->prev != NULL)
        t->prev->next = t->next;

    free(t);
}

// Display forward
void displayForward() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// Display backward
void displayBackward() {
    struct node *t = head;
    if (t == NULL) return;

    while (t->next != NULL) t = t->next;

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

int main() {
    int ch, x, pos;

    while (1) {
        printf("\n1.IF  2.IE  3.IP  4.DF  5.DE  6.DP  7.FW  8.BW  9.Exit\n");
        scanf("%d", &ch);

        if (ch == 9) break;

        if (ch == 1) { scanf("%d", &x); insertFront(x); }
        else if (ch == 2) { scanf("%d", &x); insertEnd(x); }
        else if (ch == 3) { scanf("%d %d", &x, &pos); insertPos(x, pos); }
        else if (ch == 4) deleteFront();
        else if (ch == 5) deleteEnd();
        else if (ch == 6) { scanf("%d", &pos); deletePos(pos); }
        else if (ch == 7) displayForward();
        else if (ch == 8) displayBackward();
    }
}
