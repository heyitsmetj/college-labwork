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
    node *temp = (node *)malloc(sizeof(node));

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
            last = list;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
        printf("\n Do you want to add more nodes? (Y/N): ");
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
        printf(" %d->", ptr->data);
    }
    printf("NULL\n");
}

void swap()
{
    int m, n;

    display();

    printf("\n Enter the 1st element to swap: ");
    scanf("%d", &m);

    printf("\n Enter the 2nd element to swap: ");
    scanf("%d", &n);

    if (m == n)
    {
        printf("\n Both elements are same, swap operation not performed.");
        return;
    }

    node *ptr1, *ptr2;

    for (ptr1 = list; ptr1 != NULL && m != ptr1->data; ptr1 = ptr1->next)
        ;
    for (ptr2 = list; ptr2 != NULL && n != ptr2->data; ptr2 = ptr2->next)
        ;

    if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("\n Element not found in the list.");
        return;
    }

    if (m == ptr1->data && n == ptr2->data)
    {
        int temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
        printf("\n Swapped elements are: %d and %d", ptr1->data, ptr2->data);
        display();
    }
}

void main()
{
    int ch;

    while (1)
    {
        printf("\n\n 1. Create a Linked List");
        printf("\n 2. Display Linked List");
        printf("\n 3. Swap two elements.");
        printf("\n 4. Exit");

        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            list = create(list);
            break;

        case 2:
            display();
            break;

        case 3:
            swap();
            break;

        case 4:
            exit(1);
        }
    }
}
