#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];       // Adjacency matrix for the graph
int transposed[MAX][MAX];  // Transposed graph
int stack[MAX];            // Stack to store vertices in finish time order
int top = -1;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// DFS to visit nodes
void dfs(int v, int vertices, bool visited[], int matrix[MAX][MAX]) {
    visited[v] = true;

    for (int i = 0; i < vertices; i++) {
        if (matrix[v][i] && !visited[i]) {
            dfs(i, vertices, visited, matrix);
        }
    }

    // Push to stack after finishing the vertex
    push(v);
}

// Print a component
void printComponent(int v, int vertices, bool visited[], int matrix[MAX][MAX]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < vertices; i++) {
        if (matrix[v][i] && !visited[i]) {
            printComponent(i, vertices, visited, matrix);
        }
    }
}

// Transpose the graph
void transposeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            transposed[j][i] = graph[i][j];
        }
    }
}

// Find SCCs using Kosaraju's Algorithm
void findSCCs(int vertices) {
    bool visited[MAX] = {false};

    // Step 1: Perform DFS and push vertices to stack based on finish time
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, vertices, visited, graph);
        }
    }

    // Step 2: Transpose the graph
    transposeGraph(vertices);

    // Step 3: Process all vertices in the order of the stack on the transposed graph
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;  // Reset visited array
    }

    printf("Strongly Connected Components:\n");
    while (top != -1) {
        int v = pop();
        if (!visited[v]) {
            printComponent(v, vertices, visited, transposed);
            printf("\n");
        }
    }
}

// Main function
int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    findSCCs(vertices);

    return 0;
}
