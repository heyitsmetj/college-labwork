#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *list = NULL,*last;

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d", &temp->data);
	
	temp->next = NULL;

	return temp;
}

node *create(node *list)
{
	char ch;
	node *temp, *last;

	do
	{
		temp = getnode();

		if (list == NULL)
		{
			list = temp;
		}
		else
		{
			for (last = list; last->next != NULL; last = last->next)
			;
			last->next = temp;

		}

		printf("\n Do you want to enter more nodes?(Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	return (list);
}

void display(node *list)
{
	node *ptr;

	for (ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("%d->", ptr->data);
	}
	printf("NULL");
}

void reverse()
{
	node *temp = NULL, *prev = NULL, *ptr = list;

	while (ptr != NULL)
	{
		temp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = temp;
	}
	list = prev;

	printf("\n Linked List Reversed.\n");
}



void main()
{
	printf("\n Creating 1st List:\n");
	list = create(list);

	printf("\n 1st Linked list: ");
	display(list);
	
	reverse();

	printf("\n\n Reversed Linked list: ");
	display(list);
}