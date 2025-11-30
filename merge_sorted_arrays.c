#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge until one array is exhausted
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Append remaining elements of arr1, if any
    while (i < n1)
        merged[k++] = arr1[i++];

    // Append remaining elements of arr2, if any
    while (j < n2)
        merged[k++] = arr2[j++];
}

int main() {
    int arr1[100], arr2[100], merged[200];
    int n1, n2, i;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements for first array:\n", n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements for second array:\n", n2);
    for(i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    mergeArrays(arr1, n1, arr2, n2, merged);

    printf("Merged sorted array:\n");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);
    printf("\n");

    return 0;
}