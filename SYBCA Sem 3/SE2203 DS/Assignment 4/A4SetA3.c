#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *last = NULL;

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

		if (last == NULL)
		{
			last = temp;
			last->next = last;
		}
		else
		{
			temp->next = last->next;
			last->next = temp;
			last = temp;
		}

		printf("\n Do you want to enter more nodes? (Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');
}

void display()
{
	node *ptr;

	printf("\n Linked List: ");

	ptr = last->next;
	do
	{
		printf("\t %d", ptr->data);
		ptr = ptr->next;

	} while (ptr != last->next);
}

void search()
{
	int key, flag = 0;
	node *ptr;

	display();

	printf("\n Enter the data to search: ");
	scanf("%d", &key);

	ptr = last->next;

	do
	{

		if (ptr->data == key)
		{
			printf("\n Data found in the Linked List.");
			flag = 1;
			break;
		}
		ptr = ptr->next;

	} while (ptr != last->next);

	if (flag == 0)
	{
		printf("\n Data NOT found in the Linked List!");
		display();
	}
}

void countnode()
{
	node *ptr;
	int cnt;

	ptr = last->next;
	cnt = 0;

	do
	{
		ptr = ptr->next;
		cnt++;

	} while (ptr != last->next);

	if (cnt == 0)
	{
		printf("\n Linked List is empty!");
	}
	else
	{
		display();
		printf("\n Number of nodes in the Linked List: %d", cnt);
	}
}

void main()
{
	int ch, cnt;

	while (1)
	{
		printf("\n\n 1.Create the Linked List.");
		printf("\n 2.Display the Linked List.");
		printf("\n 3.Search for a data in the Linked List.");
		printf("\n 4.Count the number of nodes in the Linked List.");
		printf("\n 5.Exit the program.");
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
			search();
			break;

		case 4:
			countnode();
			break;

		case 5:
			exit(1);
		}
	}
}
