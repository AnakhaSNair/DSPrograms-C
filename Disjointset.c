#include <stdio.h>

#define MAX 20
int parent[MAX], rank[MAX];

// Create Set: each node is its own parent, rank = 0
void createSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with Path Compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // compress path
    return parent[x];
}

// Union by Rank
void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py)
        return;  // already in same set

    if (rank[px] > rank[py])
        parent[py] = px;
    else if (rank[px] < rank[py])
        parent[px] = py;
    else {
        parent[py] = px;
        rank[px]++;  // increase rank
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    createSet(n);

    while (1) {
        printf("\n--- DISJOINT SET MENU ---\n");
        printf("1. Find Representative\n");
        printf("2. Union Two Sets\n");
        printf("3. Display Parent Array\n");
        printf("4. Display Rank Array\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                printf("Representative: %d\n", find(x));
                break;

            case 2:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);
                unionSet(x, y);
                printf("Union complete.\n");
                break;

            case 3:
                printf("Parent array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", parent[i]);
                printf("\n");
                break;

            case 4:
                printf("Rank array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", rank[i]);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
