#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *list = NULL,*last;

void main()
{
    int i, num, count = 0, arr[10];

    printf("\n Enter number: ");
    scanf("%d", &num);

    printf("\n Entered number is: %d", num);

    while (num != 0)
    {
        int digit = num % 10;
        arr[count++] = digit;
        num = num / 10;
    }

    printf("\n Linked List: ");

    for (i = count - 1; i >= 0; i--)
    {
        node *temp;
        temp = (node *) malloc(sizeof(node));
        temp->data = arr[i];
        temp->next = NULL;

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
        printf("%d->", temp->data);
    }
    printf("NULL");

}