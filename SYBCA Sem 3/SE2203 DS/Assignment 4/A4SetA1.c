#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *last, *list = NULL;

node *getnode() // creates a node
{
	node *temp;

	temp = (node *)malloc(sizeof(node)); 

	printf("\n Enter the data: ");
	scanf("%d", &temp->data);

	temp->next = NULL;

	return temp;
}

void create()
{
	int i;
	char ch;
	node *temp;

	do
	{
		temp = getnode();

		if (list == NULL)
		{
			list = temp;
		}
		else
		{
			last->next = temp;
		}

		last = temp;

		printf("\n Do you want to enter more nodes? (Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');
}

void display()
{
	node *ptr;

	printf("\n Linked List: ");

	for (ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("\t %d", ptr->data);
	}
}


void main()
{
	int ch, cnt;

	while (1)
	{
		printf("\n\n 1.Create the Linked List.");
		printf("\n 2.Display the Linked List.");
		printf("\n 3.Exit the program.");
		printf("\n Enter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			create();
			break;

		case 2:
			display();
			break;

		case 3:
			exit(1);
		}
	}
}
