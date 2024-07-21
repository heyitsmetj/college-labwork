#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *last, *list = NULL, *list2 = NULL;

node *getnode() // creates a node
{
	node *temp;

	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d", &temp->data);

	temp->next = NULL;

	return temp;
}

void create()
{
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

int countnode()
{
	node *ptr;
	int cnt;

	for (ptr = list, cnt = 0; ptr != NULL; ptr = ptr->next, cnt++)
		;

	return cnt;
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

	printf("\n Enter position to delete (starting from 1): ");
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
		printf("\n Position %d not found.\n", pos);
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

void reverse()
{
	node *temp = NULL, *prev = NULL, *current = list;

	while (current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	list = prev;

	printf("\n Linked List Reversed.\n");
	display();
}

node *create_another_list()
{
	char ch;
	node *temp, *list2 = NULL;

	printf("\n Creating another Linked List!\n");

	do
	{
		temp = getnode();

		if (list2 == NULL)
		{
			list2 = temp;
		}
		else
		{
			last->next = temp;
		}

		last = temp;

		printf("\n Do you want to enter more nodes? (Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	display();
	return list2;
}

void concatenate(node **list, node **list2)
{
	if (*list == NULL)
	{
		*list = *list2;
		return;
	}

	if (*list2 == NULL)
	{
		return;
	}

	node *ptr;

	for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
		;

	ptr->next = *list2;
	printf("\n\n List Concatenated.\n");
}

void main()
{
	int ch, cnt;

	while (1)
	{
		printf("\n\n 1.Create the Linked List.");
		printf("\n 2.Display the Linked List.");
		printf("\n 3.Count the nodes in the Linked List.");
		printf("\n 4.Delete a node from the Linked List.");
		printf("\n 5.Reverse the Linked List.");
		printf("\n 6.Concatenate another Linked List.");
		printf("\n 7.Exit the program.");
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
			cnt = countnode();
			printf("\n No. of nodes = %d\n", cnt);
			display();
			break;

		case 4:
			deletenode();
			break;

		case 5:
			reverse();
			break;

		case 6:
			list2 = create_another_list();
			concatenate(&list, &list2);
			display();
			break;

		case 7:
			exit(1);
		}
	}
}
