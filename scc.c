#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[MAX];
    int V;
} Graph;

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack* s, int v) {
    s->arr[++s->top] = v;
}

int pop(Stack* s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
        g->head[i] = NULL;
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->head[u];
    g->head[u] = newNode;
}

void DFSUtil(Graph* g, int v, int visited[], Stack* s) {
    visited[v] = 1;
    Node* temp = g->head[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFSUtil(g, temp->vertex, visited, s);
        temp = temp->next;
    }
    push(s, v);
}

Graph* transposeGraph(Graph* g) {
    Graph* gt = createGraph(g->V);
    for (int v = 0; v < g->V; v++) {
        Node* temp = g->head[v];
        while (temp != NULL) {
            addEdge(gt, temp->vertex, v);
            temp = temp->next;
        }
    }
    return gt;
}

void DFSUtilSCC(Graph* g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    Node* temp = g->head[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFSUtilSCC(g, temp->vertex, visited);
        temp = temp->next;
    }
}

void printSCCs(Graph* g) {
    int V = g->V;
    int visited[MAX] = {0};
    Stack s; s.top = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(g, i, visited, &s);

    Graph* gt = transposeGraph(g);

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");
    while (s.top != -1) {
        int v = pop(&s);
        if (!visited[v]) {
            DFSUtilSCC(gt, v, visited);
            printf("\n");
        }
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Graph* g = createGraph(V);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    printSCCs(g);
    return 0;
}
