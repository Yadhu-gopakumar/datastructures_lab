#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];       // Adjacency matrix
int transpose[MAX][MAX]; // Transposed adjacency matrix
int visited[MAX];        // Visited array
int stack[MAX];          // Stack for storing vertices
int top = -1;            // Stack pointer
int n;                   // Number of vertices

// Stack operations
void push(int vertex)
{
   stack[++top] = vertex;
}

int pop()
{
   return stack[top--];
}

// Depth First Search (DFS) for filling the stack
void dfsFillStack(int graph[MAX][MAX], int vertex)
{
   visited[vertex] = 1;
   for (int i = 0; i < n; i++)
   {
      if (graph[vertex][i] && !visited[i])
      {
         dfsFillStack(graph, i);
      }
   }
   // Push vertex to stack after exploring all neighbors
   push(vertex);
}

// Depth First Search (DFS) to find SCCs
void dfsPrintSCC(int graph[MAX][MAX], int vertex)
{
   printf("%d ", vertex); // Print the vertex in the current SCC
   visited[vertex] = 1;
   for (int i = 0; i < n; i++)
   {
      if (graph[vertex][i] && !visited[i])
      {
         dfsPrintSCC(graph, i);
      }
   }
}

// Transpose the graph
void transposeGraph()
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         transpose[i][j] = adj[j][i];
      }
   }
}

// Find Strongly Connected Components (SCCs)
void findSCCs()
{
   // Step 1: Perform DFS on the original graph and fill the stack
   for (int i = 0; i < n; i++)
   {
      visited[i] = 0; // Reset visited array
   }
   for (int i = 0; i < n; i++)
   {
      if (!visited[i])
         dfsFillStack(adj, i);
   }

   // Step 2: Transpose the graph
   transposeGraph();

   // Step 3: Perform DFS on the transposed graph using stack order
   for (int i = 0; i < n; i++)
      visited[i] = 0; // Reset visited array
   printf("Strongly Connected Components:\n");
   while (top != -1)
   {
      int vertex = pop();
      if (!visited[vertex])
      {
         dfsPrintSCC(transpose, vertex);
         printf("\n"); // Each SCC on a new line
      }
   }
}

int main()
{
   int edges, u, v;

   printf("Enter the number of vertices: ");
   scanf("%d", &n);

   // Initialize adjacency matrices
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         adj[i][j] = 0;
      }
   }

   printf("Enter the number of edges: ");
   scanf("%d", &edges);

   printf("Enter the edges (u v):\n");
   for (int i = 0; i < edges; i++)
   {
      scanf("%d %d", &u, &v);
      adj[u][v] = 1; // Directed edge
   }

   findSCCs();

   return 0;
}