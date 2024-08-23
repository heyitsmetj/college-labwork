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
			for (last = list; last->next != NULL; last = last->next)
				;
			last->next = temp;
		}

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
	printf("NULL \n");
}

int countnode()
{
	node *ptr;
	int cnt;

	for (ptr = list, cnt = 0; ptr != NULL; ptr = ptr->next, cnt++)
		;

	return cnt;
}

void deletepos()
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

void insertbypos()
{
	node *ptr;
	int pos, i;
	node *temp = getnode();

	display();

	printf("\n Enter position to insert (starting from 1): ");
	scanf("%d", &pos);

	if (pos < 1)
	{
		printf("\n Invalid position.\n");
		return;
	}

	if(pos == 1)
	{
		temp->next = list;
        list = temp;
	}

	for (ptr = list, i = 1; ptr != NULL && i < pos - 1; ptr = ptr->next, i++)
		;

	if (ptr == NULL)
	{
		printf("\n Position %d not found.\n", pos);
		return;
	}
	else
	{
		temp->next = ptr->next;
		ptr->next = temp;
	}

	printf("\n Node at position %d added.\n", pos);
	display();
}

void insertval()
{
	int val;
	node *temp, *ptr, *previous = NULL;

	printf("\n Creating a new node!\n\n");

	temp = getnode();

	display();
	printf("\n Enter the value of node after which new node is to be placed: ");
	scanf("%d", &val);

	for (ptr = list, previous = list; ptr != NULL && val != ptr->data; previous = ptr, ptr = ptr->next)
		;

	if (ptr == list && previous == list)
	{
		temp->next = ptr->next;
		list = temp;
	}

	if (ptr != NULL && val == ptr->data)
	{
		temp->next = ptr->next;
		ptr->next = temp;
	}
	else
	{
		printf("\n Value not Found!\n");
		return;
	}

	printf("\n New node inserted!\n");
	display();
}

void deleteval()
{
	int val;
	node *temp, *ptr, *previous;

	display();
	printf("\n Enter the value of node to be deleted: ");
	scanf("%d", &val);

	for (ptr = list, previous = list; ptr != NULL && val != ptr->data; previous = ptr, ptr = ptr->next)
		;

	if (val == ptr->data)
	{
		if (ptr == list && previous == list)
			list = ptr->next;

		else
		{
			previous->next = ptr->next;
		}
		printf("\n Node Deleted!\n");
		free(ptr);
	}
	else
	{
		printf("\n Value not Found!");
	}

	display();
}

void main()
{
	int ch, cnt;

	while (1)
	{
		printf("\n\n 1.Create the Linked List.");
		printf("\n 2.Display the Linked List.");
		printf("\n 3.Count the nodes in the Linked List.");
		printf("\n 4.Delete a node by Position.");
		printf("\n 5.Delete a node by Value.");
		printf("\n 6.Reverse the Linked List.");
		printf("\n 7.Concatenate another Linked List.");
		printf("\n 8.Insert a node by Position.");
		printf("\n 9.Insert a node by Value.");
		printf("\n 10.Exit the program.");
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
			deletepos();
			break;

		case 5:
			deleteval();
			break;

		case 6:
			reverse();
			break;

		case 7:
			list2 = create_another_list();
			concatenate(&list, &list2);
			display();
			break;

		case 8:
			insertbypos();
			break;

		case 9:
			insertval();
			break;

		case 10:
			exit(1);
		}
	}
}
