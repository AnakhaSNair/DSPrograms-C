#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;

    if (head == NULL) { head = n; return; }

    struct node *t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

// Delete first match
void delete(int x) {
    struct node *t = head, *p = NULL;

    if (t != NULL && t->data == x) {
        head = t->next; free(t); return;
    }

    while (t != NULL && t->data != x) {
        p = t; t = t->next;
    }
    if (t == NULL) return;

    p->next = t->next;
    free(t);
}

// Display forward
void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// Display reverse (recursion)
void displayRev(struct node *t) {
    if (t == NULL) return;
    displayRev(t->next);
    printf("%d ", t->data);
}

// Search
void search(int x) {
    struct node *t = head;
    int pos = 1;
    while (t != NULL) {
        if (t->data == x) {
            printf("Found at %d\n", pos);
            return;
        }
        pos++;
        t = t->next;
    }
    printf("Not found\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Reverse  5.Search  6.Exit\n");
        scanf("%d", &ch);

        if (ch == 6) break;

        if (ch == 1) { scanf("%d", &x); insert(x); }
        else if (ch == 2) { scanf("%d", &x); delete(x); }
        else if (ch == 3) display();
        else if (ch == 4) { displayRev(head); printf("\n"); }
        else if (ch == 5) { scanf("%d", &x); search(x); }
    }
}
