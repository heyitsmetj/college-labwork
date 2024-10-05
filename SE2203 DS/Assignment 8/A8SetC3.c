#include<stdio.h>
#include<stdlib.h>

int nov, a[100][100];

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

void checkUndirected()
{
    int i, j;
    int isUndirected = 1;

    for(i = 0; i < nov; i++)
    {
        for(j = 0; j < nov; j++)
        {
            if(a[i][j] != a[j][i])
            {
                isUndirected = 0;
                break;
            }
        }
        if(isUndirected == 0)
            break;
    }

    if(isUndirected)
        printf("\nThe graph is undirected.\n");
    else
        printf("\nThe graph is directed.\n");
}

void main()
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &nov);
    
    createadjacencymatrix();
    checkUndirected();
}
