#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int parent[MAX];


int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}


int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int vertex_count;
    int cost_matrix[MAX][MAX];
    int row, column;

    int edge_count, count = 1;
    int min_cost, sum_cost = 0;
    int row_no, column_no, edge1, edge2;

    printf("Implementation of Kruskal's Algorithm\n\n");
    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    printf("\nEnter cost matrix (0 if no edge):\n");
    for (row = 1; row <= vertex_count; row++) {
        for (column = 1; column <= vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
            if (cost_matrix[row][column] == 0)
                cost_matrix[row][column] = INF;
        }
    }

    edge_count = vertex_count - 1;

    while (count <= edge_count) {
        min_cost = INF;

        for (row = 1; row <= vertex_count; row++) {
            for (column = 1; column <= vertex_count; column++) {
                if (cost_matrix[row][column] < min_cost) {
                    min_cost = cost_matrix[row][column];
                    edge1 = row_no = row;
                    edge2 = column_no = column;
                }
            }
        }

        row_no = find(row_no);
        column_no = find(column_no);

        if (uni(row_no, column_no)) {
            printf("\nEdge %d: (%d -> %d)  Cost = %d",
                   count++, edge1, edge2, min_cost);
            sum_cost += min_cost;
        }

        cost_matrix[edge1][edge2] = cost_matrix[edge2][edge1] = INF;
    }

    printf("\n\nMinimum cost of Spanning Tree = %d\n", sum_cost);
    return 0;
}
