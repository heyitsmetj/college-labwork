#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE *prev;
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *list = NULL, *last;

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d", &temp->data);

	temp->prev = temp;
	temp->next = temp;

	return temp;
}

node *create(node *list)
{
	char ch;
	node *temp, *last, *previous;

	do
	{
		temp = getnode();

		if (list == NULL)
		{
			list = temp;
		}
		else
		{
			for (last = list, previous = list; last->next != list; previous = last, last = last->next)
				;
			last->prev = previous;
			last->next = temp;
			temp->next = list;
			list->prev = temp;
		}

		printf("\n Do you want to enter more nodes?(Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	return (list);
}

void display()
{
	node *ptr;

	printf("\n\n Doubly Linked List: ");
	
	for (ptr = list; ptr->next != list; ptr = ptr->next)
	{
		printf("<-%d->", ptr->data);
	}
	printf("<-%d->", ptr->data);
}

void main()
{
	int ch;

	while (1)
	{
		printf("\n --Menu--\n");
		printf("\n 1.Create Circular Doubly Linked List.");
		printf("\n 2.Display the Circular Doubly Linked List.");
		printf("\n 3.Exit.");

		printf("\n\n Enter Choice: ");
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
			printf("\n Exiting...");
			exit(1);

		default:
			printf("\n\n Try Again!");
			break;
		}
	}
}