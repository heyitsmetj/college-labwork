#include<stdio.h>
#include<stdlib.h>

int nov, a[100][100], visited[100];

void createadjacencymatrix()
{
    int i, j;
    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < nov; i++)
    { 
        for(j = 0; j < nov; j++)
        {
            printf("Is there an edge between v[%d] & v[%d]?(1/0): ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < nov; i++)
    {
        for(j = 0; j < nov; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

// DFS using stack
void DFS(int v)
{
    int stack[100], top = -1;

    stack[++top] = v;
    visited[v] = 1;

    while(top >= 0)
    {
        int current = stack[top--];
        printf("%d ", current + 1);

        for(int i = nov - 1; i >= 0; i--)  // Push adjacent vertices in reverse order to simulate recursion behavior
        {
            if(a[current][i] == 1 && !visited[i])
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

void resetVisited()
{
    for(int i = 0; i < nov; i++)
        visited[i] = 0;
}

void main()
{
    int startVertex;
    
    printf("\nEnter the number of vertices: ");
    scanf("%d", &nov);
    
    createadjacencymatrix();
    
    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    startVertex -= 1;  // Adjusting for 0-based indexing
    printf("\nDFS Traversal: ");
    resetVisited();
    DFS(startVertex);
}
