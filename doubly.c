#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* pre;
} node;

node* head = NULL;
int count = 0;
void display() 
{
    node* temp = head;
    if (temp == NULL) {
        printf("Empty Linked List\n");
    } else {
        while (temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void in_beg() 
{
    node* newnode = (node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    newnode->pre = NULL;

    if (head != NULL)
        head->pre = newnode;

    head = newnode;
    count++;

    printf("Node inserted at the beginning\n");
}
void in_end() 
{
    node* newnode = (node*)malloc(sizeof(node));
    node* temp = head;

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->pre = NULL;
        head = newnode;
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->pre = temp;
    }
    count++;
    printf("Node inserted at the end\n");
}
void in_pos() 
{
    int pos;
    node* newnode = (node*)malloc(sizeof(node));
    node* temp = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (pos == 1) {
        newnode->next = head;
        newnode->pre = NULL;
        if (head != NULL)
            head->pre = newnode;
        head = newnode;
    } else {
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        newnode->pre = temp;
        if (temp->next != NULL)
            temp->next->pre = newnode;
        temp->next = newnode;
    }
    count++;
    printf("Node inserted at position %d\n", pos);
}
void del_in() 
{
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }
    node* temp = head;
    head = head->next;
    if (head != NULL)
        head->pre = NULL;
    free(temp);
    count--;
    printf("Node deleted from beginning\n");
}
void del_end() 
{
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->pre != NULL)
        temp->pre->next = NULL;
    else
        head = NULL;
    free(temp);
    count--;
    printf("Node deleted from end\n");
}
void del_pos() {
    int pos;
    node* temp = head;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        del_in();
        return;
    }
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    if (temp->pre != NULL)
        temp->pre->next = temp->next;
    if (temp->next != NULL)
        temp->next->pre = temp->pre;
    free(temp);
    count--;
    printf("Node deleted from position %d\n", pos);
}
void search() {
    int key, pos = 1;
    node* temp = head;
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}
int main() 
{
    int ch;
    do {
        printf("\n***** DOUBLY LINKED LIST *****");
        printf("\n1.Display");
        printf("\n2.Insert at beginning");
        printf("\n3.Insert at end");
        printf("\n4.Insert at a position");
        printf("\n5.Delete at beginning");
        printf("\n6.Delete at end");
        printf("\n7.Delete at a position");
        printf("\n8.Search");
        printf("\n9.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1: display(); break;
            case 2: in_beg(); break;
            case 3: in_end(); break;
            case 4: in_pos(); break;
            case 5: del_in(); break;
            case 6: del_end(); break;
            case 7: del_pos(); break;
            case 8: search(); break;
            case 9: printf("Exiting program...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 9);
    return 0;
}
