#include <stdio.h>

int main() {
    int a[10], b[10], c[20];
    int n, m, i = 0, j = 0, k = 0;
    printf("Enter size of first array: ");
    scanf("%d", &n);
    printf("Enter elements (sorted): ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &m);
    printf("Enter elements (sorted): ");
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    while(i < n && j < m) {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i < n)
        c[k++] = a[i++];
    while(j < m)
        c[k++] = b[j++];
    printf("Merged array: ");
    for(i = 0; i < k; i++)
        printf("%d ", c[i]);
    return 0;
}
