#include <stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Represent no edge with a large value
            }
        }
    }

    visited[1] = 1; // Start from the first node
    printf("\n");

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min && visited[i] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as used
    }

    printf("\n\nMinimum cost: %d\n", mincost);
}

// adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

typedef struct Edge {
    int vertex, weight;
    struct Edge* next;
} Edge;

Edge* adjList[MAX]; // Adjacency list
int visited[MAX] = {0}, n;
int mincost = 0;

// Function to add an edge to the adjacency list
void addEdge(int u, int v, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = v;
    newEdge->weight = weight;
    newEdge->next = adjList[u];
    adjList[u] = newEdge;
}

// Function to find the minimum spanning tree using Prim's algorithm
void prim() {
    int ne = 1, u, v, min;
    visited[1] = 1; // Start from the first vertex

    printf("\n");

    while (ne < n) {
        min = INF;
        u = -1;
        v = -1;

        // Find the edge with the minimum weight that connects a visited vertex to an unvisited vertex
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                Edge* temp = adjList[i];
                while (temp) {
                    if (!visited[temp->vertex] && temp->weight < min) {
                        min = temp->weight;
                        u = i;
                        v = temp->vertex;
                    }
                    temp = temp->next;
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, u, v, min);
            mincost += min;
            visited[v] = 1; // Mark the vertex as visited
        }
    }

    printf("\n\nMinimum cost: %d\n", mincost);
}

int main() {
    int edges, u, v, weight;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adjList[i] = NULL;
    }

    printf("\nEnter the edges (u, v, weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
        addEdge(v, u, weight); // Since the graph is undirected
    }

    prim(); // Call Prim's algorithm
    return 0;
}

