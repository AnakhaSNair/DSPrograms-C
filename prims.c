#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int vertex_array[MAX], vertex_count;
    int cost_matrix[MAX][MAX];
    int visited[MAX] = {0};

    int row, column, counter;
    int edge_count, count = 1;
    int min_cost, sum_cost = 0;
    int row_no = 0, column_no = 0;
    int vertex1, vertex2;

    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    printf("\n-- Enter vertices --\n");
    for (counter = 1; counter <= vertex_count; counter++) {
        printf("Vertex[%d]: ", counter);
        scanf("%d", &vertex_array[counter]);
    }

    printf("\n--- Enter Cost Matrix (%d x %d) ---\n", vertex_count, vertex_count);
    printf("(Enter 0 if no edge exists)\n\n");

    for (row = 1; row <= vertex_count; row++) {
        for (column = 1; column <= vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
            if (cost_matrix[row][column] == 0)
                cost_matrix[row][column] = INF;
        }
    }

    visited[1] = 1;                 
    edge_count = vertex_count - 1;

    while (count <= edge_count) {
        min_cost = INF;

        for (row = 1; row <= vertex_count; row++) {
            if (visited[row]) {
                for (column = 1; column <= vertex_count; column++) {
                    if (!visited[column] && cost_matrix[row][column] < min_cost) {
                        min_cost = cost_matrix[row][column];
                        row_no = row;
                        column_no = column;
                    }
                }
            }
        }

        vertex1 = row_no;
        vertex2 = column_no;

        printf("\nEdge %d: (%d -> %d)  Cost = %d",
               count++, vertex_array[vertex1], vertex_array[vertex2], min_cost);

        sum_cost += min_cost;
        visited[vertex2] = 1;

        cost_matrix[vertex1][vertex2] = cost_matrix[vertex2][vertex1] = INF;
    }

    printf("\n\nMinimum cost of Spanning Tree = %d\n", sum_cost);

    return 0;
}
