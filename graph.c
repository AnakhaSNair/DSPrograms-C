#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    int num_vertices;
    struct Node *adj_list[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int start_time[MAX_VERTICES];
    int end_time[MAX_VERTICES];
    int time;

    /* For Topological Sort */
    int stack[MAX_VERTICES];
    int top;
};

void initializeGraph(struct Graph *G, int num_vertices) {
    G->num_vertices = num_vertices;
    G->time = 0;
    G->top = -1;

    for (int i = 0; i < num_vertices; i++) {
        G->adj_list[i] = NULL;
        G->visited[i] = 0;
        G->start_time[i] = 0;
        G->end_time[i] = 0;
    }
}


void addEdge(struct Graph *G, int src, int dest) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = G->adj_list[src];
    G->adj_list[src] = newNode;
}


void DFS_VISIT(struct Graph *G, int u) {
    G->visited[u] = 1;
    G->start_time[u] = ++(G->time);
    printf("%d ", u);

    struct Node *temp = G->adj_list[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!G->visited[v]) {
            DFS_VISIT(G, v);
        }
        temp = temp->next;
    }

    G->end_time[u] = ++(G->time);

    /* Push to stack for Topological Sort */
    G->stack[++G->top] = u;
}


void DFS(struct Graph *G) {
    printf("DFS Traversal: ");
    for (int i = 0; i < G->num_vertices; i++) {
        if (!G->visited[i]) {
            DFS_VISIT(G, i);
        }
    }

    printf("\n\nNode\tStart Time\tEnd Time\n");
    for (int i = 0; i < G->num_vertices; i++) {
        printf("%d\t%d\t\t%d\n",
               i, G->start_time[i], G->end_time[i]);
    }
}


void BFS(struct Graph *G, int start_vertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    printf("\nBFS Traversal: ");
    G->visited[start_vertex] = 1;
    printf("%d ", start_vertex);
    queue[++rear] = start_vertex;

    while (front <= rear) {
        int u = queue[front++];
        struct Node *temp = G->adj_list[u];

        while (temp != NULL) {
            int v = temp->vertex;
            if (!G->visited[v]) {
                G->visited[v] = 1;
                printf("%d ", v);
                queue[++rear] = v;
            }
            temp = temp->next;
        }
    }
}


void topologicalSort(struct Graph *G) {
    printf("\n\nTopological Sorting Order: ");
    while (G->top != -1) {
        printf("%d ", G->stack[G->top--]);
    }
}


int main() {
    struct Graph G;
    int num_vertices, num_edges;

    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    initializeGraph(&G, num_vertices);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&G, u, v);
    }

    DFS(&G);

        topologicalSort(&G);

        for (int i = 0; i < G.num_vertices; i++)
        G.visited[i] = 0;

    int start_vertex;
    printf("\n\nEnter starting vertex for BFS: ");
    scanf("%d", &start_vertex);

    BFS(&G, start_vertex);

    return 0;
}
