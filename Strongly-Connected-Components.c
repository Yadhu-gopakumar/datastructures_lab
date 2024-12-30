#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Stack structure
struct Stack {
    int data[MAX];
    int top;
};

// Graph structure
int adj[MAX][MAX];         // Adjacency matrix for original graph
int transpose[MAX][MAX];   // Adjacency matrix for transposed graph
int n;                     // Number of vertices
int visited[MAX];          // Visited array (1 for visited, 0 for not visited)

// Stack operations
void push(struct Stack *stack, int val) {
    stack->data[++stack->top] = val;
}

int pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Depth First Search (DFS) on original graph
void dfsOriginal(int vertex, struct Stack *stack) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] && !visited[i]) {
            dfsOriginal(i, stack);
        }
    }

    // Push the vertex onto the stack after finishing all its neighbors
    push(stack, vertex);
}

// Depth First Search (DFS) on transposed graph
void dfsTranspose(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (transpose[vertex][i] && !visited[i]) {
            dfsTranspose(i);
        }
    }
}

// Transpose the graph
void transposeGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = adj[j][i];
        }
    }
}

// Kosaraju's Algorithm
void findSCCs() {
    struct Stack stack;
    stack.top = -1;

    // Step 1: Perform DFS on the original graph and store vertices in stack
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Reset visited array
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsOriginal(i, &stack);
        }
    }

    // Step 2: Transpose the graph
    transposeGraph();

    // Step 3: Perform DFS on the transposed graph in the order of the stack
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Reset visited array
    }

    printf("\nStrongly Connected Components:\n");
    while (!isEmpty(&stack)) {
        int vertex = pop(&stack);
        if (!visited[vertex]) {
            dfsTranspose(vertex);
            printf("\n");
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
            transpose[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed edge
    }

    findSCCs();

    return 0;
}
