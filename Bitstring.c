#include <stdio.h>

#define MAX 8   // Universal set {0,1,2,3,4,5,6,7}

void printBitString(int S[]) {
    for (int i = 0; i < MAX; i++)
        printf("%d ", S[i]);
    printf("\n");
}

int main() {
    int A[MAX] = {0};
    int B[MAX] = {0};
    int U[MAX] = {0};
    int I[MAX] = {0};
    int D[MAX] = {0};

    int n, x;

    // Input Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        A[x] = 1;
    }

    // Input Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        B[x] = 1;
    }

    // Union
    for (int i = 0; i < MAX; i++)
        U[i] = A[i] | B[i];

    // Intersection
    for (int i = 0; i < MAX; i++)
        I[i] = A[i] & B[i];

    // Difference A - B
    for (int i = 0; i < MAX; i++)
        D[i] = A[i] & (!B[i]);

    // OUTPUT
    printf("\nBitstring of Set A: ");
    printBitString(A);

    printf("Bitstring of Set B: ");
    printBitString(B);

    printf("\nUnion (A U B): ");
    printBitString(U);

    printf("Intersection (A ∩ B): ");
    printBitString(I);

    printf("Difference (A - B): ");
    printBitString(D);

    return 0;
}
