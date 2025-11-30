#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function for in-order traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate BST operations
int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for an element
    int searchValue = 40;
    if (search(root, searchValue) != NULL) {
        printf("%d found in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }

    searchValue = 90;
    if (search(root, searchValue) != NULL) {
        printf("%d found in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }

    // Note: Deletion is a more complex operation and is omitted for simplicity in this basic example.
    // In a real application, you would also need a function to free the allocated memory.

    return 0;
}