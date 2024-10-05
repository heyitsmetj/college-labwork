#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *list[10];
int nov,a[100][100];

node *getnodenum(int vno)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = vno;
    temp->next=NULL;
    return temp;
}

void display(node * list[])
{
    int i;
    node *ptr;
    for(i=0; i<nov; i++)
    {
        printf("V%d: ",i+1);
        ptr=list[i];
        for(ptr = list[i];ptr != NULL;ptr = ptr->next)
            printf("%d->",ptr->data);
            printf("NULL\n");
    }
}

void createadjacencylist()
{
    int i,j;
    char ch;
    node *temp,*last;
    for(i=0; i<nov; i++)
    list[i] = NULL;
    
    for ( i = 0; i < nov; i++)
    {
        for(j = 0;j < nov;j++)
        {
            printf("\n Is there an edge between v[%d] & v[%d]?(Y/N): ",i+1,j+1);
            scanf(" %c",&ch);
            if(ch == 'Y' || ch == 'y')
            {
                temp = getnodenum(j+1);
                if(list[i] == NULL)
                    list[i] = temp;
                else
                {
                    for(last = list[i];last->next != NULL;last = last->next);
                    last->next = temp;
                }
            }
        }   
    }
}

void degree()
{
    int i, indegree, outdegree;

    printf("\nVertex\tIndegree\tOutdegree\n");

    for(i=0; i<nov; i++)
    {
        indegree = outdegree = 0;

        for(int j=0; j<nov; j++)
        {
                if(a[i][j] == 1)
                    indegree++;
                if(a[j][i] == 1)
                    outdegree++;
        }

        printf("%d\t%d\t\t%d\n", i+1, outdegree, indegree);
    }
}
void createadjacencymatrix()
{
    int i,j;
    printf("\nEnter the adjacency matrix:\n");
    for(i=0; i<nov; i++)
        for(j=0; j<nov; j++)
        {
            printf("Is there an edge between v[%d] & v[%d]?(1/0):",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    printf("\nAdjacency Matrix:\n");
    for(i=0; i<nov; i++)
    {
        for(j=0; j<nov; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void main()
{
    int i;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&nov);
    
    createadjacencymatrix();
    degree();
}