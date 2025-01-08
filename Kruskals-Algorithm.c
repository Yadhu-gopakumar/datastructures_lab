#include <stdio.h>
#include <stdlib.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[99][99], parent[99];

// Function to find the parent of a vertex
int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

// Function to union two sets
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (enter 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Mark no edge with a high cost
            }
        }
    }

    // Initialize parent array to 0
    for (i = 0; i < n; i++) {
        parent[i] = 0;
    }

    printf("The edges of the Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        // Find the minimum cost edge
        min = 999;
        for (i = 0; i < n; i++) { // Fixed indexing
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the parents of the vertices
        u = find(u);
        v = find(v);

        // If they belong to different sets, include the edge
        if (uni(u, v)) {
            printf("%d edge (%d,%d)\tcost: %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
        }

        // Mark the edge as used
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
