#include <stdio.h>

#define MAX 20

int adjMatrix[MAX][MAX], visited[MAX], inDegree[MAX], n;

// Function to read the adjacency matrix for the graph
void readGraph() {
    int i, j;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// BFS Function for Tree Traversal
void bfs(int startVertex) {
    int queue[MAX], front = 0, rear = -1, i;

    if (startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex.\n");
        return;
    }

    // Reset visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int current = queue[front++];

        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Function for Tree Traversal
void dfs(int startVertex) {
    int stack[MAX], top = -1, i;

    if (startVertex < 0 || startVertex >= n) {
        printf("Invalid starting vertex.\n");
        return;
    }

    // Reset visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal starting from vertex %d: ", startVertex);

    stack[++top] = startVertex;

   while (top >= 0) {
        int current = stack[top--];

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            // Push adjacent vertices to the stack in reverse order
            for (i = n - 1; i >= 0; i--) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

// Topological Sort (for Directed Acyclic Graph)
void topologicalSort() {
    int stack[MAX], top = -1, count = 0;

    // Calculate in-degrees
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    // Push nodes with 0 in-degree onto stack
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            stack[++top] = i;
        }
    }

    printf("\nTopological Sort: ");
    while (top >= 0) {
        int current = stack[top--];
        printf("%d ", current);
        count++;

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("\nThe graph has a cycle; topological sort is not possible.");
    }
    printf("\n");
}

int main() {
    int i, choice, startVertex;

    do {
        // Menu-driven program
        printf("\n1. Read Graph\n2. BFS\n3. DFS\n4. Topological Sort\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter the starting vertex (0 to %d) for BFS: ", n - 1);
                scanf("%d", &startVertex);
                bfs(startVertex);
                break;
            case 3:
                printf("Enter the starting vertex (0 to %d) for DFS: ", n - 1);
                scanf("%d", &startVertex);
                dfs(startVertex);
                break;
            case 4:
                topologicalSort();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
