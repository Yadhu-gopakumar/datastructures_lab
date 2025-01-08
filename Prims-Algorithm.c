#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // Replace 0 with a high cost for no edge
            }
        }
    }

    visited[0] = 1;  // Start with the first node
    printf("\nThe edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        min = 999;  // Initialize minimum to a high value

        // Find the minimum cost edge among the visited vertices
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (cost[i][j] < min && !visited[j]) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        // Include the edge in the MST
        printf("\nEdge %d: (%d, %d)\tcost: %d", ne++, a + 1, b + 1, min);
        mincost += min;
        visited[b] = 1;  // Mark the vertex as visited

        // Remove the edge from consideration
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMinimum cost: %d\n", mincost);
    return 0;
}
