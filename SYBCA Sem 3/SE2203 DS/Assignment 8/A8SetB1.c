#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *list[10];
int nov, a[100][100];

node *getnodenum(int vno)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = vno;
    temp->next = NULL;
    return temp;
}

void display(node *list[])
{
    int i;
    node *ptr;
    printf("\n Adjacency List:\n");
    for(i = 0; i < nov; i++)
    {
        printf("V%d: ", i + 1);
        ptr = list[i];
        while(ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

void createadjacencymatrix()
{
    int i, j;
    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < nov; i++)
    {
        for(j = 0; j < nov; j++)
        {
            printf("Is there an edge between v[%d] & v[%d]?(1/0): ", i + 1, j + 1);
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

void convertMatrixToList()
{
    int i, j;
    node *temp, *last;

    for(i = 0; i < nov; i++)
        list[i] = NULL;

    for(i = 0; i < nov; i++)
    {
        for(j = 0; j < nov; j++)
        {
            if(a[i][j] == 1)
            {
                temp = getnodenum(j + 1);
                if(list[i] == NULL)
                    list[i] = temp;
                else
                {
                    last = list[i];
                    while(last->next != NULL)
                        last = last->next;
                    last->next = temp;
                }
            }
        }
    }
}

void main()
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &nov);
    
    createadjacencymatrix();
    convertMatrixToList();
    display(list);
}
