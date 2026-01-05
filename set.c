#include <stdio.h>

void Union(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe Union of Set A and B is: ");
    for (i = 0; i < n; i++)
        z[i] = (x[i] == 1 || y[i] == 1);

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

void Intersection(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe Intersection of Set A and B is: ");
    for (i = 0; i < n; i++)
        z[i] = (x[i] == 1 && y[i] == 1);

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

void Difference(int x[], int y[], int n)
{
    int z[50], i;
    printf("\nThe Difference (A - B) is: ");
    for (i = 0; i < n; i++)
        z[i] = (x[i] == 1 && y[i] == 0);

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

int main()
{
    int n, m, o, i, j;
    int u[20], a[20], b[20];
    int bitA[50], bitB[50];
    int ch;

    printf("Enter the size of Universal set: ");
    scanf("%d", &n);

    printf("Enter the elements of Universal set: ");
    for (i = 0; i < n; i++)
        scanf("%d", &u[i]);

    printf("Universal set: ");
    for (i = 0; i < n; i++)
        printf("%d ", u[i]);

    printf("\nEnter size of Set A: ");
    scanf("%d", &m);
    while (m > n)
    {
        printf("Invalid size! Enter again: ");
        scanf("%d", &m);
    }

    printf("Enter elements of Set A: ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Set A: ");
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);

    printf("\nEnter size of Set B: ");
    scanf("%d", &o);
    while (o > n)
    {
        printf("Invalid size! Enter again: ");
        scanf("%d", &o);
    }

    printf("Enter elements of Set B: ");
    for (i = 0; i < o; i++)
        scanf("%d", &b[i]);

    printf("Set B: ");
    for (i = 0; i < o; i++)
        printf("%d ", b[i]);

    // Creating Bit String for Set A
    for (i = 0; i < n; i++)
    {
        bitA[i] = 0;
        for (j = 0; j < m; j++)
        {
            if (u[i] == a[j])
            {
                bitA[i] = 1;
                break;
            }
        }
    }

    // Creating Bit String for Set B
    for (i = 0; i < n; i++)
    {
        bitB[i] = 0;
        for (j = 0; j < o; j++)
        {
            if (u[i] == b[j])
            {
                bitB[i] = 1;
                break;
            }
        }
    }

    printf("\nBit String A: ");
    for (i = 0; i < n; i++)
        printf("%d ", bitA[i]);

    printf("\nBit String B: ");
    for (i = 0; i < n; i++)
        printf("%d ", bitB[i]);

    do
    {
        printf("\n\nChoose operation:");
        printf("\n1. Union");
        printf("\n2. Intersection");
        printf("\n3. Difference (A - B)");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Union(bitA, bitB, n);
            break;
        case 2:
            Intersection(bitA, bitB, n);
            break;
        case 3:
            Difference(bitA, bitB, n);
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!");
        }
    } while (ch != 4);

    return 0;
}
