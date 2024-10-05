#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *list = NULL, *olist = NULL, *elist = NULL, *last;

node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));

    printf("\n Enter data for new node: ");
    scanf("%d", &temp->data);

    temp->next = NULL;

    return temp;
}

node *create(node *list)
{
    node *temp;
    char ch;

    do
    {
        temp = getnode();

        if (list == NULL)
        {
            list = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }

        printf("\n Do you want to enter more nodes?(Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return list;
}

void display(node *dlist)
{
    node *ptr;

    for (ptr = dlist; ptr != NULL; ptr = ptr->next)
    {
        printf("%d->", ptr->data);
    }
    printf("NULL\n");
}

void getnodedigit(node *list)
{
    node *ptr;

    for (ptr = list; ptr != NULL; ptr = ptr->next)
    {

        if (ptr->data % 2 == 0)
        {
            node *temp;
            temp = (node *)malloc(sizeof(node));
            temp->data = ptr->data;
            temp->next = NULL;

            if (elist == NULL)
            {
                elist = temp;
            }
            else
            {
                for (last = elist; last->next != NULL; last = last->next)
                    ;
                last->next = temp;
            }
        }
        else
        {
            node *temp;
            temp = (node *)malloc(sizeof(node));
            temp->data = ptr->data;
            temp->next = NULL;

            if (olist == NULL)
            {
                olist = temp;
            }
            else
            {
                for (last = olist; last->next != NULL; last = last->next)
                    ;
                last->next = temp;
            }
        }
    }
}

void main()
{
    printf("\n Creating Singly Linked List:\n ");
    list = create(list);

    printf("\n Linked List: ");
    display(list);

    printf("\n Separating Odd and Even Elements:\n ");
    getnodedigit(list);

    
    printf("\n Even Elements Linked List: ");
    display(elist);

    printf("\n Odd Elements Linked List: ");
    display(olist);
}