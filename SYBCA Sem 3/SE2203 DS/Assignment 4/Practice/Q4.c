#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *list = NULL, *last;

node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));

    printf("\n Enter data for new node: ");
    scanf("%d", &temp->data);

    temp->next = NULL;

    return temp;
}

node * create(node *list)
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

void display()
{
    node *ptr;
    
    printf("\n Linked List: ");

    for (ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%d->", ptr->data);
    }
    printf("NULL\n");

    printf("\n Odd Elements Linked List: ");

    for (ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->data % 2 != 0)
        printf("%d->", ptr->data);
    }
    printf("NULL\n");
}

void main()
{
    printf("\n Creating Singly Linked List:\n ");
    list = create(list);
    display();
}