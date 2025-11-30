#include <stdio.h>

// Function to search for an element in the array
int search(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i; // Return the index if found
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[100], n, key, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    pos = search(arr, n, key);

    if (pos == -1)
        printf("%d not found in the array.\n", key);
    else
        printf("%d found at position %d (index %d).\n", key, pos + 1, pos);

    return 0;
}