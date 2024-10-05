#include <stdio.h>
#include <stdlib.h>

int nov, a[100][100], visited[100];

void createadjacencymatrix()
{
    int i, j;
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
        {
            printf("Is there an edge between v[%d] & v[%d]?(1/0): ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

// BFS Function
void BFS(int v)
{
    int queue[100], front = 0, rear = 0;
    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v + 1);

        for (int i = 0; i < nov; i++)
        {
            if (a[v][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void resetVisited()
{
    for (int i = 0; i < nov; i++)
        visited[i] = 0;
}

void main()
{
    int startVertex;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &nov);

    createadjacencymatrix();

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    startVertex -= 1; // Adjusting for 0-based indexing
    printf("\nBFS Traversal: ");
    resetVisited();
    BFS(startVertex);
}
