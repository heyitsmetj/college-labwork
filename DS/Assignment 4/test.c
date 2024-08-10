#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE
{
	int coeff;
	int expo;
	struct NODE *next;
};

typedef struct NODE node;
node *list = NULL, *last;

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the coefficient for new node: ");
	scanf("%d", &temp->coeff);
	printf("\n Enter the exponent for new node: ");
	scanf("%d", &temp->expo);

	temp->next = NULL;

	return temp;
}

node * create(node *list)
{
	int i, n;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (i = rand()%(10); i < n; i++)
    {
        node *temp = getnode();

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
    }
}


void main()
{
	srand(time(0));
	printf("\n Creating Random Linked List:\n");
	list = create(list);

	printf("\n\n Your Random Linked: ");
	display(list);
}