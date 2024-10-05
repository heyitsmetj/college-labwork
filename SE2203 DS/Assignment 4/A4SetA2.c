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

	printf("\n Enter the data for the new node: ");
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

void deletenode()
{
	int pos, i;
	node *curr, *prev = NULL;

	if (list == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	display();

	printf("\n\n Enter position to delete (starting from 1): ");
	scanf("%d", &pos);

	if (pos < 1)
	{
		printf("Invalid position.\n");
		return;
	}

	for (curr = list, i = 1; curr != NULL && i < pos; prev = curr, curr = curr->next, i++)
		;

	if (curr == NULL)
	{
		printf("Position %d not found.\n", pos);
		return;
	}

	if (prev == NULL)
	{
		list = curr->next;
	}
	else
	{
		prev->next = curr->next;
	}

	if (curr == last)
	{
		last = prev;
	}

	free(curr);
	printf("\n Node at position %d deleted.\n", pos);
	display();
}

void insertbypos()
{
	node *ptr;
	int pos, i;
	node *temp = getnode();

	display();

	printf("Enter position to insert (starting from 1): ");
	scanf("%d", &pos);

	if (pos < 1)
	{
		printf("Invalid position.\n");
		return;
	}

	for (ptr = list, i = 1; ptr != NULL && i < pos - 1; ptr = ptr->next, i++)
		;

	if (ptr == NULL)
	{
		printf("Position %d not found.\n", pos);
		return;
	}
	else
	{
		temp->next = ptr->next;
		ptr->next = temp;
	}

	printf("Node at position %d added.\n", pos);
	display();
}

void main()
{
	int ch, cnt;

	while (1)
	{
		printf("\n\n 1.Create the Linked List.");
		printf("\n 2.Display the Linked List.");
		printf("\n 3.Delete a node by position.");
		printf("\n 4.Insert a node by position. ");
		printf("\n 5.Exit the program.");
		printf("\n\n Enter choice: ");
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
			deletenode();
			break;

		case 4:
			insertbypos();
			break;

		case 5:
			exit(1);

		}
	}
}
