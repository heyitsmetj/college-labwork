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

void display(node *list)
{
	node *ptr;

	printf("\n\n Doubly Linked List: ");

	for (ptr = list; ptr->next != list; ptr = ptr->next)
	{
		printf("<-%d->", ptr->data);
	}
	printf("<-%d->", ptr->data);
}

void delete()
{
	if (list == NULL)
	{
		printf("The list is empty.\n");
		return;
	}

	int val;
	node *ptr = list, *previous = NULL;

	display(list);

	printf("\n\n Enter the value of node to delete: ");
	scanf("%d", &val);

	do
	{
		if (ptr->data == val)
		{
			if (ptr->next == ptr)
			{
				free(ptr);
				list = NULL;
			}
			else
			{
				if (ptr == list)
				{
					list = ptr->next;
				}
				if (ptr->next != NULL)
				{
					ptr->next->prev = ptr->prev;
				}
				if (ptr->prev != NULL)
				{
					ptr->prev->next = ptr->next;
				}
				free(ptr);
			}
			printf("\n\n Node %d deleted successfully!\n", val);
			display(list);
			return;
		}
		previous = ptr;
		ptr = ptr->next;
	} while (ptr != list);

	printf("Node not found!\n");
}

void append(node *list)
{
	node *temp, *last;

    temp = getnode();

    if (list == NULL)
    {
        list = temp;
        list->prev = list;
        list->next = list;
    }
    else
    {
        for (last = list; last->next != list; last = last->next)
            ;
        last->next = temp;
        temp->prev = last;
        temp->next = list;
        list->prev = temp;
    }

    printf("\n Node appended successfully!\n");
	display(list);
}

void main()
{
	int ch;

	while (1)
	{
		printf("\n\n --Menu--\n");
		printf("\n 1.Create Circular Doubly Linked List.");
		printf("\n 2.Display the Circular Doubly Linked List.");
		printf("\n 3.Delete a node by its value.");
		printf("\n 4.Append a node.");
		printf("\n 5.Exit.");

		printf("\n\n Enter Choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			list = create(list);
			break;

		case 2:
			display(list);
			break;

		case 3:
			delete ();
			break;

		case 4:
			append(list);
			break;

		case 5:
			printf("\n Exiting...");
			exit(1);

		default:
			printf("\n\n Try Again!");
			break;
		}
	}
}